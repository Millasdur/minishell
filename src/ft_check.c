/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:05:42 by hlely             #+#    #+#             */
/*   Updated: 2017/12/09 16:00:55 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_launch(char **line, char **env)
{
	pid_t	father;

	father = fork();
	if (father)
		wait(0);
	else
		execve(line[0], line, env);
}

int		ft_check(char **line, char ***env)
{
	if (!ft_strcmp(line[0], "env"))
		ft_print_env(*env);
	else if (!ft_strcmp(line[0], "setenv"))
		ft_setenv(env, line[1], line[2]);
	else if (!ft_strcmp(line[0], "unsetenv"))
		ft_unsetenv(env, line[1]);
	else if (!ft_strcmp(line[0], "cd"))
		ft_cd(line[1], env);
	else if (!ft_strcmp(line[0], "echo"))
		ft_echo(line);
	else if (!access(line[0], F_OK | X_OK))
		ft_launch(line, *env);
	else
		return (0);
	return (1);
}
