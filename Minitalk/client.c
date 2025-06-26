#include "minitalk.h"

void	send_char(pid_t client_pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(client_pid, SIGUSR2);
		else
			kill(client_pid, SIGUSR1);
		i--;
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;

	if (ac != 3)
	{
		write(2, "Usage: ./client <server-id>\n", 29);
		return (1);
	}
	pid = atoi(av[1]);
	while (*av[2])
		send_char(pid, *av[2]++);
	send_char(pid, '\0');
	return (0);
}
