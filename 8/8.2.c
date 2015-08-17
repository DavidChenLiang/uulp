/*
 * =====================================================================================
 *
 *       Filename:  8.2.c
 *
 *    Description:  test
 *
 *        Version:  1.0
 *        Created:  2015年07月30日 21时41分32秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Chen Liang (), 
 *   Organization:  
 *
 * =====================================================================================
 */


#include	<stdlib.h>
#include <stdio.h>

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
        int
main ( int argc, char *argv[] )
{
        int n;
        for (n=0;n<10;n++){
                fprintf(stdout,"my pid = %d,n = %d\n",getpid(),n);
                sleep(1);
                if (fork()!=0)
                        exit(0);
        }
        return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
