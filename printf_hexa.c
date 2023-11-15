/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouajjou <iouajjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:24:00 by iouajjou          #+#    #+#             */
/*   Updated: 2023/11/15 18:09:47 by iouajjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	int_to_hexa(long unsigned int nb, char *base)
{
	if (nb / 16)
		int_to_hexa(nb / 16, base);
	ft_putchar_fd(base[nb % 16], 1);
}

static size_t	lenhexa(int nb)
{
	size_t	i;

	i = 0;
	while (nb / 16)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}

int	printptr(va_list *ap)
{
	void	*ptr;

	ptr = va_arg(*ap, void *);
	ft_putstr_fd("0x", 1);
	int_to_hexa((unsigned long)ptr, "0123456789abcdef");
	return (lenhexa((long unsigned)ptr));
}

int	printhexalo(va_list *ap, char *base)
{
	int		nb;

	nb = va_arg(*ap, int);
	int_to_hexa(nb, base);
	return (lenhexa(nb));
}
