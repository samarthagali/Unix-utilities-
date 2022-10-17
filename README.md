# Unix-utilities-
3 basic tools that can be used in a unix cli implemented using the c programming language

### mcat
The program mcat is a simple program. Generally, it reads a file as specified by the user and prints its contents. A typical usage is as follows, in which the user wants to see the contents of main.c, and thus types:

A mcat reads the file. for example, main.c and prints out its contents. 

### mgrep
The second utility you will build is called mgrep, a variant of the UNIX tool grep. This tool looks through a file, line by line, trying to find a user-specified search term in the line. If a line has the word within it, the line is printed out, otherwise it is not.


 mgrep is always passed a search term and one or more files to grep through (thus, more than one is possible). It should go through each line and see if the search term is in it; if so, the line should be printed, and if not, the line should be skipped.
The matching is case sensitive. Thus, if searching for foo, lines with Foo will not match.

If mgrep encounters a file that it cannot open, it should print "wgrep: cannot open file" (followed by a newline) and exit with status 1.
In all other cases, wgrep should exit with return code 0.


### mrev
An input file might look like this:



The goal of the reversing program is to read in the data from the specified input file and reverse it; thus, the lines should be printed out in the reverse order of the input stream. Thus, for the aforementioned example, the output should be:



###prev
Has 3 functions
- exec prev :executes the previous command
- show prev :shows the previous command
- list prev :lists 20 previous command

