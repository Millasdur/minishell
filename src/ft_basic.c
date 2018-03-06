/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_basic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 15:01:32 by hlely             #+#    #+#             */
/*   Updated: 2017/12/10 10:27:08 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_space(char ***tabl, char ***envt)
{
	if (!(*envt))
	{
		ft_puterr("PATH is not initialised\n");
		ft_del_tab_envt(tabl, envt);
		return (0);
	}
	return (1);
}

void	ft_del_tab_envt(char ***tabl, char ***envt)
{
	ft_strdeltab(tabl);
	ft_strdeltab(envt);
}

char	**ft_clear_shell(char **av, char **environ)
{
	pid_t	father;
	char	**env;
	char	*usr;

	env = ft_cpyenv(environ);
	father = fork();
	if (father)
		wait(0);
	else
		execve("/usr/bin/clear", av, env);
	ft_putstr("Welcome ");
	usr = ft_getenv(env, "USER");
	ft_putstr(usr);
	ft_putstr(" !\n");
	return (env);
}

void	ft_strdeltab(char ***tabl)
{
	int		i;

	i = 0;
	while ((*tabl) && (*tabl)[i])
	{
		ft_strdel(&((*tabl)[i]));
		i++;
	}
	if (*tabl)
		free(*tabl);
	*tabl = NULL;
}
