#include "minitalk.h"

static void	putnbr_postv(int nbr)
{
	char	nb;

	if (nbr > 9)
		putnbr_postv(nbr / 10);
	nb = nbr % 10 + 48;
	write(1, &nb, 1);
}

static void	print_buf(char *buf, int size)
{
	write(1, buf, size);
	write(1, "\n", 1);
}

void	signal_handler(int signum)
{
	static unsigned char	current_char = 0;
	static int				bit_count = 0;
	static int				index = 0;
	static char				buffer[BUFFER_SIZE];

	if (signum == SIGUSR2)
		current_char |= (1 << (7 - bit_count));
	bit_count++;
	if (bit_count == 8)
	{
		if (index < BUFFER_SIZE - 1)
		{
			buffer[index++] = current_char;
			if (current_char == '\0')
			{
				print_buf(buffer, index - 1);
				index = 0;
			}
		}
		else
			index = 0;
		bit_count = 0;
		current_char = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

	pid = getpid();
	sa.sa_handler = signal_handler;
	sa.sa_flags = 0;
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
