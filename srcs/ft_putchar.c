/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/15 08:10:58 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/05/19 17:46:19 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
	FT_PUTCHAR
	Writes the character c to the standard output stream.
	PARAMETER(S)
		The character c of type char to be printed.
	RETURN
	The function returns 1 indicating the number of bytes written in stdout.
	EXAMPLES
		ft_putchar('c') outputs "c" and returns 1
		ft_putchar('\0') outputs "" and returns 1
*/

int	ft_putchar(unsigned char c)
{
	return (write(STDOUT_FILENO, &c, 1));
}
