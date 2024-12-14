/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foogungb <foogungb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:32:13 by foogungb          #+#    #+#             */
/*   Updated: 2024/12/02 09:14:08 by foogungb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Function checks for alphabetic character
 * in the standard C locale */
int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}
