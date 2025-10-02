/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 18:40:19 by ludebarn          #+#    #+#             */
/*   Updated: 2025/10/02 19:00:49 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = *lst;
	temp->content = new;
	new = temp;
}

int	main(void)
{
	t_list *node1 = ft_lstnew("789");
	t_list *node2 = ft_lstnew("456");
	t_list *header = ft_lstnew("123");
	ft_lstadd_front(&header, node1);
	ft_lstadd_front(&header, node2);
	printf("%s\n", (char *)header->content);
}
