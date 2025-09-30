/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:32:14 by ludebarn          #+#    #+#             */
/*   Updated: 2025/09/30 18:22:17 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_issep(char const str, char c)
{
    if (str == c)
            return(1);
    return(0);
}

size_t ft_countword(char const *str, char c)
{
    size_t  i;
    size_t  word;

    i = 0;
    word = 0;
    while (str[i])
    {
        while(ft_issep(str[i], c) && str[i])
            i++;
        while (!(ft_issep(str[i], c)) && str[i])
        {
            if (ft_issep(str[i - 1], c))
                word++;
            i++;
        }
    }
    return (word);
}

void    ft_totallen(char **str, char const *s1, char c)
{
    size_t  len;
    size_t  i;
    size_t word;

    i = 0;
    len = 0;
    word = 0;
    while(str[word])
    {
        while(s1[i] && !ft_issep(s1[i], c))
        {
            if (ft_issep(s1[i], c) && s1[i - 1] != c)
                str[word] = malloc(sizeof(char) * len + 1);
                if (!newstr)
                    return(NULL);
            len++;
            i++;
        }
        word++;
    }
}
char    **ft_split(char const *s1, char c)
{
    char    **newstr;
    size_t word;

    word = ft_countword(s1, c);
    newstr = malloc(sizeof(char*) * word + 1);
    if (!newstr)
        return(NULL);
    newstr[word] = NULL;
    ft_totallen(newstr, s1, c);
    return(newstr);
}

int main(void)
{
    char **newstr;
    int i = 0;
    newstr = ft_split("Bonjour comment ca va ?", 32);
    while(newstr[i])
    {
        printf("%s\n", newstr[i]);
        i++;
    }
    free(newstr);
}
