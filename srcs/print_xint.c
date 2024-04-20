/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_xint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnguyen- <cnguyen-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 02:23:42 by cnguyen-          #+#    #+#             */
/*   Updated: 2024/04/20 03:08:24 by cnguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_xint(t_formatspec specs, va_list *args)
{
	int					n_chars;
	unsigned long int	arg;
	int					arg_len;
	int					n_zeros;

	n_chars = 0;
	fetch_next_args(&specs, args);
	arg = (unsigned long int)va_arg(*args, unsigned int);
	arg_len = ft_uintlen(arg, 16);
	if (arg == 0 && specs.precision == 0)
		arg_len = 0;
	n_zeros = 0;
	if (specs.precision > -1 && arg_len < specs.precision)
		n_zeros = specs.precision - arg_len;
	if (!specs.dash && !specs.zero)
	{
		while (specs.width - arg_len - n_zeros - 2 * specs.hash * (arg > 0) > n_chars)
			n_chars += ft_putchar(' ');
	}
	if (specs.hash && arg != 0)
		n_chars += ft_putchar('0') + ft_putchar(specs.specifier);
	while ((specs.zero && specs.width - arg_len > n_chars) || n_zeros--)
		n_chars += ft_putchar('0');
	if (arg != 0 || specs.precision != 0)
		n_chars += ft_putuint(arg, specs.specifier);
	while (specs.dash == 1 && specs.width - n_chars > 0)
		n_chars += ft_putchar(' ');
	return (n_chars);
}