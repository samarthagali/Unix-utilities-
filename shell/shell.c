#include "mcat.h"
#include "mgrep.h"
#include "mrev.h"
#include <ncurses.h>
void gotomcat(char * line){
    char * writer="mcat e";
    char * delim=" ";
    char newl[200];
    memcpy(newl,line,strlen(line));
    char * token =strtok(line,delim);
    char last[200];
    int i =0;   
    while(token!=NULL){
        i++;
        memcpy(last,token,strlen(token));
        token=strtok(NULL,delim);
    }
    last[strlen(last)-1]='\0';
    if(strstr(newl,writer)){
        printf("in writer\n");
        writefcat(last);
        return;
    }
    char * help="mcat --help";
    if(strstr(newl,help)){
        helpcat();
        return;
    }
    printf("in reader\n");
    printf("%s\n",last);
    readfcat(last);
    return;
}

void gotogrep(char * line){
    printf("in grepper\n");
    char * writer="mcat e";
    char * delim=" ";
    char newl[200];
    memcpy(newl,line,strlen(line));
    char * token =strtok(line,delim);
    char last[200],second[200];
    int i =0;   
    while(token!=NULL){
        i++;
        if(i==2){
            strcpy(second,token);
        }
        memcpy(last,token,strlen(token));
        token=strtok(NULL,delim);
    }
    char * help="mgrep --help";
    if(strstr(newl,help)){
        grephelp();
        return;
    }
    last[strlen(last)-1]='\0';
    search(second,last);
}

void gotorev(char * line){
    printf("in rev\n");
    char * writer="mcat e";
    char * delim=" ";
    char newl[200];
    memcpy(newl,line,strlen(line));
    char * token =strtok(line,delim);
    char last[200],second[200];
    int i =0;   
    while(token!=NULL){
        i++;
        if(i==2){
            strcpy(second,token);
        }
        memcpy(last,token,strlen(token));
        token=strtok(NULL,delim);
    }
    char * help="mrev --help";
    if(strstr(newl,help)){
        revhelp();
        return;
    }
    last[strlen(last)-1]='\0';
    if(i==2){
        display(last);
        return;
    }
    // printf("%s",second);
    last[strlen(last)-1]='\0';
    writeinto(second,last);
}

void exec(char * line){
    char *q="quit";
    char * cat="mcat ";
    char * grep="mgrep ";
    char * rev="mrev ";
    char check[5];
    if (strstr(line,q)){
        printf("\nexiting sam shell\n");
        exit(0);
        }
        memcpy(check,line,5);
    if(strstr(check,cat)){
        gotomcat(line);
        return;
        }
    if(strstr(check,grep)){
        gotogrep(line);
        return;
        }
    if(strstr(check,rev)){
        gotorev(line);
        return;
        }
}

void main(int argc,char** argv){
    if(argc==1){
    char  line[200];
    while(1){
        printf("sam-shell>");
        fgets(line, sizeof(line), stdin);
        exec(line);
    }
    }
    else{
        printf("cannot enter shell by passing command line arguments\nplease retry without passing arguments\n");
        exit(1);
    }
}