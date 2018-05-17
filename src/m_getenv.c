/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerasmus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 16:59:22 by jerasmus          #+#    #+#             */
/*   Updated: 2016/12/13 10:02:43 by lkoekemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		*ft_envloop(int i, const char *name, char **t, t_var *v)
{
	char		*ft;

	while (v->env[i])
	{
		t = ft_strsplit(v->env[i], '=');
		if (ft_strncmp(t[0], name, ft_strlen(name)) == 0)
		{
			ft = (char *)ft_memalloc(sizeof(char) * (ft_strlen(t[1])));
			ft_strcpy(ft, t[1]);
			free_args(t);
			return (ft);
		}
		free_args(t);
		i++;
	}
	return (NULL);
}

char			*m_getenv(const char *name, t_var *v)
{
	int			i;
	char		**temp;
	char		*str;

	i = 0;
	temp = NULL;
	str = ft_envloop(i, name, temp, v);
	if (str != NULL)
		return (str);
	free_args(temp);
	return (NULL);
}
