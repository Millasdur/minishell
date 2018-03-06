/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:58:09 by hlely             #+#    #+#             */
/*   Updated: 2017/12/08 18:27:05 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_put_path(char **env)
{
	char	*buf;
	char	*tmp;
	char	*home;

	buf = ft_strnew(200);
	tmp = buf;
	buf = getcwd(buf, 200);
	if (!buf)
	{
		ft_strdel(&tmp);
		ft_puterr("Problem with current path, setting path to HOME\n");
		if (!(home = ft_getenv(env, "HOME")))
		{
			ft_puterr("HOME is not set, setting path to /Users\n");
			chdir("/Users");
		}
		else
			chdir(home);
		buf = getcwd(buf, 200);
	}
	ft_putcolor(buf, LIGHT_RED);
	ft_putcolor(" ✏ >", BROWN);
	ft_strdel(&buf);
}

void	ft_remove_quote(char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if ((line[i] == '"' && (i == 0 || i == ft_strlen(line) - 1)))
			i++;
		else
		{
			if (line[i] == '\\' && line[i + 1] == 'n')
			{
				ft_putchar('\n');
				i += 2;
			}
			ft_putchar(line[i]);
			i++;
		}
	}
}

void	ft_echo(char **line)
{
	int i;

	i = 1;
	if (!ft_strcmp(line[1], "-n"))
		i++;
	while (line[i])
	{
		ft_remove_quote(line[i]);
		if (line[i + 1])
			ft_putchar(' ');
		else if (!line[i + 1] && ft_strcmp(line[1], "-n"))
			ft_putchar('\n');
		i++;
	}
}
