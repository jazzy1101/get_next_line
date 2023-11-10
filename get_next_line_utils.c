/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:23:27 by dabae             #+#    #+#             */
/*   Updated: 2023/11/10 15:26:00 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	line_len(t_list *buf_list)
{
	int	i;
	int	j;

	j = 0;
	while (buf_list)
	{
		i = 0;
		while (buf_list->str_tmp[i] && i < BUFFER_SIZE)
		{
			if (buf_list->str_tmp[i] == '\n')
				return (j);
			i++;
			j++;
		}
		buf_list = buf_list->next;
	}
	return -1;
}

void	empty_attach_node(t_list **buf_list, char *rest)
{
	t_list	*tmp;

	if (*buf_list)
	{
		while ((*buf_list)->next)
		{
			tmp = (*buf_list)->next;
			free((*buf_list)->str_tmp);
			free(*buf_list);
			*buf_list = tmp;
		}
		free((*buf_list)->str_tmp);
		free(*buf_list);
		*buf_list = NULL;
	}
	else
	{
		*buf_list = malloc(sizeof(t_list));
		if (*buf_list)
		{
			(*buf_list)->str_tmp = rest;
			(*buf_list)->next = NULL;
		}
		else
			free(rest);
	}
}

void	add_node(t_list **buf_list, char *buffer)
{
	t_list	*new;
	t_list	*tmp;

	new = malloc(sizeof(t_list));
	if (!new)
	{
		free(buffer);
		return ;
	}
	new->str_tmp = buffer;
	new->next = NULL;
	if (*buf_list)
	{
		tmp = *buf_list;	
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*buf_list = new;
}

void	copy_rest(t_list *last_node, char **rest)
{
	int	i;
	int	rest_len;

	if (!last_node)
		return ;
	i = 0;
	while (last_node->str_tmp[i] && last_node->str_tmp[i] != '\n')
		i++;
	if (last_node->str_tmp[i] != '\n')
		return ;
	rest_len = 0;
	while (last_node->str_tmp[i + rest_len + 1])
		rest_len++;
	*rest = malloc(sizeof(char) * (rest_len + 1));
	if (!*rest)
		return ;
	(*rest)[rest_len] = '\0';
	while (rest_len >= 0)
	{
		(*rest)[rest_len] = last_node->str_tmp[i + rest_len + 1];
		rest_len--;
	}
}

void	free_list(t_list *buf_list)
{
	t_list	*tmp;

	while (buf_list)
	{
		tmp = buf_list;
		buf_list = buf_list->next;
		free(tmp->str_tmp);
		free(tmp);
	}
}
