/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iouajjou <iouajjou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 12:31:16 by iouajjou          #+#    #+#             */
/*   Updated: 2023/11/15 18:50:02 by iouajjou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

int	ft_printf(const char *format, ...);
//printf_nb
int	printint(va_list *ap);
int	printunsigned(va_list *ap);
//printf_hexa
int	printptr(va_list *ap);
int	printhexalo(va_list *ap, char *base);

#endif
