#!/bin/sh
#定义变量
KERNEL=$(pwd)
BUSYBOX=$(find busybox* -maxdepth 0)
LINUX=$(find linux* -maxdepth 0)
#通过cpio创建镜像
cd $BUSYBOX/_install
find . | cpio -o --format=newc > $KERNEL/rootfs.img
cd $KERNEL
#通过gzip创建zip镜像
gzip -c rootfs.img > rootfs.img.gz
