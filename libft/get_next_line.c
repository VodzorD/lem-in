/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscallop <wscallop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 20:27:58 by wscallop          #+#    #+#             */
/*   Updated: 2020/11/24 14:40:47 by wscallop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_element		*create(int fd)
{
	t_element *element;

	element = NULL;
	element = (t_element*)malloc(sizeof(t_element));
	if (element)
	{
		element->fd = fd;
		element->buf = NULL;
		element->next = NULL;
	}
	return (element);
}

t_element		*get_element(t_element **begin, int fd)
{
	t_element *temp;

	if (*begin && begin)
	{
		temp = *begin;
		while (temp)
		{
			if (temp->fd == fd)
				return (temp);
			if (temp->next == NULL)
			{
				temp->next = create(fd);
				return (temp->next);
			}
			temp = temp->next;
		}
		temp = create(fd);
		return (temp);
	}
	*begin = create(fd);
	return (*begin);
}

int				readfile(t_element *element)
{
	char	buf[BUFF_SIZE + 1];
	char	*temp;
	int		position;
	int		ret;

	ret = 1;
	position = -1;
	while (position < 0 && ret > 0)
	{
		if (element->buf == NULL)
			element->buf = ft_strnew(0);
		position = ft_char_position(element->buf, '\n');
		if (position == -1)
		{
			ret = read(element->fd, buf, BUFF_SIZE);
			if (ret == -1)
				return (-2);
			buf[ret] = '\0';
			temp = element->buf;
			element->buf = ft_strjoin(element->buf, buf);
			ft_strdel(&temp);
		}
	}
	return (position);
}

int				setline(t_element *element, char **line, int position)
{
	char *temp;

	if (position == -2)
		return (-1);
	if (position == -1)
	{
		*line = ft_strdup(element->buf);
		ft_strdel(&(element->buf));
		return (ft_strlen(*line) > 0);
	}
	else
	{
		temp = element->buf;
		*line = ft_strsub(element->buf, 0, position);
		element->buf = ft_strsub(element->buf, position + 1,
		ft_strlen(element->buf + position + 1));
		ft_strdel(&temp);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_element	*begin;
	t_element			*element;

	if (fd < 0 || fd == 1 || fd == 2 || line == NULL)
		return (-1);
	element = get_element(&begin, fd);
	return (setline(element, line, readfile(element)));
}
