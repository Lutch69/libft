/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 10:18:15 by lucasdebarn       #+#    #+#             */
/*   Updated: 2025/10/07 16:00:49 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*realdst;
	const unsigned char	*realsrc;

	i = 0;
	if ((!dst && !src) || dst == src || n == 0)
		return (dst);
	realdst = (unsigned char *)dst;
	realsrc = (const unsigned char *)src;
	if (realdst < realsrc)
	{
		i = 0;
		while (i < n)
		{
			realdst[i] = realsrc[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i-- > 0)
			realdst[i] = realsrc[i];
	}
	return (dst);
}
// int main(void)
// {
// 	char buf[8] = "abcdef";
// 	ft_memmove(buf, buf+3, 3);
// 	printf("%s", buf);
// }
