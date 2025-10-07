/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 13:28:19 by ludebarn          #+#    #+#             */
/*   Updated: 2025/10/07 15:22:10 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (f)(void *))
{
	t_list	*temp;

	temp = lst;
	if (!lst || !f)
		return ;
	while (temp != NULL)
	{
		f(temp->content);
		temp = temp->next;
	}
}
// void	to_upper(void *content)
// {
// 	char *s = (char *)content;
// 	while (*s)
// 	{
// 		if (*s >= 'a' && *s <= 'z')
// 			*s -= 32;
// 		s++;
// 	}
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
// 	ft_lstiter(header, to_upper);
// 	printf("%s", (char *)header->content);
// 	printf("%s", (char *)header->next->content);
// 	printf("%s", (char *)header->next->next->content);
// }
