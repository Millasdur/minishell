/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 11:30:19 by hlely             #+#    #+#             */
/*   Updated: 2017/12/08 15:48:56 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getenv(char **env, char *elem)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strstr(env[i], elem))
			return (ft_strchr(env[i], '=') + 1);
		i++;
	}
	return (NULL);
}

char	**ft_cpyenv(char **environ)
{
	char	**tabl;
	int		i;

	i = 0;
	if (!(tabl = (char**)malloc(sizeof(char*) * ft_nb_word(environ) + 1)))
		return (NULL);
	while (environ[i])
	{
		tabl[i] = ft_strdup(environ[i]);
		i++;
	}
	tabl[i] = NULL;
	return (tabl);
}

void	ft_print_env(char **env)
{
	int i;

	i = 0;
	while (env[i])
	{
		ft_putendl(env[i]);
		i++;
	}
}

void	ft_setenv(char ***env, char *elem, char *value)
{
	int		i;
	char	*line;
	char	*tmp;

	if (!elem || !value)
		return ;
	tmp = ft_strjoin(elem, "=");
	i = 0;
	ft_touppercase(tmp, elem);
	line = ft_strjoin(tmp, value);
	while ((*env)[i])
	{
		if ((*env)[i][0] == tmp[0] && ft_strstr((*env)[i], tmp))
		{
			ft_strdel(&((*env)[i]));
			ft_strdel(&tmp);
			(*env)[i] = line;
			return ;
		}
		i++;
	}
	ft_strdel(&tmp);
	*env = ft_realloc(*env, (sizeof(char*) * (ft_nb_word(*env)
					+ 1)), (sizeof(char*) * (ft_nb_word(*env) + 2)));
	(*env)[i] = line;
}

void	ft_unsetenv(char ***env, char *elem)
{
	int		i;
	char	*tmp;

	if (!elem)
	{
		ft_puterr("usage: unsetenv [elem]\n");
		return ;
	}
	i = 0;
	tmp = ft_strjoin(elem, "=");
	ft_touppercase(tmp, elem);
	while ((*env)[i])
	{
		if ((*env)[i][0] == tmp[0] && ft_strstr((*env)[i], tmp))
		{
			ft_swapstr(&(*env)[i], &(*env)[ft_nb_word(*env) - 1]);
			ft_strdel(&(*env)[ft_nb_word(*env) - 1]);
			*env = ft_realloc(*env, (sizeof(char*) * (ft_nb_word(*env)
							+ 1)), (sizeof(char*) * (ft_nb_word(*env) + 1)));
			ft_strdel(&tmp);
			return ;
		}
		i++;
	}
	ft_strdel(&tmp);
}
