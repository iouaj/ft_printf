/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_nb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouajjou <iouajjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:22:29 by iouajjou          #+#    #+#             */
/*   Updated: 2023/11/15 18:49:56 by iouajjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nblen(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		if (n == -2147483648)
		{
			n = 214748364;
			i++;
		}
		else
			n = -n;
		i++;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

void	ft_putunsigned(unsigned int n, int fd)
{
	if (n / 10)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + 48, fd);
}

int	printint(va_list *ap)
{
	int	nb;

	nb = va_arg(*ap, int);
	ft_putnbr_fd(nb, 1);
	return (nblen((long) nb));
}

int	printunsigned(va_list *ap)
{
	unsigned int	nb;

	nb = va_arg(*ap, unsigned int);
	ft_putunsigned(nb, 1);
	return (nblen(nb));
}
