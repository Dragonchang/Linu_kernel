#define _GNU_SOURCE
#include <sys/wait.h>
#include <sys/utsname.h>
#include <sched.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define errExit(msg)    do { perror(msg); exit(EXIT_FAILURE); \
                       } while (0)

int test;
static int              /* Start function for cloned child */
childFunc(void *arg)
{
   printf("child test be= %d\n", test);
   test = 2222;
   printf("child test be= %d\n", test);
   sleep(200);

   return 0;           /* Child terminates now */
}

#define STACK_SIZE (1024 * 1024)    /* Stack size for cloned child */

int
main(int argc, char *argv[])
{
   test = 1111;
   char *stack;                    /* Start of stack buffer */
   char *stackTop;                 /* End of stack buffer */
   pid_t pid;

   /* Allocate stack for child */

   stack = malloc(STACK_SIZE);
   if (stack == NULL)
       errExit("malloc");
   stackTop = stack + STACK_SIZE;  /* Assume stack grows downward */

   pid = clone(childFunc, stackTop, SIGCHLD | CLONE_VM, NULL);
   if (pid == -1)
       errExit("clone");
   printf("clone() returned %ld\n", (long) pid);
   printf("parent test be= %d\n", test);
   /* Parent falls through to here */

   sleep(1); 
   printf("parent test af= %d\n", test);

   if (waitpid(pid, NULL, 0) == -1)    /* Wait for child */
       errExit("waitpid");
   printf("child has terminated\n");
   exit(EXIT_SUCCESS);
}
