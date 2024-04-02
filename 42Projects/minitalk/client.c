#include "minitalk.h"

void signal_handler(int signum)
{
    if (signum == SIGUSR1 || signum == SIGUSR2) {
        char message[] = "Signal was successfully sent\n";
        write(STDOUT_FILENO, message, sizeof(message) - 1);
    }
}

int main(int argc, char *argv[]) {
	struct sigaction sa;
    sa.sa_handler = signal_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server_pid> <string>\n", argv[0]);
        return 1;
    }

    pid_t server_pid = atoi(argv[1]); // Get server PID from command line argument
    char *message = argv[2]; // Get message to send from command line argument

    for (int i = 0; message[i] != '\0'; i++) {
        if (message[i] == '0') {
            kill(server_pid, SIGUSR1); // Send SIGUSR1 for '0'
        } else {
            kill(server_pid, SIGUSR2); // Send SIGUSR2 for '1'
        }
        usleep(100); // Sleep for a short duration to ensure signals are sent separately
    }
	

    return 0;
}

while (message[i] != '\0')
	{
		bit_index = 0;
		while (bit_index < 8)
		{
			message[i] 
		}
	}