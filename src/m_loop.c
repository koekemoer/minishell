/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_loop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoekemo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 10:32:25 by lkoekemo          #+#    #+#             */
/*   Updated: 2016/12/13 09:56:38 by lkoekemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		print_promt(t_var *v)
{
	if (getcwd(v->cwd, sizeof(v->cwd)) != 0)
	{
		ft_putstr(CYAN);
		ft_putstr(v->cwd);
		ft_putstr(RED);
		ft_putstr(" $> ");
		ft_putstr(RESET);
	}
}

void			free_args(char **arr)
{
	int		i;

	i = 0;
	if (arr == NULL)
		return ;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	if (arr != NULL)
		free(arr);
}

static void		m_exit(t_var *v)
{
	ft_putstr(GREEN);
	ft_putendl("KBYE!");
	ft_putstr(RESET);
	free_args(v->args);
	free_args(v->path);
	exit(0);
}

static int		builtins(t_var *v)
{
	int		res;
	char	*str;

	str = v->args[0];
	res = 0;
	if (ft_strcmp(str, "echo") == 0 || ft_strcmp(str, "cd") == 0 ||
			ft_strcmp(str, "env") == 0 || ft_strcmp(str, "setenv") == 0 ||
			ft_strcmp(str, "unset") == 0)
		res = 1;
	if (res == 1)
	{
		if (ft_strcmp(str, "cd") == 0)
			m_cd(v);
		else if (ft_strcmp(str, "echo") == 0)
			m_echo(v);
		else if (ft_strcmp(str, "env") == 0)
			m_env(v);
		else if (ft_strcmp(str, "setenv") == 0 && v->args[1] != NULL
				&& v->args[2] != NULL)
			m_setenv(v->args[1], v->args[2], 1, v);
		else if (ft_strcmp(str, "unset") == 0 && v->args[1] != NULL)
			m_unsetenv(v->args[1], v);
	}
	return (res);
}

void			m_loop(t_var *v)
{
	char *tmp;

	while (42)
	{
		free_args(v->path);
		free_args(v->args);
		tmp = m_getenv("PATH", v);
		print_promt(v);
		v->line = ft_getline();
		v->args = ft_strsplit(v->line, ' ');
		v->path = ft_strsplit(tmp, ':');
		ft_free(tmp);
		if (v->args[0] == '\0' || builtins(v) == 1)
			continue;
		else if (ft_strcmp(v->args[0], "exit") == 0)
			m_exit(v);
		else
			do_the_fork(v);
	}
}
