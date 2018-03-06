/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 11:42:59 by hlely             #+#    #+#             */
/*   Updated: 2017/12/10 10:28:48 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_fork(char **envt, char **tabl, char **env)
{
	int		i;
	pid_t	father;

	i = 0;
	if (!ft_space(&tabl, &envt))
		return (0);
	father = fork();
	if (father)
	{
		wait(0);
		ft_del_tab_envt(&tabl, &envt);
	}
	else
	{
		while (envt[i])
			if (execve(envt[i], tabl, env) == -1)
				i++;
		ft_puterr("No such command 😑\n");
		ft_del_tab_envt(&tabl, &envt);
		exit(EXIT_FAILURE);
	}
	return (0);
}

char	**ft_set_path(char **envt, char ***tabl, char *my_env, char *line)
{
	int	i;

	*tabl = ft_strsplitwhite(line, ' ');
	if (!my_env || !(*tabl)[0])
		return (NULL);
	i = 0;
	envt = ft_strsplit(my_env, ':');
	while (envt[i])
	{
		envt[i] = ft_strjoindel(envt[i], "/");
		envt[i] = ft_strjoindel(envt[i], (*tabl)[0]);
		i++;
	}
	return (envt);
}

void	ft_major(char *line, char ***env)
{
	char	**tabl;
	char	*my_env;
	char	**envt;

	tabl = NULL;
	envt = NULL;
	my_env = ft_getenv(*env, "PATH");
	if (line[0])
	{
		envt = ft_set_path(envt, &tabl, my_env, line);
		if (!tabl[0])
		{
			ft_del_tab_envt(&tabl, &envt);
			return ;
		}
		if (!ft_check(tabl, env))
			ft_fork(envt, tabl, *env);
		else
			ft_del_tab_envt(&tabl, &envt);
	}
}

void	ft_major_comma(char *line, char ***env)
{
	int		i;
	char	**cmd;

	i = 0;
	cmd = ft_strsplit(line, ';');
	while (cmd[i])
	{
		ft_major(cmd[i], env);
		i++;
	}
	ft_strdeltab(&cmd);
}

int		main(int ac, char **av, char **environ)
{
	char	*line;
	char	**env;

	ac++;
	env = ft_clear_shell(av, environ);
	while (1)
	{
		ft_put_path(env);
		get_next_line(0, &line);
		if (line && ft_strcmp(line, "exit") == 0)
		{
			ft_putstr("Goodbye\n");
			ft_strdel(&line);
			exit(0);
		}
		ft_major_comma(line, &env);
		ft_strdel(&line);
	}
	return (0);
}
