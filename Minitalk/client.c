#include "minitalk.h"

volatile sig_atomic_t	g_status = 0;

int	ft_atoi_strict(const char *nptr)
{
	int	nbr;

	nbr = 0;
	while (*nptr)
	{
		if (!(*nptr >= 48 && *nptr <= 57))
			return (-1);
		nbr = nbr * 10 + (*nptr - 48);
		nptr++;
	}
	return (nbr);
}

void	ack_handler(int signum)
{
	(void)signum;
	g_status |= ACK_RECEIVED;
}

void	timeout_handler(int signum)
{
	(void)signum;
	g_status |= TIMEOUT;
}

void	send_char(pid_t pid, char c)
{
	int	i;

	g_status &= ~(ACK_RECEIVED | TIMEOUT);
	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i--;
		usleep(500);
	}
	alarm(2);
	while (!(g_status & (ACK_RECEIVED | TIMEOUT)))
		pause();
	alarm(0);
	if (g_status & TIMEOUT)
	{
		write(2, "Error: Timeout no ACK received.\n", 32);
		_exit(1);
	}
	g_status &= ~ACK_RECEIVED;
}

int	main(int ac, char **av)
{
	pid_t		pid;

	if (ac != 3)
	{
		write(2, "Usage: ./client <server-pid>\n", 29);
		return (1);
	}
	pid = ft_atoi_strict(av[1]);
	if (pid <= 0 || kill(pid, 0) == -1)
	{
		write(2, "Error: Invalid Server PID.\n", 27);
		return (1);
	}
	signal(SIGUSR2, ack_handler);
	signal(SIGALRM, timeout_handler);
	while (*av[2])
		send_char(pid, *av[2]++);
	send_char(pid, '\0');
	return (0);
}
