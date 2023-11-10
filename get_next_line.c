/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:27:15 by dabae             #+#    #+#             */
/*   Updated: 2023/11/10 11:27:46 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static  void	extract_rest(t_list *buf_list, char **rest)
{
        int     i;
        int     j;

        while (buf_list->next)
                buf_list = buf_list->next;
        i = 0;
        while (buf_list->str_tmp[i] && buf_list->str_tmp[i] != '\n')
                i++;
        i++;
        j = 0;
        while (buf_list->str_tmp[i + j])
                j++;
        *rest = malloc(sizeof(char) * (j + 1));
        if (!*rest)
                return ;
        (*rest)[j] = '\0';
        while (j >= 0)
        {
                (*rest)[j] = buf_list->str_tmp[i + j];
                j--;
        }
}

static  void    retrieve_line(t_list *buf_list, char **line)
{
        int     i;
        int     j;

        *line = (char *)malloc(sizeof(char) * (line_len(buf_list) + 1));
        if (!*line)
                return ;
        j = 0;
        while (buf_list && j < line_len(buf_list))
        {
                i = 0;
                while (buf_list->str_tmp[i] != '\n')
                {
                        (*line)[j] = buf_list->str_tmp[i];
                        i++;
                        j++;
                }
                buf_list = buf_list->next;
        }
        (*line)[j] = '\0';
}

static	int	found_n(t_list *buf_list)
{
	int	i;

	j = 0;
	while (buf_list)
	{
		i = 0;
		while (buf_list->str_tmp[i] && i < BUFFER_SIZE)
		{
			if (buf_list->str_tmp[i] == '\n')
				return (1);
			i++;
		}
		buf_list = buf_list->next;
	}
	return (0);
}
static	void	create_list(t_list **buf_list, int fd)
{
	char    *buffer;
        int     bytes_read;

	while (!found_n(*buf_list))
	{
		buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
        	if (!buffer)
		{
			free_list(*buf_list);
                	return ;
		}
        	bytes_read = read(fd, buffer, BUFFER_SIZE);
        	if (!bytes_read)
		{
			free(buffer);
			buffer = malloc(sizeof(char));
			if (!buffer)
			{
				free_list(*buf_list);
				return ;
			}
			buffer[0] = '\n';
			add_node(buf_list, buffer;
                	return ;
		}
		buffer[bytes_read] = '\0';
		add_node(buf_list, buffer);
	}
}
char	*get_next_line(int fd)
{
	static	t_list	*buf_list;
	char	*line;
	char	*rest;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	create_list(&buf_list, fd);
	line = NULL;
	line = retreive_line(buf_list, &line);
	rest = NULL;
	extract_rest(buf_list, &rest);
	if (rest && buf_list)
	{
		empty_attach_node(&buf_list, rest);
		free(rest);
	}
	return (line);
}
