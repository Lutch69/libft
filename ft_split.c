/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ludebarn <ludebarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:32:14 by ludebarn          #+#    #+#             */
/*   Updated: 2025/10/03 16:38:03 by ludebarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t ft_countword(char const *str, char c)
{
    size_t  i;
    size_t  word;

    i = 0;
    word = 0;
    while (str[i])
    {
        while(str[i] == c && str[i])
            i++;
        if (str[i] != c && str[i])
            word++;
        while (str[i] != c && str[i])
            i++;
    }
    return (word);
}

void    *ft_malloc_lines(char **newstr, const char *str, char c)
{
    size_t len;
    size_t  i;
    size_t word;

    word = 0;
    i = 0;
    len = 0;
    while (str[i])
    {
        len = 0;
        while (str[i] == c && str[i])
            i++;
        while (str[i] != c && str[i])
        {
            len++;
            i++;
        }
        if (len > 0)
        {
            newstr[word] = malloc(sizeof(char) * (len + 1));
            if (!newstr)
                return (NULL);
            word++;
        }
    }
    return (NULL);
}

void  *ft_copy_lines(char **newstr, const char *str, char c, size_t total_word)
{
    size_t i;
    size_t count_word;
    size_t count_char;

    count_char = 0;
    count_word = 0;

    i = 0;
    while (count_word < total_word)
    {
        count_char = 0;
        while (str[i] == c && str[i])
            i++;
        while (str[i] != c && str[i])
        {
            newstr[count_word][count_char] = str[i];
            i++;
            count_char++;
        }
        count_word++;
    }
    return (NULL);
}

char    **ft_split(const char*s1, char c)
{
    char    **newstr;
    size_t word;

    word = ft_countword(s1, c);
    newstr = malloc(sizeof(char *) * (word + 1));
    if (!newstr)
        return (NULL);
    newstr[word] = NULL;
    ft_malloc_lines(newstr, s1, c);
    ft_copy_lines(newstr, s1, c, word);
    return (newstr);
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
