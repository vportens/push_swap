/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viporten <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/15 22:55:06 by viporten          #+#    #+#             */
/*   Updated: 2021/06/04 19:42:27 by laclide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libft.h"
#include "push_swap.h"

int		ft_strchr_gnl(char *str, int found)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == found)
			return (i + 1);
		i++;
	}
	return (0);
}

char	*ft_strjoin_gnl(char **s1, char *s2)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while ((*s1)[i])
		i++;
	while (s2[j])
		j++;
	if ((ret = malloc(sizeof(char) * (i + j + 1))) == NULL)
		return (NULL);
	ret[i + j] = '\0';
	while (j-- > 0)
		ret[i + j] = s2[j];
	while (i-- > 0)
		ret[i] = (*s1)[i];
	free(*s1);
	return (ret);
}

char	*ft_strdup_gnl(char *str, int len)
{
	char	*new;
	int		i;

	i = 0;
	if ((new = malloc(sizeof(char) * (len + 1))) == NULL)
		return (NULL);
	while (i < len)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_substr_gnl(char *str, int start)
{
	char	*new;
	int		i;

	i = 0;
	while (str[start + i])
		i++;
	if ((new = malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	i = 0;
	while (str[start + i])
	{
		new[i] = str[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_calloc_gnl(void)
{
	char	*new;

	if ((new = malloc(1)) == NULL)
		return (NULL);
	new[0] = 0;
	return (new);
}
