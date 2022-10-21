#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>


int cd(char * dr){
   int n= chdir(".");
   if (n==0){
    printf("changed successfully to %s",getdir());
   }
   else{
    printf("could not change to %s",dr);
   }
}

int crtdir(char * dr){
    int n=mkdir(dr,0777);
    if(!n){
        printf("creation succesful");
    }
    else{
        printf("not succesful in creating dir *dr");
    }
    return n;
}

void  getdir(){
    char n[2000];
    if(getcwd(n,2000)!=NULL){
    printf("%s\n",getcwd(n,2000));
    return}
    else{
        printf("cannot get the current directory");
        return;
    }
}

