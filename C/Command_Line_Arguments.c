//             ****** Command Line Arguments ******
// Commandline arguments is an important concept in C proramming.
// Sometimes we need to pass arguments from the command line to the program a set of inputs.
// Command line arguments are used to supply permeters to the prorame when it is invoked.
// It is mostly used when you need ot control your program from the console.
// These arguments are passed to the main() method.
// By default at index number 0 program name. (argv[0] = "File_Nmae'';)

#include<stdio.h>

int main(int argc , char *argv[])     // int main(int argc, char **argv)
{
    printf("The value of argc is %d\n", argc);
    for(int i=0; i < argc; i++)
    {
        printf("This argument at index number %d has value of %s\n", i, argv[i]);
    }
    return 0;
}