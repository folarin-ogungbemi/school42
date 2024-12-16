#include "includes/ft_printf.h"

int	main(void)
{
	char	a;

	a = 16;
	int library = printf("c[%c], s[%s], p[%p] d[%d], i[%i], u[%u], x[%x], X[%X], %%[%%]\n", 'x', "string", &a, 12345, 987654, 44, 0, 12);
	int custom = ft_printf("c[%c], s[%s], p[%p] d[%d], i[%i], u[%u], x[%x], X[%X], %%[%%]\n", 'x', "string", &a, 12345, 987654, 44, 0, 12);
    	printf("[%d] library total chars\n", library);
    	printf("[%d] custom total chars\n", custom);
	return (0);
}
