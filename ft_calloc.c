/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 12:04:06 by lucasdebarn       #+#    #+#             */
/*   Updated: 2025/09/27 10:23:34 by lucasdebarn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*tab;

	if (size && count > SIZE_MAX / size)
		return (NULL);
	tab = malloc(size * count);
	if (!tab)
		return (NULL);
	ft_bzero(tab, (count * size));
	return (tab);
}
// int main(void)
// {
// 	size_t i = 0;
// 	void *p = ft_calloc(5, 3);
// 	while(i < 15)
// 	{
// 		if(((unsigned char *)p)[i])
// 			write(1, "X", 1);
// 		i++;
// 	}
// }
