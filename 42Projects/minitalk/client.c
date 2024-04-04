#include "minitalk.h"

volatile sig_atomic_t server_recived_message = 0;

void	signal_handler(int signum)
{
	if (signum == SIGUSR2)
	{
		char message[] = "Server recived Message\n";
        write(STDOUT_FILENO, message, sizeof(message) - 1);
		usleep(100);
		server_recived_message = 1;
	}
}
int end_of_line(pid_t server_pid)
{
	int	i;
	i = 0;
	while (i < 8)
	{
		kill(server_pid, SIGUSR2);
		usleep(100);
		i++;
	}
	return (0);
}

int	message_to_bit(char *message, pid_t server_pid)
{
	int		i;
	int		bit_index;
	int		bit_to_send;
	i = 0;
	while (message[i] != '\0')
	{
		bit_index = 7;
		while (bit_index >= 0)
		{
			bit_to_send = ((int)message[i] >> bit_index) & 1; 
			if (bit_to_send == 1)
				kill(server_pid, SIGUSR1);
			else
				kill(server_pid, SIGUSR2);
			usleep(300);
			bit_index--;
		}
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
	{
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
	if (message_to_bit(message, server_pid) == 0)
		end_of_line(server_pid);
	while (!server_recived_message)
		pause();
    return 0;
	}
