/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_env.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoekemo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 10:52:26 by lkoekemo          #+#    #+#             */
/*   Updated: 2016/12/13 10:02:04 by lkoekemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free(char *str)
{
	if (str != NULL)
		free(str);
}

void	m_env(t_var *v)
{
	int		i;

	i = 0;
	while (v->env[i] != NULL)
	{
		ft_putendl(v->env[i]);
		i++;
	}
}

char	*ft_errchk(const char *n, const char *val, int owrite, t_var *v)
{
	char		*str;
	char		*strtmp;
	char		*tmp;

	str = NULL;
	strtmp = NULL;
	tmp = m_getenv(n, v);
	if (n == NULL || n[0] == '\0' || ft_strchr(n, '=') != NULL ||
			val == NULL || ft_strchr(n, ' '))
		return (NULL);
	if (tmp != NULL && owrite == 0)
		return (NULL);
	if (!(strtmp = ft_strjoin(n, "=")))
		return (NULL);
	if (!(str = ft_strjoin(strtmp, val)))
		return (NULL);
	free(strtmp);
	free(tmp);
	if (str == NULL)
		return (NULL);
	return (str);
}

int		m_setenv(const char *name, const char *val, int owrite, t_var *v)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_errchk(name, val, owrite, v);
	while (v->env[i] != NULL)
	{
		if (ft_strncmp(v->env[i], name, ft_strlen(name)) == 0)
		{
			ft_strcpy(v->env[i], str);
			free(str);
			return (0);
		}
		i++;
	}
	v->env[i] = v->env[i - 1];
	v->env[i - 1] = str;
	v->env[i + 1] = NULL;
	return (0);
}

int		m_unsetenv(const char *name, t_var *v)
{
	int		i;
	char	**tmp;

	i = 0;
	while (v->env[i])
	{
		tmp = ft_strsplit(v->env[i], '=');
		if (ft_strncmp(tmp[0], name, ft_strlen(name)) == 0)
		{
			free(v->env[i]);
			while (v->env[i])
			{
				v->env[i] = v->env[i + 1];
				i++;
			}
			free_args(tmp);
			return (0);
		}
		free_args(tmp);
		i++;
	}
	return (0);
}
