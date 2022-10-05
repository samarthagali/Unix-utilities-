#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int search(char * key,char * inpfile){
    FILE * fptr;
    fptr=fopen(inpfile,"r");
    if (fptr==NULL){
        fprintf(stderr,"File %s not found",inpfile);
        return 0;
    }
    printf("searching for keyword in file %s\n",inpfile);
    char * line=NULL;
    size_t read,len=0;
    int flag=0;
    while ((read = getline(&line, &len, fptr)) != -1) {
        if(strstr(line,key)){
            flag=1;
            printf("%s",line);
        }
    }
}