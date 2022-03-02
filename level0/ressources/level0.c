#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char **argv) {
    int i;

    puts("***********************************");
    puts("*          -Level00 -          *");
    puts("***********************************");
    printf("Password:");
    scanf("%d", &i);
    if (i != 5276) {
        puts("\nInvalid Password!");
        return (1);
    }
    else {
        puts("\nAuthenticated!");
        system("/bin/sh");
        return (0);
    }
}