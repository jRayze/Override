#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(void) {
    FILE *file = NULL; // rbp -8
    char username[100]; // rbp - 112
    char flag[41]; // rbp - 160
    char passwd[100]; // rbp - 272
    size_t n = 0; // rbp -12
    
    memset(username, 0, 100);
    username[99] += 4;
    memset(flag, 0, 41);
    flag[40] += 1;
    memset(passwd, 0, 100);
    passwd[99] += 4;
    
    file = fopen("/home/users/level03/.pass", "r"); 
    if (file == 0) {
        fwrite("ERROR: failed to open password file\n", 1, 36, stderr);
        exit(1);
    }
    n = fread(flag,1, 41, file);
    flag[strcspn(flag, "\n")] = '\0';
    if (n != 41) {
        fwrite("ERROR: failed to read password file\n", 1, 41, stderr);
        fwrite("ERROR: failed to read password file\n", 1, 41, stderr );
        exit(1);
    }
    fclose(file);
    puts("===== [ Secure Access System v1.0 ] =====");
    puts("/***************************************\\");
    puts("| You must login to access this system. |");
    puts("\\***************************************/");
    printf("--[ Username: ");
    fgets(username, 100, stdin);
    username[strcspn(username,"\n")] = '\0';
    printf("--[ Password: ");
    fgets(passwd, 100, stdin);
    passwd[strcspn(passwd,"\n")] = '\0';
    puts("*****************************************");
    if (strncmp(flag, passwd, 41) == 0) {
        printf("Greetings, %s!\n", username);
        system("/bin/sh");
        return 0;
    }
    printf(username);
    puts(" does not have access!");
    exit(1);
    return 0;
}