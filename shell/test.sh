#########################################################################
# File Name: test.sh
# Author: fxm
# mail: fangxiaoming01@baidu.com
# Created Time: 2018年07月16日 星期一 17时36分54秒
#########################################################################
#!/bin/bash

echo $0 $1 $2
echo $1
start_path=$(pwd)
echo ${start_path}

echo $# $$ $?

name="fangxiaoming"
#readonly name #只读变量
echo $name
name="xiaoming"
echo ${name}

greeting="hello , ${name} !"
echo $greeting
echo ${#greeting}
echo ${greeting:2:4}

string="runoob is a great company"
echo `expr index "$string" is`

:<<EOF
my_array=(123 "sss" 456 'fxm' xiaoming)
echo $my_array
echo ${my_array[1]}
echo ${my_array[4]}
echo ${#my_array[@]}
echo ${#my_array[4]}
EOF

:<<'
注释内容..
'

echo $1


