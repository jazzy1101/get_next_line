/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:22:46 by dabae             #+#    #+#             */
/*   Updated: 2023/11/07 15:31:26 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

static	char	*retrieve_line(t_list *buf_list)
{
	char	*line;
	
	line = (char *)malloc(sizeof(char) * (line_len(buf_list) + 1));
	if (!line)
		return (NULL);


}
static	void	add_node(t_list **buf_list, char *buffer)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	while (!buf_list->next)
		buf_list = buf_list->next;
	if (!buf_list)
                buf_list = new;
	buf_list->next = new;
	new->next = NULL;
	new->str_tmp = buffer;
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
                	return ;
        	bytes_read = read(fd, buffer, BUFFER_SIZE);
        	if (!bytes_read)
		{
			free(buffer);
			buffer[0] = '\n';
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

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	create_list(buf_list, buffer);
	line = create_line();
	return (line);
}
