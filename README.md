# gcc的一些命令:
# 1.生成s 汇编文件  
   gcc -S exec.c  -o libshare.s  
# 2.生成obj 可重定位文件  
  gcc -c exec.c  -o libshare.o  
# 3.生成可执行程序文件
  gcc  exec.c  -o libshare  -m32  
  gcc  exec.c  -o libshare -static -m32  
# 4.生成共享object文件主要是so库
  gcc -shared dynaLib.c -o libdynaLib.so -m32
