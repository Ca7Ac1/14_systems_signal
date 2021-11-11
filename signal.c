#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <string.h>

void sighandler(int signo)
{
    if (signo == SIGINT)
    {
        int writer = open("File.txt", O_WRONLY | O_APPEND | O_CREAT, 0644);
        char message[] = "Exited due to SIGINT";
        write(writer, message, sizeof(message[0]) * strlen(message));
        exit(0);
    }
    else if (signo == SIGUSR1)
    {
        printf("Parent PID: %d\n", getppid());
    }
}

int main()
{
    signal(SIGINT, sighandler);
    signal(SIGUSR1, sighandler);

    while (1)
    {
        printf("PID: %d\n", getpid());
        sleep(1);
    }

    return 0;
}