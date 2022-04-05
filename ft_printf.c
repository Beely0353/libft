/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:43:48 by baroun            #+#    #+#             */
/*   Updated: 2022/04/05 10:34:19 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_arg(const char flag)
{
	return (ft_strchr("cspdiuxX%", flag) != 0);
}

static int	ft_arg(const char s, va_list ap, int len)
{
	if (s == '%')
		len += ftprintf_putchar(s);
	if (s == 'c')
		len += ftprintf_putchar(va_arg(ap, int));
	else if (s == 's')
		len += ftprintf_putstr(va_arg(ap, char *));
	else if (s == 'p')
		len += ftprintf_putptr(va_arg(ap, void *));
	else if (s == 'd')
		len += ftprintf_putnbr(va_arg(ap, int));
	else if (s == 'i')
		len += ftprintf_putnbr(va_arg(ap, int));
	else if (s == 'u')
		len += ftprintf_putunbr(va_arg(ap, unsigned int));
	else if (s == 'x')
		len += ftprintf_putunbr_base(va_arg(ap, unsigned int), "0123456789abcdef");
	else if (s == 'X')
		len += ftprintf_putunbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF");
	return (len);
}

static int	ftprintf_argnbr(const char *s, va_list ap)
{
	int	len;

	len = 0;
	while (*s)
	{
		if (*s == '%' && ftprintf_is_arg(*(s + 1)))
		{
			s++;
			len = ft_arg(*s, ap, len);
		}
		else
		{
			ftprintf_putchar(*s);
			len ++;
		}
		s++;
	}
	return (len);
}

int	ft_printf(const char *s, ...)
{
	int		len;
	va_list	ap;

	va_start(ap, s);
	len = ftprintf_argnbr(s, ap);
	va_end(ap);
	return (len);
}
