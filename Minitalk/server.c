#include "minitalk.h"

void	putnbr_postv(int nbr)
{
	char	nb;

	if (nbr > 9)
		putnbr_postv(nbr / 10);
	nb = nbr % 10 + 48;
	write(1, &nb, 1);
}

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static unsigned char	current_char = 0;
	static int				bit_count = 0;

	(void)context;
	if (signum == SIGUSR2)
		current_char |= (1 << (7 - bit_count));
	bit_count++;
	if (bit_count == 8)
	{
		write(1, &current_char, 1);
		if (current_char == '\0')
			write(1, "\n", 1);
		bit_count = 0;
		current_char = 0;
		kill(info->si_pid, SIGUSR2);
	}
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	pid = getpid();
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	write(1, "SERVER PID is: ", 15);
	putnbr_postv(pid);
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
