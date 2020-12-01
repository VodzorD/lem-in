/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wscallop <wscallop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 20:27:58 by wscallop          #+#    #+#             */
/*   Updated: 2020/12/01 16:01:25 by wscallop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*end(char *bf)
{
	int		ln;
	char	*str;

	ln = 0;
	while (bf[ln] != '\n' && bf[ln] != '\0')
		ln++;
	str = ft_strsub(bf, 0, ln);
	return (str);
}

static int			bffr(char *str, char **line)
{
	if (*str)
	{
		if (ft_strchr(str, '\n'))
		{
			*line = end(str);
			ft_strcpy(str, ft_strchr(str, '\n') + 1);
			return (1);
		}
		*line = ft_strdup(str);
	}
	else
		*line = ft_strdup("");
	return (0);
}

static int			chckend(char *vcs, char **line, char *str)
{
	char	*tmp;
	char	*tmp2;

	if (ft_strchr(vcs, '\n'))
	{
		if (!(tmp = end(vcs)))
			return (-1);
		tmp2 = *line;
		*line = ft_strjoin(tmp2, tmp);
		free(tmp2);
		free(tmp);
		ft_strcpy(str, ft_strchr(vcs, '\n') + 1);
		return (1);
	}
	else
	{
		tmp = *line;
		*line = ft_strjoin(tmp, vcs);
		free(tmp);
	}
	return (0);
}

int					get_next_line(const int fd, char **line)
{
	static char		str[BUFF_SIZE + 1];
	char			vcs[BUFF_SIZE + 1];
	int				i;

	if (!line || fd < 0)
		return (-1);
	i = bffr((char *)str, line);
	if (i)
		return (i);
	while ((i = read(fd, vcs, BUFF_SIZE)) > 0)
	{
		vcs[i] = '\0';
		if (chckend(vcs, line, str))
			return (1);
		if (i < BUFF_SIZE)
			return (1);
	}
	if (i < 0)
		return (-1);
	if (ft_strcmp(*line, "") != 0)
		return (1);
	return (0);
}
