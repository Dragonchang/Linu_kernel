#!/bin/sh
#定义变量
LINUX=$(find linux* -maxdepth 0)
BUSYBOX=/usr/local/kvm/bin/qemu-system-x86_64
#启动qemu
/usr/local/kvm/bin/qemu-system-x86_64 -kernel linux-3.4.1/arch/x86_64/boot/bzImage -initrd rootfs.img.gz -append "root=/dev/ram rdinit=sbin/init noapic"
