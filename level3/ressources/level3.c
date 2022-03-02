#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void decrypt(int val) {
    char    str[] = "Q}|u`sfg~sf{}|a!";
    size_t  len_str = strlen(str);
    int     index = 0;

    while (index < len_str)
    {
        str[index] = (int)str[index] ^ val;
        index++;
    }
    if (strncmp(str, "Congratulations!", 17) != 0) {
        puts("\nInvalid Password");
    }
    else {
        system("/bin/sh");
    }
}


void test(int i, int d) {
    int diff = d - i;
     // epb-0xc
    if (diff <= 21) {
        if ((diff >= 1 && diff <= 9) || (diff >= 16 && diff <= 21)) {
            decrypt(diff);
        }
    }
    decrypt(rand());
}


int main(void) {
    int i; // esp + 0x1c

    srand(time(0));
    puts("***********************************");
    puts("*\t\tlevel03\t\t**");
    puts("***********************************");
    printf("Password:");
    scanf("%d", &i);
    test(i, 0x1337d00d); // 322424845 - 18 = 322424827
    return(0);
}