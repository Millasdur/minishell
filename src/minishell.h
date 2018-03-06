/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 11:43:23 by hlely             #+#    #+#             */
/*   Updated: 2017/12/10 10:06:07 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <unistd.h>
# include <signal.h>
# include <sys/types.h>
# include <termios.h>
# include <ncurses.h>
# include <term.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

char		**ft_clear_shell(char **av, char **environ);
char		**ft_cpyenv(char **environ);

char		*ft_getenv(char **env, char *elem);

int			ft_check(char **line, char ***env);
int			ft_space(char ***tabl, char ***envt);

void		ft_cd(char *path, char ***env);
void		ft_check_arrow(char **line, char **env);
void		ft_del_tab_envt(char ***envt, char ***tabl);
void		ft_echo(char **line);
void		ft_print_env(char **env);
void		ft_put_path(char **env);
void		ft_setenv(char ***env, char *elem, char *value);
void		ft_set_term(char **env);
void		ft_strdeltab(char ***tabl);
void		ft_touppercase(char *tmp, char *str);
void		ft_unsetenv(char ***env, char *elem);
#endif
