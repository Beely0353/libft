/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf_putstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 14:53:55 by baroun            #+#    #+#             */
/*   Updated: 2022/04/05 10:37:31 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ftprintf_putstr(char *s)
{
	int	i;

	i = 0;
	if (s != NULL)
		while (s[i])
			write(1, &s[i++], 1);
	else
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	return (i);
}
