/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foogungb <foogungb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:46:57 by foogungb          #+#    #+#             */
/*   Updated: 2024/12/02 10:51:11 by foogungb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

/* The memset() function fills the first n bytes
 * of the memory area pointed to by s with the constant byte c.*/
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned int	i;

	p = s;
	i = 0;
	while (i < n)
	{
		p[i] = c;
		i++;
	}
	return (s);
}
/*
#include <stddef.h>
#include <stdio.h>
int	main(void)
{
	char	arr[5] = "test";
	int	i;

	i = 0;	
	printf("Before: %s\n", arr);
	ft_memset(arr, 0, sizeof(arr));
	while (i < 5)
	{
		printf("at index: %d %d\n", i, arr[i]);
		i++;
	}
	printf("After: %s\n", arr);
	return (0);
}*/
