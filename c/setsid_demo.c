#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

int main() {

    pid_t child_pid = fork();
    if (child_pid == -1) {
        perror("fork");
        return -1;
    }
    if (child_pid > 0) {
        if (waitpid(child_pid, NULL, 0) == -1) {
            perror("waitpid");
            return -1;
        }
        return 0;
    }
    printf("before: PID=%ld, PGID=%ld, SID=%ld\n",
        (long)getpid(), (long)getpgrp(), (long)getsid(0));
    pid_t session_id = setsid();
    if (session_id == -1) {
        perror("setsid");
        return -1;
    }
    printf("after: PID=%ld, PGID=%ld, SID=%ld\n",
        (long)getpid(), (long)getpgrp(), (long)getsid(0));

    return 0;
}