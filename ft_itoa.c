/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:08:45 by ludebarn          #+#    #+#             */
/*   Updated: 2025/10/07 14:16:55 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_countlen(int long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		signe;
	long	count;
	long	nb;

	signe = 0;
	nb = n;
	if (nb < 0)
	{
		nb *= -1;
		signe++;
	}
	count = ft_countlen(nb) + signe;
	str = malloc(sizeof(char) * count + 1);
	if (!str)
		return (NULL);
	str[count] = '\0';
	while (--count >= 0)
	{
		str[count] = (nb % 10) + '0';
		nb /= 10;
	}
	if (signe)
		str[0] = '-';
	return (str);
}
// int	main(void)
// {
// 	printf("%s\n", ft_itoa(-2147483647 -1));
// }
