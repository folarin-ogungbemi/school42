#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("ex.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	while ((str = get_next_line(fd)) != NULL)
	{
		printf("\nsleep ...\n");
		sleep(2);
		printf("\n(%s)\n", str);
		printf("\nwake ..\n");
		free(str);
	}
	close(fd);
	return (0);
}
