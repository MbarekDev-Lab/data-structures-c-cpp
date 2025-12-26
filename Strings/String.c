#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
    char str[] = "Hello, World!";
    printf("%s\n", str);

    int len = 0;
    char str2[] = "Data Structures in C";
    for (int i = 0; str2[i] != '\0'; i++)
    {
        len++;
    }
    printf("%s\n", str2);


    printf("End of program!\n");
    return 0;
}

// clang -o string_app Strings/String.c && ./string_app
