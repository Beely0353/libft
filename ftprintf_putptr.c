/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftprintf_putptr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baroun <baroun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:32:38 by baroun            #+#    #+#             */
/*   Updated: 2022/04/05 10:40:59 by baroun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ftprintf_putptr(void *ptr)
{
	int				count;
	unsigned long	a;

	a = (unsigned long) ptr;
	count = ftprintf_putstr("0x");
	count += ftprintf_putunbr_base(a, "0123456789abcdef");
	return (count);
}
