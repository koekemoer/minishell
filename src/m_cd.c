/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msh_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoekemo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 08:36:49 by lkoekemo          #+#    #+#             */
/*   Updated: 2016/12/09 11:12:29 by lkoekemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		*get_path(char *str)
{
	int		i;
	int		j;
	char	*path;

	i = 0;
	j = 0;
	if (!(path = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (NULL);
	while (str[i])
	{
		if (str[i] == '~')
			i++;
		path[j] = str[i];
		i++;
		j++;
	}
	path[j] = '\0';
	return (path);
}

void			m_cd(t_var *v)
{
	v->cd_path = NULL;
	v->cd_home = m_getenv("HOME", v);
	v->cd_old = m_getenv("OLDPWD", v);
	v->cd_pwd = m_getenv("PWD", v);
	m_setenv("OLDPWD", v->cd_pwd, 1, v);
	if (v->args[1] != NULL)
	{
		v->cd_path = get_path(v->args[1]);
		if (v->args[1][0] == '~')
			chdir(ft_strcat(v->cd_home, v->cd_path));
		else if (v->args[1][0] == '-')
			chdir(v->cd_old);
		else
			chdir(v->cd_path);
	}
	else
		chdir(v->cd_home);
	m_setenv("PWD", getcwd(v->cwd, sizeof(v->cwd)), 1, v);
	free(v->cd_path);
	free(v->cd_home);
	free(v->cd_old);
	free(v->cd_pwd);
}
