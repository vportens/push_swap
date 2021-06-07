/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viporten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 17:57:16 by viporten          #+#    #+#             */
/*   Updated: 2021/06/04 19:42:28 by laclide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include "push_swap.h"

int		get_line(char **line, char **str)
{
	int		i;
	char	*tmp;

	i = ft_strchr_gnl(*str, '\n');
	if (i == 0 && *str)
	{
		while ((*str)[i])
			i++;
		if (((tmp = ft_strdup_gnl(*str, i)) == NULL))
			return (-1);
		free(*str);
		*str = NULL;
		*line = tmp;
		return (0);
	}
	if ((tmp = ft_strdup_gnl(*str, i - 1)) == NULL)
		return (-1);
	*line = tmp;
	if ((tmp = ft_substr_gnl(*str, i)) == NULL)
		return (-1);
	if (*str)
		free(*str);
	*str = tmp;
	return (1);
}

int		get_next_line(int fd, char **line)
{
	int			res;
	char		buf[BUFFER_SIZE + 1];
	static char	*w[OPEN_MAX];
	char		*tmp;

	if (fd < 0 || fd > OPEN_MAX || line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	if (w[fd] == NULL)
		if ((w[fd] = ft_calloc_gnl()) == NULL)
			return (-1);
	if (ft_strchr_gnl(w[fd], '\n'))
		return (get_line(line, &w[fd]));
	while ((res = read(fd, buf, BUFFER_SIZE)) >= 0)
	{
		buf[res] = '\0';
		if ((tmp = ft_strjoin_gnl(&w[fd], buf)) == NULL)
			return (-1);
		w[fd] = tmp;
		if (ft_strchr_gnl(buf, '\n') || res == 0)
			break ;
	}
	if (res < 0)
		return (-1);
	return (get_line(line, &w[fd]));
}
