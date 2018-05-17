/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoekemo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 10:31:12 by lkoekemo          #+#    #+#             */
/*   Updated: 2016/12/13 10:03:08 by lkoekemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init(t_var *v)
{
	extern char		**environ;
	int				c;
	int				i;

	i = 0;
	v->line = NULL;
	v->args = NULL;
	v->path = NULL;
	v->cd_home = NULL;
	v->cd_path = NULL;
	v->cd_pwd = NULL;
	v->cd_old = NULL;
	c = m_count_arr(environ);
	v->env = (char **)ft_memalloc(sizeof(char *) * (c + 2));
	while (environ[i])
	{
		v->env[i] = (char *)ft_memalloc(sizeof(char) *
				(ft_strlen(environ[i]) + 1));
		ft_strcpy(v->env[i], environ[i]);
		i++;
	}
	v->env[i] = NULL;
}

int		main(void)
{
	t_var		v;

	init(&v);
	ft_putstr(CLEAR);
	ft_putstr(GREEN);
	ft_putendl("Sharknado_Shell by lkoekemo");
	ft_putstr(RESET);
	m_loop(&v);
	return (0);
}
