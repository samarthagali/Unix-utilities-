#include "mcat.h"
#include "mgrep.h"
#include "mrev.h"
#include "help.h"
#include "dirs.h"
void gotomcat(char * line);

void gotogrep(char * line);

void gotorev(char * line);

void showprev();

void execprev();

int checkprev(char * line);

void exec(char * line);

struct comms{
    char line[200];
    char check;
};
struct comms commands[20];
int front=-1,rear=-1;
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

void listprev(){
    if(front!=-1){
    int i=front;
    do{
        i=(i+1)%20;
        if(commands[i].check)
            printf("%s",commands[i].line);
        else
            continue;
    }while(i!=front);   
    }
}
void showprev(){
    int i;
    i=(rear)%20;
    printf("%s",commands[i].line);
}
void execprevcom(){
    int i;
    i=(rear)%20;
    exec(commands[i].line);
}
int checkprev(char * line){
    char * delim=" ";
    char newl[200];
    char *ex="exec",* show="show",*prev="prev",*list="list",*help="help";
    memcpy(newl,line,strlen(line));
    char * token =strtok(line,delim);
    int k=strcmp(ex,token);
    int j=strcmp(show,token);
    int l=strcmp(list,token);
    int m=strcmp(help,token);
    if(k==0||j==0||l==0||m==0){
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
        // printf("\n\n\n\n%s",last);
        last[strlen(last)-1]='\0';
        if(strcmp(prev,second)&&i==2){
        if(j==0){ 
            showprev();
            return 1;   
            }
        if(k==0){
            printf("in here"); 
            execprevcom();
            return 1;
        }
        if(l==0){   
        listprev();
        return 1;}
        prevhelp();
        return 1;
        }
        printf("invalid command pls enter help prev to see all possible commands");
        return 1;
        }
    return 0;
}

void enqueue(char * line){
    if (rear==front-1);{
        front=(front+1)%20;
        rear=(rear+1)%20;
        strcpy(commands[rear].line,line);
        commands[rear].check=1;
        return;
    }
    if(front==-1){
        front=(front+1)%20;
    }
    rear=(rear+1)%5;
    strcpy(commands[rear].line,line);
    commands[rear].check=1;
}

void exec(char * line){
    char *q="quit";
    char * cat="mcat ";
    char * grep="mgrep ";
    char * rev="mrev ";
    char check[5];
    if (strstr(line," prev")&&front!=-1 ){
        
    int i=checkprev(line);
    return;}
    enqueue(line);
    if (strstr(line,q)){
       int i=0;
       printf("\n\n");
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
        //
    }
    }
    else{
        printf("cannot enter shell by passing command line arguments\nplease retry without passing arguments\n");
        exit(1);
    }
}


