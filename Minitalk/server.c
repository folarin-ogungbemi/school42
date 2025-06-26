#include "minitalk.h"

void	signal_handler(int signum)
{
	static unsigned char	current_char = 0;
	static int		bit_count = 0;

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
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = signal_handler;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, (struct sigaction *)&sa, NULL);
	sigaction(SIGUSR2, (struct sigaction *)&sa, NULL);
	printf("SERVER PID is: %d\n", getpid());
	while (1)
		pause();
	return (0);
}
