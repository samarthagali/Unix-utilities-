#include <stdio.h>

void revhelp(){
    printf("Possible Commands are:\n");
    printf("mrev _filename_:");
    printf("    reads the file into stdout in reverse order line wise  if it exists otherwise returns an  error (if the file is not foun)\n\n");
    printf("mcrev _inputfile_  _outputfile_:");
    printf("  creates a file with the name specified in output file if it doesn't exist\n");
    printf("                                    if file does exist it rewrites the file from line 1 \n");
    printf("                                    writes the input file line by line but in reverse order\n");
}

void helpcat(){
    printf("Possible Commands are:\n");
    printf("mcat _filename_:    reads the file into stdout if it exists returns an  error if the file is not found\n\n");
    printf("mcat e _filename_:    creates a file with the name specified if it doesn't exist\n");
    printf("                       if file does exist it rewrites the file from line 1 \n");
    printf("                       writes until ~ character is encountered\n");
}


void grephelp(){
    printf( "Search for PATTERNS in each FILE.\nmgrep _pattern_ _filenames\nmultiple files can be entered after the pattern\n");
}

void prevhelp(){
    printf("possible commands are:\n");
    printf("show prev:lists the previous command entered\n");
    printf("exec prev:executes the previous command\n");
    printf("list prev:lists 20 previous commands entered\n");
    printf("commands with prev in them are not stored\n");
}