/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foogungb <foogungb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:08:50 by foogungb          #+#    #+#             */
/*   Updated: 2024/12/02 14:45:18 by foogungb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(int nb)
{
	size_t	count;

	count = 0;
	if (nb <= 0)
		count++;
	while (nb != 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

static char	*ft_zero(int n, char *m)
{
	if (n == 0)
	{
		m[0] = 48;
		m[1] = '\0';
		return (m);
	}
	return (NULL);
}

static int	ft_negative(int n, char *m)
{
	if (n < 0)
	{
		m[0] = '-';
		n = -n;
	}
	return (n);
}

/* Function returns a string representing the integer received as an argument.
 * Negative numbers must be handled. */
char	*ft_itoa(int n)
{
	char	*m;
	size_t	len;
	size_t	i;

	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	len = ft_count(n);
	i = len - 1;
	m = (char *)malloc(len + 1);
	if (!m)
		return (NULL);
	m[len] = '\0';
	if (ft_zero(n, m))
		return (m);
	n = ft_negative(n, m);
	while (n > 0)
	{
		m[i] = (n % 10) + 48;
		n /= 10;
		i--;
	}
	return (m);
}
