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
    store[i]= malloc( (200)*sizeof(char));
    strcpy(store[i++],str);    
}

void display(){
    int j;
    for (j=i;j>=0;j=j-1){
        printf("%s",store[j]);
    }
}

void writeinto(char * fname){
    FILE * fptr;
    fptr=fopen(fname,"w");
    int j;   
    for (j=i-1;j>=0;j=j-1)
        fprintf(fptr,"%s",store[j]);
    
    if(fptr!=NULL)
        fclose(fptr);
}

void main(int argc, char** argv){
    if (argc!=2 && argc!=3) {
        printf("%s",argv[1]);
        fprintf(stderr,"incorrect command for mycat editor\nenter ./mcat --help inorder to view all possible command options ");
        exit(1);
    }
    store= malloc( (200*20)*sizeof(char));
     if (argc==2){
            if(strcmp(argv[1],"--help")!=0){
                FILE *fptr;
                fptr=fopen(argv[1],"r");
                if (fptr==NULL){
                    fprintf(stderr,"File %s not found",argv[1]);
                    exit(1);
                }
                char * line=NULL;
                size_t read,len=0;
                while ((read = getline(&line, &len, fptr)) != -1) {
                    insertfront(line);
                }
                display();
                fclose(fptr);
                if (line){
                    free(line);}
                exit(0);}   
       else{
                printf("Possible Commands are:\n");
                printf("./mrev _filename_:");
                printf("    reads the file into stdout in reverse order line wise  if it exists otherwise returns an  error (if the file is not foun)\n\n");
                printf("./mcrev _inputfile_  _outputfile_:");
                printf("  creates a file with the name specified in output file if it doesn't exist\n");
                printf("                                    if file does exist it rewrites the file from line 1 \n");
                printf("                                    writes the input file line by line but in reverse order");
                exit(0);            
                }
        }
        FILE *fptr;
        fptr=fopen(argv[1],"r");
        if (fptr==NULL){
                fprintf(stderr,"File %s not found",argv[1]);
                exit(1);
        }
        char * line=NULL;
        size_t read,len=0;
        while ((read = getline(&line, &len, fptr)) != -1) {
                insertfront(line);
        }
        fclose(fptr);
        writeinto(argv[2]);
        if (line){
        free(line);}
        exit(0);
}