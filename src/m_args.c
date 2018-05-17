/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jerasmus <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 14:51:57 by jerasmus          #+#    #+#             */
/*   Updated: 2016/12/08 14:02:45 by lkoekemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "stdio.h"

int			m_count_arr(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		i++;
	}
	return (i);
}

char		*m_argsjoin(char **args)
{
	int		i;
	char	*str;
	char	*tmp;

	i = 1;
	str = "\0";
	tmp = "\0";
	while (args[i])
	{
		str = ft_strjoin(tmp, args[i]);
		if (i > 1)
			free(tmp);
		if (i < (m_count_arr(args) - 1))
		{
			tmp = str;
			str = ft_strjoin(tmp, " ");
			free(tmp);
		}
		tmp = str;
		i++;
	}
	return (str);
}
