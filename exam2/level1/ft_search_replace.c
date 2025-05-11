#include <unistd.h>

void	search_rep(char *str, char s, char r)
{
	while (*str)
	{
		if (*str == s)
			*str = r;
		str++;
	}
}

int	main(int argc, char *argv[])
{
	if (argc == 4 && argv[2][1] == '\0' && argv[3][1] == '\0')
	{
		search_rep(argv[1], argv[2][0], argv[3][0]);
		while (*argv[1])
			write(1, argv[1]++, 1);
	}
	write(1, "\n", 1);
	return (0);
}
