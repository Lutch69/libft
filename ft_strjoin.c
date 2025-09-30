/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucasdebarnot <lucasdebarnot@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 10:26:34 by lucasdebarn       #+#    #+#             */
/*   Updated: 2025/09/30 11:17:19 by lucasdebarn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *newstr;
	size_t len1;
	size_t len2;
	size_t i;

	i = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	newstr = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!newstr)
		return(NULL);
	while (i < len1)
	{
		newstr[i] = s1[i];
		i++;
	}
	ft_strlcat(newstr, s2, len1 + len2 + 1);
	return(newstr);
}
// int main(void)
// {
// 	printf("%s\n", ft_strjoin("",""));
// }
