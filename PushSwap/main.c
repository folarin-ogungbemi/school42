#include <stdio.h>
//#include <stddev.h>

int	main(int argc, char *argv[])
{
	int	i;

	i = 0;
	if (argc >= 1)
	{
		while (argv[i])
		{
			printf("result [%s]:\n", argv[i]);
			i++;
		}
		printf("argc [%d]:\n", argc);
	}
	return (0);
}
