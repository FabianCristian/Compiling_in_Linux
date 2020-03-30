# Compiling_in_Linux

Here you'll find a little program made for converting characters.
Written in the C programming language.
You'll need input file, output file. In Linux, input and output files may be missing and then input and output will be stdin and stdout.
Option are:
    -l  - convert to lower case
    -u  - convert to upper case
    -p  - convert to proper case (the first letter of word to upper and the rest to lower)
    -i  - invert upper case to lower case and lower case to upper case
        - if the option is missing, it will just copy the text
For compiling in the Linux terminal:
$ gcc caseconv.c -o caseconv
$ ./caseconv -option file.in file.out
Examples:
$ ./caseconv -l file1.txt file2.txt
$ ls -1 | ./caseconv -u  //coverts the output from the ls command to lower case and prints the result to terminal
