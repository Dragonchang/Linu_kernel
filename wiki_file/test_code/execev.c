#include <sys/wait.h>
#include <sys/utsname.h>
#include <sched.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int argc, char * argv[])
{
    int pid;
    /* fork another process */
    pid = fork();
    if (pid<0) 
    { 
        /* error occurred */
        printf("Fork Failed!\n");
        exit(-1);
    } 
    else if (pid==0) 
    {
        /*   child process   */
        execlp("/bin/ls","ls",NULL);
        //child process never run to here
        printf("after /bin/ls pid =  %d\n",pid);
    } 
    else 
    {  
        /*     parent process  */
        /* parent will wait for the child to complete*/
        wait(NULL);
        printf("Child Complete!\n");
        exit(0);
    }
}
