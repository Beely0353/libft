/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf_putunbr_base.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:30:46 by baroun            #+#    #+#             */
/*   Updated: 2022/04/05 10:38:53 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_base_len(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (ft_isspace(base[i]))
			return (0);
		j = i + 1;
		while (base[j])
			if (base[i] == base[j++])
				return (0);
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

static void	ft_putunbr_recursive(unsigned long nbr, char *base)
{
	int		base_size;
	int		i;

	i = 1;
	if (nbr < 16)
		i = 0;
	base_size = ft_strlen(base);
	if (nbr > 0)
	{
		ft_putunbr_recursive(nbr / base_size, base);
		ft_putchar_fd(base[nbr % base_size], 1);
	}
}

int	count(unsigned long nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (3);
	while (nbr)
	{
		nbr /= 16;
		i++;
	}
	return (i);
}

int	ftprintf_putunbr_base(unsigned long nbr, char *base)
{
	int		base_size;
	int		i;

	base_size = ft_base_len(base);
	if (base_size)
	{
		if (nbr == 0)
		{
			ft_putchar_fd(base[0], 1);
			return (1);
		}
		else
			ft_putunbr_recursive(nbr, base);
	}
	i = count(nbr);
	return (i);
}
