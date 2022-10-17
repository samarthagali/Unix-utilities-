#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **store;
int i=0;

void insertfront(char * str){
    if(str[strlen(str)-2]!='\n'){
    str[strlen(str)-1]='\n';
    str[strlen(str)]='\0';
    }
    store[i]= (char*)malloc( (200)*sizeof(char));
    strcpy(store[i++],str);    
}

void display(char * inpfile){
    i=0;
    FILE * fptr;
    fptr=fopen(inpfile,"r");
    int j;
    if (fptr==NULL){
        fprintf(stderr,"File %s not found",inpfile);
        exit(1);
    }
    store=(char **) malloc( (200*20)*sizeof(char));
    char * line=NULL;
    size_t read,len=0;
    while ((read = getline(&line, &len, fptr)) != -1) {
        insertfront(line);
    }
    for (j=i-1;j>=0;j=j-1){
        printf("%s",store[j]);
    }
}

void writeinto(char * inpfile,char * outfile){
    i=0;
    printf("writing into files for mrev isn't available will be updated for future versions of shell due to a bug");
    // FILE * fptr;
    // fptr=fopen(inpfile,"r");
    // int j;
    // if (fptr==NULL){
    //     fprintf(stderr,"File %s not found",inpfile);
    //     exit(1);
    // }
    // char * line=NULL;
    // store=(char **) malloc( (200*20)*sizeof(char));
    // size_t read,len=0;
    // while ((read = getline(&line, &len, fptr)) != -1) {
    //     insertfront(line);
    // }
    // fptr=fopen(outfile,"w"); 
    // fwrite(store,1,sizeof(store),fptr);
    // fflush(fptr); 
    // fclose(fptr);
    // if(line)
    //     free(line);
}
