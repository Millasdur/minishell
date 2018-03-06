/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:44:37 by hlely             #+#    #+#             */
/*   Updated: 2017/12/09 17:07:06 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cd(char *path, char ***env)
{
	char	*buf;
	char	*tmp;

	buf = ft_strnew(200);
	if (!path)
		path = ft_getenv(*env, "HOME");
	else if (!ft_strcmp(path, "-"))
	{
		if ((tmp = ft_getenv(*env, "OLD_DIR")))
			path = tmp;
		else
			path = ft_getenv(*env, "HOME");
	}
	ft_setenv(env, "OLD_DIR", getcwd(buf, 200));
	if (chdir(path) == -1)
	{
		buf = getcwd(buf, 200);
		buf = ft_strjoindel(buf, path);
		if (chdir(buf) == -1)
		{
			ft_puterr("cd: no such file or directory: ");
			ft_puterrnl(path);
		}
	}
	ft_strdel(&buf);
}
