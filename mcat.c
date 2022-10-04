#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void main(int argc, char** argv){
    if (argc!=2 && argc!=3){
        fprintf(stderr,"incorrect command for mycat editor\nenter mcat --help inorder to view all possible command options ");
        exit(1);
    }
    else{
        if (argc==2){
            if(strcmp(argv[1],"--help")!=0){
                FILE *fptr;
                fptr=fopen(argv[1],"r");
                if (fptr==NULL){
                    fprintf(stderr,"FILE %s not found",argv[1]);
                    exit(1);
                }
                char * line=NULL;
                size_t read,len=0;
                while ((read = getline(&line, &len, fptr)) != -1) {
                    printf("%s", line);
                }
                fclose(fptr);
                if (line){
                    free(line);}
                exit(0);}
            else{
                printf("Possible Commands are:\n");
                printf("./mcat _filename_:\n");
                printf("    reads the file into stdout if it exists returns an  error if the file is not found\n");
                printf("./mcat # _filename_\n");
                printf("    creates a file with the name specified if it doesn't exist\n");
                printf("    if file does exist it rewrites the file from line 1 ");
                printf("    writes until ~ character is encountered");
                exit(0);            
                }
        }
        if (strcmp(argv[1],"#")==0){
            FILE *fptr;
            fptr=fopen(argv[2],"w");
            char *str;
            char c='~';
            do{
                scanf("%s",str);
                fputs(str,fptr);
            }while (strchr(str,c));
            exit (0);
        }
        else{
            fprintf(stderr,"incorrect command for mycat editor\nenter mcat --help inorder to view all possible command options ");
            exit(1);
        }
    }
}