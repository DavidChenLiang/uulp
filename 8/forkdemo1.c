#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int
main(void)
{
    int ret_from_fork,mypid;
    mypid = getpid();
    printf("Before: my pid is %d\n",mypid);
    ret_from_fork = fork();
    sleep(1);
    printf("After: my pid is %d, fork() said %d\n",getpid(),ret_from_fork);
    return EXIT_SUCCESS;
}
