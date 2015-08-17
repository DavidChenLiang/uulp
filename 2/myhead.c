/*
 * =====================================================================================
 *
 *       Filename:  myhead.c
 *
 *    Description:  head
 *
 *        Version:  1.0
 *        Created:  2015年07月10日 15时03分53秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Chen Liang (), 
 *   Organization:  
 *
 * =====================================================================================
 */


#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
        int
main ( int argc, char *argv[] )
{
        int opt;
        int displayCounter = 10;                /* default print 10 lines of file */
        while ((opt = getopt(argc,argv,"n:")) != -1){ /* scan all the options until met a argumnt */
                switch(opt){
                        case('n'):
                                displayCounter = atoi(optarg);
                                break;
                }
        }
//        printf("argc =%d\n",argc);
//        printf("optind =%d\n",optind);
//        printf("argvNumber =%d\n",argc - optind);
//        printf("=================\n");
        for (;optind < argc; optind++){
            int counterIndex = displayCounter;
            int fd;
            if ((fd = open(argv[optind],O_RDONLY)) == -1){
                perror("Can not open file");
            }
            char buf[256];                          /* buffer for a line */
            int bufOffset =0;                       /* buffer offset counter */
            while (counterIndex-- > 0){
                while (read(fd,buf+bufOffset,1) > 0){/* return less or equals to 0 means not right */
                if ((*(buf + bufOffset) == '\n')){
                        *(buf + bufOffset) = '\0';
                        printf("%s\n",buf);
                        bufOffset = 0;
                        break;
                }
                bufOffset++;
            }  /* end of while */
            }
            if (close(fd) == -1){
                perror("Can not close file");
            }
        }   /* end of for loop */
        return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
