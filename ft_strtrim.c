/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 11:21:12 by lucasdebarn       #+#    #+#             */
/*   Updated: 2025/09/30 16:55:27 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
    size_t start;
    size_t end;
    char *newstr;

    start = 0;
    end = ft_strlen(s1) - 1;
    if(!s1 || !set)
        return(NULL);
    while(s1[start] && ft_strchr(set, s1[start]))
        start++;
    while(end > start && ft_strrchr(set, s1[end]))
        end--;
    newstr = ft_substr(s1, start, (end - start) + 1);
    return(newstr);
}
int main(void)
{
    printf("%s\n", ft_strtrim("ABbonjourAB", "AB"));
}
