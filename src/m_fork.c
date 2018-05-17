/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_fork.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoekemo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 10:14:04 by lkoekemo          #+#    #+#             */
/*   Updated: 2016/12/13 09:59:58 by lkoekemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		*execute(t_var *v)
{
	int		i;
	int		p_count;
	char	*tmp;
	char	*tmp2;

	i = 0;
	p_count = 0;
	if (access(v->args[0], F_OK) != -1)
		return (v->args[0]);
	if (v->path != NULL)
	{
		p_count = m_count_arr(v->path);
		while (i++ < p_count && v->path[i] != NULL)
		{
			tmp2 = ft_strcat(v->path[i], "/");
			tmp = ft_strcat(tmp2, v->args[0]);
			if (access(tmp, F_OK) != -1)
				return (tmp);
		}
	}
	ft_putstr(v->args[0]);
	ft_putendl(": command not found");
	return (NULL);
}

int				do_the_fork(t_var *v)
{
	pid_t	pid;
	int		sig;
	char	*tmp;

	tmp = execute(v);
	sig = 1;
	if (tmp != NULL)
	{
		pid = fork();
		if (pid < 0)
		{
			ft_putendl("The Fork could not be done");
			return (1);
		}
		if (pid > 0)
			wait(&sig);
		if (pid == 0)
			execve(tmp, v->args, v->env);
	}
	return (1);
}
