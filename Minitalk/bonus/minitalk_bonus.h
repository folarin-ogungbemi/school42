#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# define ACK_RECEIVED	0x01
# define TIMEOUT	0x02

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <signal.h>

void	signal_handler(int signum, siginfo_t *info, void *context);
void	send_char(int client_pid, char c);

#endif
