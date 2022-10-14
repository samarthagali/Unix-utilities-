#include "mcat.h"
#include "mgrep.h"
#include "mrev.h"

void gotomcat(char * line);

void gotogrep(char * line);

void gotorev(char * line);

void showprev(int no);

void execprev(int no);

int checkprev(char * line);

void exec(char * line);


char commands[20][200];
int pos=0;

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

void showprev(int no){
    int i;
    i=(pos-no-1)%20;
    printf("%s",commands[i]);
}

void execprevcom(int no){
    int i;
    i=(pos-no-1)%20;
    exec(commands[i]);
}
int count;
char nums[]={"0123456789"};
int checkprev(char * line){
    char * delim=" ";
    char newl[200];
    char *ex="exec",* show="show",*prev="prev";
    memcpy(newl,line,strlen(line));
    char * token =strtok(line,delim);
    int k=strcmp(ex,token);
    int j=strcmp(show,token);
    if(k==0||j==0){
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
        printf("%c",last[0]);
        last[strlen(last)-1]='\0';
        if(strcmp(prev,second)&&i<=2){
            if(k){
                if(strlen(second)==4){
                    showprev(1);
                    return 1;
                }
           
                if(isdigit(second[4])){
                    showprev((int)second[5]);
                    return 1;
                }
                else{
                    printf("invalid command pls enter a no after prev ");
                    return 1;
                    }
            }
            if(i==2){
                showprev(1);
                return 1;
            }
            if(strchr(nums,last[0])){
                printf("in here");
                showprev((int)last[0]);
                return 1;}
            printf("invalid command pls enter a no after prev");
            return 1;
        }
        return 0;
        
    }
    return 0;
}


void exec(char * line){
    char *q="quit";
    char * cat="mcat ";
    char * grep="mgrep ";
    char * rev="mrev ";
    char check[5];
    strcpy(commands[pos],line);
    pos=(pos+1)%20;
    count++;
    if (strstr(line," prev")&&count>1 ){
        
    int i=checkprev(line);
    if(i==1)
        return;}
    if (strstr(line,q)){
       int i=0;
    //    printf("commands entered are:\n");
    //    for (i=0;i<pos;i++){
    //         printf("%s",commands[i]);
    //    }
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


