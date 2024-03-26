#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void signal_handler(int signum, siginfo_t *info, void *context) {
    if (signum == SIGUSR1 || signum == SIGUSR2) {
        char message[] = "Received signal from client PID: \n";
        write(STDOUT_FILENO, message, sizeof(message) - 1);
        // Convert PID to string and use write() to output it, or just indicate signal was received.
        kill(info->si_pid, SIGUSR1);
    }
}

int main() {
    pid_t pid = getpid(); // Get the PID of the server
    printf("Server PID: %d\n", pid);

    struct sigaction sa;
    sa.sa_sigaction = signal_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_SIGINFO;

    sigaction(SIGUSR1, &sa, NULL); // Register signal handler for SIGUSR1
    sigaction(SIGUSR2, &sa, NULL); // Register signal handler for SIGUSR2

    while (1) {
        pause(); // Wait for signals indefinitely
    }

    return 0;
}
