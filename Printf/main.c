#include "includes/ft_printf.h"

int	main(void)
{
	char	a;

	a = 16;
	int library = printf("c[%c], s[%s], p[%p] d[%d], i[%i], u[%u], x[%x], X[%X], %%[%%]\n", 'x', "string", &a, 12345, 987654, 44, 12, 12);
	int libp = ft_printf("p1[%p], p2[%p] p3[%p]\n", 0, -2, 5);
	int libu = printf("u1[%u], u2[%u] u3[%u]\n", -1, -123, 5);
	int cusu = ft_printf("u1[%u], u2[%u] u3[%u]\n", -1, -123, 5);
	int libx = printf("x1[%x], x2[%x] x3[%x]\n", -1, -123, 5);
	int cusx = ft_printf("x1[%x], x2[%x] x3[%x]\n", -1, -123, 5);
	int libX = printf("X1[%X], X2[%X] X3[%X]\n", -1, -123, 5);
	int cusX = ft_printf("X1[%X], X2[%X] X3[%X]\n", -1, -123, 5);
	int libd = printf("d[ %d %d %ld %ld %ld %d %d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	int cusd = ft_printf("d[ %d %d %d %d %d %d %d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

	int custom = ft_printf("c[%c], s[%s], p[%p] d[%d], i[%i], u[%u], x[%x], X[%X], %%[%%]\n", 'x', "string", &a, 12345, 987654, 44, 12, 12);
    	printf("[%d] library total chars\n", library);
    	printf("[%d] libd\n", libd);
    	printf("[%d] cusd\n", cusd);
    	printf("[%d] libp\n", libp);
    	printf("[%d] libu\n", libu);
    	printf("[%d] cusu\n", cusu);
    	printf("[%d] libx\n", libx);
    	printf("[%d] cusx\n", cusx);
    	printf("[%d] libX\n", libX);
    	printf("[%d] cusX\n", cusX);
    	printf("[%d] custom total chars\n", custom);
	return (0);
}
