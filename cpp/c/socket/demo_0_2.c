// Copyright (c) 2020 Baidu.com, Inc. All Rights Reserved
// File Name: demo_0_1.c
// Author: fangxiaoming01@baidu.com 
// Created Time: Thu 07 May 2020 11:21:51 AM CST

#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define MAXLINE 128

int main() {

    struct sockaddr_in server_addr;

    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);
    server_addr.sin_port = htons(1234);

    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);

    // 连接服务器，如果非0，则连接失败
    if (0 != connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr))) {
        return -1;
    }

    char sendMsg[MAXLINE] = "hello world!";
    char recvMsg[MAXLINE] = {0};
    write(socket_fd, sendMsg, strlen(sendMsg));

    if(0 != read(socket_fd, recvMsg, MAXLINE)) {
        printf("recvMsg:%s\n", recvMsg);
    }

    // close
    close(socket_fd);
    printf("exit\n");

    return 0;
}
