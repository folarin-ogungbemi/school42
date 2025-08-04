#include "minitalk.h"

static int	ft_atoi_strict(const char *nptr)
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

void	send_char(pid_t pid, char c)
{
	int	i;

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
}

int	main(int ac, char **av)
{
	pid_t		pid;

	if (ac != 3)
	{
		write(2, "Usage: ./client PID msg\n", 24);
		return (1);
	}
	pid = ft_atoi_strict(av[1]);
	if (pid <= 0 || kill(pid, 0) == -1)
	{
		write(2, "Error: Invalid Server PID.\n", 27);
		return (1);
	}
	while (*av[2])
		send_char(pid, *av[2]++);
	send_char(pid, '\0');
	return (0);
}
