/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf_putnbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:22:12 by baroun            #+#    #+#             */
/*   Updated: 2022/04/05 10:36:19 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lennbr(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

int	ftprintf_putnbr(int n)
{
	unsigned int	s;
	int				i;

	i = ft_lennbr(n);
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		s = -n;
	}
	else
		s = n;
	if (s > 9)
	{
		ft_putnbr_fd(s / 10, 1);
		s %= 10;
	}
	ft_putchar_fd(s + '0', 1);
	return (i);
}
