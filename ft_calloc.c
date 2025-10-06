/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 12:04:06 by lucasdebarn       #+#    #+#             */
/*   Updated: 2025/10/06 08:35:06 by lucasdebarn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	ptr = malloc(size * count);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, (count * size));
	return (ptr);
}
// int main(void)
// {
// 	size_t i = 0;
// 	void *str = ft_calloc(30, 1);
// 	while(i < 30)
// 	{
// 		if(((char *)str)[i])
// 			write(1, "X", 1);
// 		i++;
// 	}
// 	free(str);
// }
