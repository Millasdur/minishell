/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 16:37:04 by hlely             #+#    #+#             */
/*   Updated: 2017/12/05 08:50:57 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	if (s)
	{
		i = 0;
		if ((res = ft_strnew(len)))
		{
			while (i < len)
			{
				res[i] = s[start + i];
				i++;
			}
			return (res);
		}
	}
	return (NULL);
}

char	*ft_strsubdel(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*res;

	if (s)
	{
		i = 0;
		if ((res = ft_strnew(len)))
		{
			while (i < len)
			{
				res[i] = s[start + i];
				i++;
			}
			ft_strdel(&s);
			return (res);
		}
	}
	return (NULL);
}
