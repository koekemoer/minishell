/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_echo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoekemo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 15:20:51 by lkoekemo          #+#    #+#             */
/*   Updated: 2016/12/09 11:13:34 by lkoekemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		ft_printenv(char *str, t_var *v)
{
	int			i;
	int			j;
	char		temp[255];
	char		*strtmp;

	i = 1;
	j = 0;
	ft_memset(temp, '\0', 255);
	while (str[i] != '\0')
		temp[j++] = str[i++];
	strtmp = m_getenv(temp, v);
	if (strtmp == NULL)
		ft_putendl("Environment Variable does not exist");
	else
		ft_putendl(strtmp);
	if (strtmp != NULL)
		free(strtmp);
}

static void		de_quote(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\"')
			i++;
		ft_putchar(str[i]);
		i++;
	}
}

static void		de_quote_line(char *str)
{
	int		i;

	i = 0;
	while (i < ft_strlen(str))
	{
		while (str[i] != '\"' && str[i])
			i++;
		i++;
		while (str[i] != '\"' && str[i])
		{
			ft_putchar(str[i]);
			i++;
		}
		while (str[i] != '\"' && str[i])
			i++;
		i++;
		if (i < ft_strlen(str))
			ft_putchar(' ');
	}
}

void			m_echo(t_var *v)
{
	int		i;

	i = 1;
	if (v->args[1] == NULL)
		ft_putchar('\n');
	if (v->args[1][0] == '$')
		ft_printenv(v->args[1], v);
	else if (v->args[i][0] == '\"')
	{
		de_quote_line(v->line);
		ft_putchar('\n');
	}
	else
	{
		while (v->args[i])
		{
			de_quote(v->args[i]);
			if (v->args[i + 1] != NULL)
				ft_putchar(' ');
			else
				ft_putchar('\n');
			i++;
		}
	}
}
