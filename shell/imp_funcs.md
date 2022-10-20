## In built functions
###  strings (<string.h>)
#### strcpy :
            copies from source to destination
            char * strcpy(char * dest,char * source);
####  memcpy :
            copies from  number of bytes source to destination
            void memcpy(void * dest,void * source,size_t num_of_bytes);
#### strtok :
            breaks string into different tokens based on delimiter
            similar to split function but does it one occurence at a time
            char * strtok (char *token,char * delimiter);

### files (<stdio.h>)
#### fopen :
            opens file in mode specified
            FILE * fopen(char * filename,char * mode);
#### fputs : 
            writes string to file excluding last char
            int fputs(char * string ,FILE * fptr);
#### fgets :
            puts n character from a file into a string
            char * fgets(char * str,int n, FILE * fptr);

#### getline :
            writes into string one line at a time 
            size_t getline (char **string, size_t *n, FILE *stream);

### directory (<dirent.h>,<sys/stat.h>)
#### chdir :
            changes to directory specified (cd in terminal)
            int chdir(char * path);
#### mkdir : 
            makes directory with given name
            int mkdir(const char *__path, mode_t __mode);
#### getcwd :
            gets current working directory
            char *getcwd(char *__buf, size_t __size);
#### opendir :
            Open a directory stream on name if exists
            DIR *opendir(const char *__name)            
#### readdir :
            reads directory specified if it exists
            struct dirent *readdir(DIR *__dirp)