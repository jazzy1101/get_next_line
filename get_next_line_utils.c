/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:23:27 by dabae             #+#    #+#             */
/*   Updated: 2023/11/07 15:31:32 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	line_len(t_list *buf_list)
{
	int     i;
        int     j;

	while (buf_list)
        {
                i = 0;
                while (buf_list->str_tmp[i] && i < BUFFER_SIZE)
                {
                        if (buf_list->str_tmp[i] == '\n')
                                return (j);
                        j++;
                        i++;
                }
                buf_list = buf_list->next;
        }
}

char	*ft_strdup(const char *s)
{
	char	*arr;
	int		i;

	arr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		arr[i] = s[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	
