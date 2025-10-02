/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:08:45 by ludebarn          #+#    #+#             */
/*   Updated: 2025/10/01 14:45:39 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countlen(int long n)
{
	int len;

	len = 1;
	if (n == 0)
		return(1);
	while(n > 0)
	{
		n /= 10;
		len++;
	}
	return(len);
}

int ft_isneg(int n)
{
	if (n >= 0)
		return(1);
	else
		return (0);
}

char	*ft_itoa(int n)
{
	char *str;
	int signe;
	int long count;
	int long nb;

	signe = 0;
	nb = n;
	if (!ft_isneg(n))
	{
		nb *= -1;
		signe++;
	}
	count = ft_countlen(nb);
	str = malloc(sizeof(char) * count + signe + 1);
	if (!str)
		return(NULL);
	str[count] = '\0';
	while (count-- >= 0)
	{
		str[count] = (nb % 10) + '0';
		nb /= 10;
	}
	if (signe)
		str[0] = '-';
	return(str);
}
/*int	main(void)
{
	printf("%s\n", ft_itoa(-2147483648));
}*/
