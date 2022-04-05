/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf_putunbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:30:28 by baroun            #+#    #+#             */
/*   Updated: 2022/04/05 10:40:27 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lenunbr(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

int	ftprintf_putunbr(unsigned int n)
{
	int				i;

	i = ft_lenunbr(n);
	if (n == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	if (n > 9)
	{
		ftprintf_putunbr(n / 10);
		n %= 10;
	}
	ft_putchar_fd(n + '0', 1);
	return (i);
}
