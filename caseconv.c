#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int to_upper_file(int in, int out, char **argv)
{
    char ch;
    if(!argv[2])
    {
        in=0;
        out=1;
    }
    if(!argv[3])
        out=1;
    while (read(in, (char*)&ch, sizeof(char)) == 1)
    {
        if ((ch >= 'a') && (ch <= 'z'))
        {
            ch=ch-32;
            write(out, (char*)&ch, sizeof(char));
        }
        else
            write(out, (char*)&ch, sizeof(char));
    }
    return 0;
}

int to_lower_file(int in, int out, char **argv)
{
    if(!argv[2])
    {
        in=0;
        out=1;
    }
    if(!argv[3])
        out=1;
    char ch;
    while (read(in, (char*)&ch, sizeof(char)) == 1)
    {
        if ((ch >= 'A') && (ch <= 'Z'))
        {
            ch = ch + 32;
            write(out, (char*)&ch, sizeof(char));
        }
        else
            write(out, (char*)&ch, sizeof(char));
    }
    return 0;
}

int to_invert_file(int in, int out, char **argv)
{
    if(!argv[2])
    {
        in=0;
        out=1;
    }
    if(!argv[3])
        out=1;
    char ch;
    while (read(in, (char*)&ch, sizeof(char)) == 1)
    {
        if ((ch >= 'a') && (ch <= 'z'))
        {
            ch = ch - 32;
            write(out, (char*)&ch, sizeof(char));
        }
        else if ((ch >= 'A') && (ch <= 'Z'))
        {
            ch = ch + 32;
            write(out, (char*)&ch, sizeof(char));
        }
        else
            write(out, (char*)&ch, sizeof(char));
    }
    return 0;
}

int to_proper_file(int in, int out, char **argv)
{
    if(!argv[2])
    {
        in=0;
        out=1;
    }
    if(!argv[3])
        out=1;
    char ch,aux;
    read(in, (char*)&ch, sizeof(char));
    if (ch >= 'a' && ch <= 'z')
    {
        ch = ch - 32;
        write(out, (char*)&ch, sizeof(char));
    }
    aux=ch;
    while (read(in, (char*)&ch, sizeof(char)) == 1)
    {
        if (ch == ' ' || ch == '\n')
        {
            write(out, (char*)&ch, sizeof(char));
            read(in, (char*)&ch, sizeof(char));
            if ((ch >= 'a') && (ch <= 'z'))
            {
                ch = ch - 32;
                write(out, (char*)&ch, sizeof(char));
            }
            else
                write(out, (char*)&ch, sizeof(char));
        }
        else if ((ch >= 'A' && ch <= 'Z') && (aux != ' ' || aux != '\n' || aux != '\t'))
            {
                aux=ch;
                ch = ch + 32;
                write(out, (char*)&ch, sizeof(char));
            }
        else
            write(out, (char*)&ch, sizeof(char));
    }
    return 0;
}

int to_coppy_file(int in, int out, char **argv)
{
    if(!argv[2])
    {
        in=0;
        out=1;
    }
    if(!argv[3])
        out=1;
    char ch;
    while (read(in, (char*)&ch, sizeof(char)) == 1)
    {
        ch = ch + 32;
        write(out, (char*)&ch, sizeof(char));
    }
    return 0;
}

int main(int argc,char **argv)
{
    int in = open(argv[2], O_RDONLY );
    int out = open(argv[3], O_WRONLY | O_CREAT);
    int status;

    if(strcmp(argv[1], "-u") == 0)
    {
        status = to_upper_file(in,out,argv);
        printf("\nConvertire la majuscule reusita.\n");
    }
    else if(strcmp(argv[1], "-l") == 0)
    {
        status = to_lower_file(in,out,argv);
        printf("\nConvertire la minuscule reusita.\n");
    }
    else if(strcmp(argv[1], "-p") == 0)
    {
        status = to_proper_file(in,out,argv);
        printf("\nConvertire la proper reusita.\n");
    }
    else if(strcmp(argv[1], "-i") == 0)
    {
        status = to_invert_file(in,out,argv);
        printf("\nConvertire inversata reusita.\n");
    }
    else
    {
        status = to_coppy_file(in,out,argv);
        printf("\nCopiere reusita.\n");
    }
    if (status == 0)
    {
        printf("\n Convertire reusita! \n");
        return 0;
    }
    if (status == -1)
    {
        write(3,"\n Nu s-a putut converti.\n",28);
        return 0;
    }
    close(in);
    close(out);
    return 0;
}
