#########################################################################
# File Name: demo_2.sh
# Author: fxm
# mail: fangxiaoming01@baidu.com
# Created Time: 2018年07月17日 星期二 11时41分07秒
#########################################################################
#!/bin/bash

#read name
#echo "$name It is a test"

for loop in 1 2 3 4 5
do
    echo "this is a $loop"
done

int=1
while(($int <= 5))
do
    echo $int
    let "int++"
done
