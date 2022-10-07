#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


void readfcat(char * inpfile){
    FILE *fptr ;
    fptr=fopen(inpfile,"r");
    if (fptr==NULL){
        fprintf(stderr,"File %s not found",inpfile);
        return;
    }
    char * line=NULL;
    size_t read,len=0;
    while ((read = getline(&line, &len, fptr)) != -1) 
        printf("%s", line);
    fclose(fptr);
    if (line){
    free(line);}
    printf("\n");
    return;
}

void writefcat(char * outfile){
        FILE *fptr;
        fptr=fopen(outfile,"w");
        char str[200];
        char c='~';
        do{
            fgets(str, sizeof(str), stdin);
            printf("%s",str);
            if (strchr(str,c)){
                break;
            }
            fputs(str,fptr);
        }while(1);
        str[strlen(str)-2]='\n';
        str[strlen(str)-1] = '\0';
        fputs(str,fptr);
        fflush(fptr);
        fclose(fptr);
}


void helpcat(){
    printf("Possible Commands are:\n");
    printf("./mcat _filename_:    reads the file into stdout if it exists returns an  error if the file is not found\n\n");
    printf("./mcat e _filename_:    creates a file with the name specified if it doesn't exist\n");
    printf("                       if file does exist it rewrites the file from line 1 \n");
    printf("                       writes until ~ character is encountered\n");
}

