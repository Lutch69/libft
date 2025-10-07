/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 13:27:38 by ludebarn          #+#    #+#             */
/*   Updated: 2025/10/07 15:27:02 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_node;
	t_list	*mylist;
	t_list	*temp;

	mylist = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		temp = f(lst->content);
		new_node = NULL;
		if (temp)
			new_node = ft_lstnew(temp);
		if (!temp || !new_node)
		{
			if (temp && !new_node)
				del(temp);
			ft_lstclear(&mylist, del);
			return (NULL);
		}
		ft_lstadd_back(&mylist, new_node);
		lst = lst->next;
	}
	return (mylist);
}

// void	ft_free(void *content)
// {
// 	if (content)
// 		free(content);
// }

// void	*to_upper(void *content)
// {
// 	char *s = (char *)content;
// 	while (*s)
// 	{
// 		if (*s >= 'a' && *s <= 'z')
// 			*s -= 32;
// 		s++;
// 	}
// 	return(content);
// }

// int	main(void)
// {
// 	t_list	*node1;
// 	t_list	*node2;
// 	t_list	*header;

// 	node1 = ft_lstnew(ft_strdup("abc"));
// 	node2 = ft_lstnew(ft_strdup("def"));
// 	header = ft_lstnew(ft_strdup("ijk"));
// 	ft_lstadd_front(&header, node2);
// 	ft_lstadd_front(&header, node1);
// 	ft_lstmap(header, to_upper, ft_free);
// 	printf("%s", (char *)header->content);
// 	printf("%s", (char *)header->next->content);
// 	printf("%s", (char *)header->next->next->content);
// }
