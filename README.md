# Unix-utilities-
3 basic tools that can be used in a unix cli implemented using the c programming language

### mcat
The program mcat is a simple program. Generally, it reads a file as specified by the user and prints its contents. A typical usage is as follows, in which the user wants to see the contents of main.c, and thus types:

A mcat reads the file. for example, main.c and prints out its contents. 

This will make a single executable binary called mcat which can be run


 mcat can be invoked with one or more files on the command line; it should just print out each file in turn.
In all non-error cases, mcat  exits with status code 0,  by or by calling exit(0).
If no files are specified on the command line, mcat  exits and return 1. Note that this is slightly different than the behavior of normal UNIX cat (if you'd like to, figure out the difference).
If the program tries to fopen() a file and fails, an error is printed to stderr  and exits with status code 1.

### mgrep
The second utility you will build is called mgrep, a variant of the UNIX tool grep. This tool looks through a file, line by line, trying to find a user-specified search term in the line. If a line has the word within it, the line is printed out, otherwise it is not.

Here is how a user would look for the term foo in the file bar.txt:

```
prompt> ./wgrep foo bar.txt
this line has foo in it
so does this foolish line; do you see where?
even this line, which has barfood in it, will be printed.
```
 mgrep is always passed a search term and one or more files to grep through (thus, more than one is possible). It should go through each line and see if the search term is in it; if so, the line should be printed, and if not, the line should be skipped.
The matching is case sensitive. Thus, if searching for foo, lines with Foo will not match.

If mgrep encounters a file that it cannot open, it should print "wgrep: cannot open file" (followed by a newline) and exit with status 1.
In all other cases, wgrep should exit with return code 0.


### mrev
An input file might look like this:

```
hello
this
is 
a file
```

The goal of the reversing program is to read in the data from the specified input file and reverse it; thus, the lines should be printed out in the reverse order of the input stream. Thus, for the aforementioned example, the output should be:

```
a file
is
this
hello
```

The different ways to invoke the tool are with two command-line arguments and with one,when invoked with two arguments the program should read from the input file the user supplies and write the reversed version of said file to the output file the user supplies.

When invoked with just one argument, the user supplies the input file, but the file should be printed to the screen. In Unix-based systems, printing to the screen is the same as writing to a special file known as standard output, or stdout for short.

