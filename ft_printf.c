/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 22:55:22 by ludebarn          #+#    #+#             */
/*   Updated: 2025/12/12 17:05:13 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_checkformat_printf(const char c, va_list *param)
{
	char	*ifint;
	int		count;

	count = 0;
	ifint = "diuxX";
	if (c == '%')
		count += ft_putchar_printf('%');
	else if (c == 'c')
		count += ft_putchar_printf(va_arg(*param, int));
	else if (c == 's')
		count += ft_putstr_printf(va_arg(*param, char *));
	else if (c == 'p')
		count += ft_putnbr_base_printf("0123456789abcdef",
				(unsigned long)va_arg(*param, void *), 16, c);
	else if (c == 'f')
		count += get_float_printf(0, param);
	else if (ft_strchr_printf(ifint, c))
		count += ft_putdigit_printf(c, param);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	va_list	param;
	int		count;

	i = 0;
	count = 0;
	va_start (param, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == '.')
			{
				i++;
				count += get_float_printf(str[i], &param);
			}
			else
				ft_checkformat_printf(str[i], &param);
		}
		else
			count += ft_putchar_printf(str[i]);
		i++;
	}
	va_end(param);
	return (count);
}
int	main(void)
{
	ft_printf("%.2f", -15.6666);
}
