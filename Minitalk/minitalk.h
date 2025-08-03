#ifndef MINITALK_H
# define MINITALK_H

# define BUFFER_SIZE	1024

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <signal.h>

void	signal_handler(int signum);
void	send_char(int client_pid, char c);

#endif
