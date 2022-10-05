#include "mcat.h"
#include "mgrep.h"
#include "mrev.h"

void main(int argc,char** argv){
    if(argc==1){
    char *q="quit";
    char  line[200];
    while(1){
        printf("sam-shell>");
        fgets(line, sizeof(line), stdin);
        if (strstr(line,q)){
            printf("\nexiting sam shell\n");
            exit(0);
        }
    }
    }
    else{
        printf("cannot enter shell by passing command line arguments\nplease retry without passing arguments\n");
        exit(1);
    }
}