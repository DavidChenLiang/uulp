#include <stdlib.h>
#include <stdio.h>

int 
main(void){
    char * cp = getenv("LANG");
    if (cp != NULL && strcmp(cp,"fr") == 0){
        printf("Bonjour\n");
    }else{
        printf("Hello\n");
    }
}
