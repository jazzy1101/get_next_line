/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabae <dabae@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 10:23:50 by dabae             #+#    #+#             */
/*   Updated: 2023/11/10 15:09:01 by dabae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_list
{
	char	*str_tmp;
	struct s_list		*next;
}			t_list;

char	*get_next_line(int fd);

int	line_len(t_list *buf_list);

void	empty_attach_node(t_list **buf_list, char *rest);

void	add_node(t_list **buf_list, char *buffer);

void	copy_rest(t_list *last_node, char **rest);

void	free_list(t_list *buf_list);

#endif
