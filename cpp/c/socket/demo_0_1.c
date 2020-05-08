// Copyright (c) 2020 Baidu.com, Inc. All Rights Reserved
// File Name: demo_0_1.c
// Author: fangxiaoming01@baidu.com 
// Created Time: Thu 07 May 2020 11:21:51 AM CST

#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

#define MAXLINE 128

int main() {

    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;

    server_addr.sin_family = AF_INET;
    //使用默认的ip和port
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(1234);

    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    //sleep(2000);

    // 绑定指定ip和端口
    if (0 != bind(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr))) {
        return -1;
    }

    char ip[MAXLINE] = {0};
    printf("start server at %s:%d\n", inet_ntop(AF_INET,&server_addr.sin_addr,ip,MAXLINE),ntohs(server_addr.sin_port));

    // 监听
    listen(socket_fd, 4); // 表示连接队列长度

    socklen_t clilen = sizeof(client_addr);
    int conn_fd = accept(socket_fd, (struct sockaddr *)&client_addr, &clilen);
    if (conn_fd == -1) {
        printf("accept failed\n"); 
        return -1;
    }

    printf("connect from %s %d\n", inet_ntop(AF_INET,&client_addr.sin_addr,ip,MAXLINE),ntohs(client_addr.sin_port));

    char recvMsg[MAXLINE] = {0};
    if(0 != read(conn_fd, recvMsg, MAXLINE)) {
        printf("recv msg:%s\n", recvMsg);
        // 返回给客户端数据
        write(conn_fd, recvMsg, MAXLINE);
    }

    
    // close
    close(conn_fd);
    close(socket_fd);
    printf("exit\n");

    return 0;
}
