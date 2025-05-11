#include <unistd.h>
#include <time.h>
#include <string.h>
#include <stdio.h>

/*
size_t	ft_strspn(const char *s, const char *accept)
{
	while (*s)
}
*/
int	main(void)
{
	clock_t	start;
	clock_t end;
	double	time_taken;

	start = clock();
	printf("result: %ld\n", strspn("folarin", "f"));
	end = clock();
	time_taken = (double)(end - start)/ CLOCKS_PER_SEC;
	printf("time taken: %f seconds to execution\n", time_taken);
	return (0);
}
