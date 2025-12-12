/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 14:29:49 by ludebarn          #+#    #+#             */
/*   Updated: 2025/12/12 16:16:37 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_fnbr(double fnb)
{
	int	count;

	count = 0;
	while(1)
	{
		fnb *= 10;
		count++;
		if (((int)fnb % 10) == 0)
			break;
	}
	return(count);
}
static int	get_inbr(int inb)
{
	int	count;

	count = 0;
	if (inb < 0)
	{
		inb *= -1;
		count++;
	}
	while (inb > 0)
	{
		inb /= 10;
		count++;
	}
	return (count);
}

int	get_float_printf(char c, va_list *param)
{
	int	count;
	int	nb;

	count = get_inbr(va_arg(*param, int));
	if (ft_isdigit(c) > 0)
	{
		nb = c + '0';
		ft_ftoa(va_arg(*param, double), nb);

	}
	else if (c == 'f')
	{
		nb = get_fnbr(va_arg(*param, double));
		ft_ftoa (va_arg(*param, double), nb);
	}
	return (nb + count);
}
