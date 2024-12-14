/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: foogungb <foogungb@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:42:26 by foogungb          #+#    #+#             */
/*   Updated: 2024/12/02 09:22:43 by foogungb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* checks whether c is a 7-bit unsigned char value
 * that fits into the ASCII character set. 
 *  8-bit is considered chars btw 128-255.*/
int	ft_isascii(int c)
{
	if ((unsigned char)c <= 127)
		return (1);
	return (0);
}
