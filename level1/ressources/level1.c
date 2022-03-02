#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char a_user_name[256];

int verify_user_pass(char *buff) {
    return (strncmp(buff, "admin", 5));
}

int verify_user_name(void) {
    puts("verifying username....\n");
    return (strncmp(a_user_name, "dat_wil", 7));
}

int main(void) {
    char buff[64] = {0};
    int i = 0;
    puts("********* ADMIN LOGIN PROMPT *********");
    fgets(a_user_name , 256, stdin);
    i = verify_user_name();

    if (i != 0) {
        puts("nope, incorrect username...\n");
        return(1);
    }
    puts("Enter Password: ");
    fgets(buff, 100, stdin);
    i = verify_user_pass(buff);
    if (i == 0) {
        puts("nope, incorrect password...\n");
        return (1);
    }
    if (i == 0) {
        return (0);
    }
    puts("nope, incorrect password...\n");
    return (1);
}