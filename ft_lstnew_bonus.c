/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:40:03 by ludebarn          #+#    #+#             */
/*   Updated: 2025/10/02 18:45:27 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *res;
	res = malloc(sizeof(t_list));
	res->content = content;
	res->next = NULL;
	return(res);
}

// int	main(void)
// {
// 	t_list *node1;
// 	node1 = ft_lstnew("abc");
// 	printf("%s\n", (char *)node1->content);
// }
