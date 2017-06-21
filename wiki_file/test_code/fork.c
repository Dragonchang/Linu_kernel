#include<unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int glob = 0;
int main(int argc, char *argv)
{
    pid_t pid;
    int status;
    if ((pid = fork())<0)
    {
        printf("fork the child failed!\n");
        exit(0);
    } else if (pid == 0)
    {
        
        ++glob;
        //sleep(5);
        printf("this is child process pid:%d pid =%d glob =%d\n",getpid(), pid, glob);
        //exit(0);
        
    } else 
    {  
       //返回给父进程的pid为子进程的pid号
      //sleep(3);
       printf("waite begin pid:%d pid:%d\n",getpid(),pid);
      // if(wait(&status) != pid)
         // printf("waite error\n");
       if (waitpid(pid, &status, WNOHANG) != pid) {
           printf("waite error\n");
       }
       printf("waite end pid:%d status = %d\n",getpid(), status);
       sleep(10);
        printf("this is parent process pid :%d glob =%d\n",getpid(), glob);
    }
    printf("exit pid:%d pid_t =%d\n",getpid(),pid);
    return 0;
}



 
