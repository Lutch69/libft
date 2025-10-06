/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 15:55:32 by ludebarn          #+#    #+#             */
/*   Updated: 2025/10/03 16:27:52 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	int		i;
	t_list	*temp;

	temp = *lst;
	i = ft_lstsize(temp);
	while (i > 0)
	{
		del(temp->content);
		i--;
	}
}

void	*ft_free(void *content)
{
	if (content)
		free(content);
	return (NULL);
}

int	main(void)
{
	t_list	*node1;
	t_list	*node2;
	t_list	*header;

	node1 = ft_lstnew(ft_strdup("1,2,3,"));
	node2 = ft_lstnew(ft_strdup("4,5,6,"));
	header = ft_lstnew(ft_strdup("7,8,9,"));
	ft_lstadd_front(&header, node2);
	ft_lstadd_front(&header, node1);
	ft_lstclear(&header, ft_free((unsigned char *)header->content));
}
