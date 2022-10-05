#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void main(int argc,char ** argv){
    if (argc<3){
        if(argc<2){
        fprintf(stderr,"pls refer to ./mgrep -- help  for details on how to use mgrep ");
        exit(1);}
        else if((strcmp(argv[1],"--help")!=0)){
        fprintf(stderr,"pls refer to ./mgrep -- help  for details on how to use mgrep ");
        exit(1);}
       printf( "Search for PATTERNS in each FILE.\n./mgrep _pattern_ _filenames\nmultiple files can be entered after the pattern");
       exit(0);
    }
    else{
    char *key= argv[1];
    int i;
    for (i=2;i<argc;i++){
        FILE * fptr;
        fptr=fopen(argv[i],"r");
        if (fptr==NULL){
                fprintf(stderr,"File %s not found",argv[i]);
                continue;
                }
        printf("searching for keyword in file %s\n",argv[i]);
        char * line=NULL;
        size_t read,len=0;
        int flag=0;
        while ((read = getline(&line, &len, fptr)) != -1) {
                if(strstr(line,key)){
                    flag=1;
                    printf("%s",line);
                }
        }
        if(flag==0){
            printf("no instances of keywords %s found in file %s",key,argv[i]);
        }
        printf("\n\n\n");
    }
    }
}