#include <sys/wait.h>
#include <sys/utsname.h>
#include <sched.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
void setRTSched(int priority) {
    printf ("Policy %d\n", sched_getscheduler(0));  
    printf("max priority: %d\n", sched_get_priority_max(0)); /* 99 for real-time process 0 non-real-time process */  
    struct sched_param param;  
    int maxRR;  
    maxRR = sched_get_priority_max(SCHED_RR);  
   printf("maxRR =%d \n", maxRR);
    if(maxRR == -1){  
        perror("sched_get_priority_max() error!\n");  
        exit(1);  
    }  
    param.sched_priority = priority;  
    if(sched_setscheduler(getpid(), SCHED_RR, &param) == -1){  
        perror("sched_setscheduler() error!\n");  
        exit(1);  
    }  
}

void setFIFOSched(int priority) {
    printf ("Policy %d\n", sched_getscheduler(0));  
    printf("max priority: %d\n", sched_get_priority_max(0)); /* 99 for real-time process 0 non-real-time process */  
    struct sched_param param;  
    int maxFIFO;  
    maxFIFO = sched_get_priority_max(SCHED_FIFO);   
   printf("maxFIFO =%d \n", maxFIFO);
    if(maxFIFO == -1){  
        perror("sched_get_priority_max() error!\n");  
        exit(1);  
    }  
    param.sched_priority = priority;  
    if(sched_setscheduler(getpid(), SCHED_FIFO, &param) == -1){  
        perror("sched_setscheduler() error!\n");  
        exit(1);  
    }  
}

void setBATCHSched(int priority) {
    printf ("Policy %d\n", sched_getscheduler(0));  
    printf("max priority: %d\n", sched_get_priority_max(0)); /* 99 for real-time process 0 non-real-time process */  
    struct sched_param param;  
    int max;  
    max = sched_get_priority_max(0);   
   printf("max=%d \n", max);
    if(max == -1){  
        perror("sched_get_priority_max() error!\n");  
        exit(1);  
    }  
    param.sched_priority = max;  
    if(sched_setscheduler(getpid(), 0, &param) == -1){  
        perror("sched_setscheduler() error!\n");  
        exit(1);  
    }  
}


int
main(int argc, char *argv[])
{
sleep(2);
float time_use=0;
struct timeval start;
struct timeval end;




//setFIFOSched(99);
setBATCHSched(120);
gettimeofday(&start,NULL);
printf("start.tv_sec:%d\n",start.tv_sec);
printf("start.tv_usec:%d\n",start.tv_usec);
int i;
for(i= 0; i<10000000;i++) {
 int a = i;
}
gettimeofday(&end,NULL);
printf("end.tv_sec:%d\n",end.tv_sec);
printf("end.tv_usec:%d\n",end.tv_usec);
time_use=(end.tv_sec-start.tv_sec)*1000000+(end.tv_usec-start.tv_usec);//微秒
printf("time_use is %f\n",time_use);
return 0;

}




