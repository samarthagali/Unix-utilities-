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
    FILE * fptr;
    fptr=fopen(inpfile,"r");
    int j;
    if (fptr==NULL){
        fprintf(stderr,"File %s not found",inpfile);
        exit(1);
    }
    char * line=NULL;
    size_t read,len=0;
    while ((read = getline(&line, &len, fptr)) != -1) {
        insertfront(line);
    }
    fptr=fopen(outfile,"w"); 
    for (j=i-1;j>=0;j=j-1)
        fprintf(fptr,"%s",store[j]);
    
    if(fptr!=NULL)
        fclose(fptr);
    if(line)
        free(line);
}

void revhelp(){
    printf("Possible Commands are:\n");
    printf("./mrev _filename_:");
    printf("    reads the file into stdout in reverse order line wise  if it exists otherwise returns an  error (if the file is not foun)\n\n");
    printf("./mcrev _inputfile_  _outputfile_:");
    printf("  creates a file with the name specified in output file if it doesn't exist\n");
    printf("                                    if file does exist it rewrites the file from line 1 \n");
    printf("                                    writes the input file line by line but in reverse order\n");
}