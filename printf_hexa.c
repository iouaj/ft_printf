/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouajjou <iouajjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:24:00 by iouajjou          #+#    #+#             */
/*   Updated: 2023/11/17 12:17:29 by iouajjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	int_to_hexa(unsigned int nb, char *base, int len)
{
	int	last;

	last = 0;
	if (nb / 16)
		last = int_to_hexa(nb / 16, base, len++);
	ft_putchar_fd(base[nb % 16], 1);
	return (len + last);
}

static int	int_to_hexa_ptr(long unsigned int nb, char *base, int len)
{
	int	last;

	last = 0;
	if (nb / 16)
		last = int_to_hexa_ptr(nb / 16, base, len++);
	ft_putchar_fd(base[nb % 16], 1);
	return (len + last);
}

int	printptr(va_list *ap)
{
	void	*ptr;

	ptr = va_arg(*ap, void *);
	if (!ptr)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	return (int_to_hexa_ptr((long unsigned int)ptr, "0123456789abcdef", 0) + 3);
}

int	printhexalo(va_list *ap, char *base)
{
	int		nb;

	nb = va_arg(*ap, int);
	return (int_to_hexa(nb, base, 0) + 1);
}
