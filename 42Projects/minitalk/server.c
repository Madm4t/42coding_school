#include "minitalk.h"

typedef struct {
    volatile sig_atomic_t bit_index;
    volatile sig_atomic_t current_char;
} GlobalData;

GlobalData global_data = {0, 0};

void signal_handler(int signum, siginfo_t *info, void * context)
{
	(void)context; //suppresses the unused parameter
	char newline = '\n';
	global_data.current_char = global_data.current_char << 1;
	if (signum == SIGUSR1) 
		global_data.current_char |= 1;
	global_data.bit_index++;
	if (global_data.bit_index == 8)
	{
		if (global_data.current_char == '\0')
		{
			write(STDOUT_FILENO, &newline, 1);
			kill (info->si_pid, SIGUSR2);
		}
		else
		{
			write(STDOUT_FILENO, (const void*)&global_data.current_char, 1);
			kill (info->si_pid, SIGUSR1);
		}
		global_data.bit_index = 0;
		global_data.current_char = 0;
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

