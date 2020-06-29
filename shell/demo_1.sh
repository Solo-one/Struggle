#########################################################################
# File Name: demo_1.sh
# Author: fxm
# mail: fangxiaoming01@baidu.com
# Created Time: 2018年07月17日 星期二 11时21分52秒
#########################################################################
#!/bin/bash

var=`expr 2 + 2` #注意空格
echo "两个数之和：$var" 

a=10
b=20

echo `expr $a \* $b`
echo `expr $b / $a`

echo `expr [$a != $b]`
