#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <sys/ptrace.h>



int main(void) {
    char buff[128] = {0}; // esp + 32
    int value = 0; // esp + 168
    int status = 0; // esp + 28
    pid_t pid = 0; // esp + 172

    pid = fork();
    if (pid == 0) { // processus fils
        prctl(PR_SET_PDEATHSIG, SIGHUP); // 1, 1
        ptrace(PTRACE_TRACEME,0,0,0); //
        puts("Give me some shellcode, k");
        gets(buff);
    }
    else { // processus parent
        do {
            wait(&status);
            if (WIFEXITED(status) && WIFSIGNALED(status)) {
                puts("child is exiting...");
                return (0);
            }
        }
        while((value = ptrace(PTRACE_PEEKUSER, pid, ORIG_EAX * 4, 0)) != 11);
        puts("no exec() for you");
        kill(pid, SIGKILL);
    }
    return(0);
}