/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouajjou <iouajjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:48:55 by iouajjou          #+#    #+#             */
/*   Updated: 2023/11/15 17:34:27 by iouajjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printchar(va_list *ap)
{
	char	c;

	c = va_arg(*ap, int);
	ft_putchar_fd(c, 1);
	return (1);
}

int	printstring(va_list *ap)
{
	char	*str;

	str = va_arg(*ap, char *);
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	printsimple(char c)
{
	if (ft_isdigit(c))
		ft_putnbr_fd(ft_toupper(c) - 48, 1);
	else
		ft_putchar_fd(c, 1);
	return (1);
}

static int	checkformat(const char *format, va_list *ap)
{
	if (format[1] == 'c')
		return (printchar(ap));
	if (format[1] == 's')
		return (printstring(ap));
	if (format[1] == 'p')
		return (printptr(ap));
	if (format[1] == 'd')
		return (printint(ap));
	if (format[1] == 'i')
		return (printint(ap));
	if (format[1] == 'u')
		return (printunsigned(ap));
	if (format[1] == 'x')
		return (printhexalo(ap, "0123456789abcdef"));
	if (format[1] == 'X')
		return (printhexalo(ap, "0123456789ABCDEF"));
	if (format[1] == '%')
		return ((printsimple('%')));
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	size_t	i;
	va_list	ap;
	int		len;

	i = 0;
	len = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			len += checkformat(format + i, &ap);
			i++;
		}
		else
			len += printsimple(format[i]);
		i++;
	}
	return (len);
}

// #include <stdio.h>
// #include <limits.h>

// int main(void)
// {
// 	char *str = "Test 12452 Yo";
// 	char c = 't';
// 	int nb = 2147483647;
// 	unsigned int nbu = 2147483660;
// 	int hexa = 42;
// }
