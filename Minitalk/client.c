#include "minitalk.h"

int	ft_isdigit(char c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_atoi_strict(const char *nptr)
{
	int	nbr;

	nbr = 0;
	while (*nptr)
	{
		if (!ft_isdigit(*nptr))
			return (-1);
		nbr = nbr * 10 + (*nptr - 48);
		nptr++;
	}
	return (nbr);
}

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
	pid = ft_atoi_strict(av[1]);
	if (pid <= 0 || kill(pid, 0) == -1)
	{
		write(2, "Invalid PID\n", 12);
		return (1);
	}
	while (*av[2])
		send_char(pid, *av[2]++);
	send_char(pid, '\0');
	return (0);
}
