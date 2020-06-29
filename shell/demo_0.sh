#########################################################################
# File Name: demo.sh
# Author: fxm
# mail: fangxiaoming01@baidu.com
# Created Time: 2018年07月16日 星期一 18时17分34秒
#########################################################################
#!/bin/bash

# 测试 $* 和 $@ 的区别
echo "--- \$* 演示 ---"
for i in '$*'; do
    echo $i
done

echo "--- \$@ 演示 ---"
for i in '$@'; do
    echo $i
done
