/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_getline.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoekemo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 10:32:13 by lkoekemo          #+#    #+#             */
/*   Updated: 2016/12/08 14:23:55 by lkoekemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_getchar(void)
{
	char	c;

	if (read(0, &c, 1) != 1)
		return (-1);
	return ((int)c);
}

char	*ft_getline(void)
{
	int			i;
	int			c;
	static char	buf[BUF_SIZE];

	i = 0;
	ft_bzero(buf, BUF_SIZE);
	while (1)
	{
		c = ft_getchar();
		if (c == '\n' || c == '\0')
		{
			buf[i] = '\0';
			return (buf);
		}
		else
			buf[i] = c;
		i++;
	}
	return (0);
}
