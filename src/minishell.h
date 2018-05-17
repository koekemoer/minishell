/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkoekemo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 10:32:43 by lkoekemo          #+#    #+#             */
/*   Updated: 2016/12/13 10:03:40 by lkoekemo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"

# define BUF_SIZE 1024

typedef struct	s_var
{
	char		*line;
	char		**args;
	char		**path;
	char		**env;
	char		cwd[512];
	char		*cd_home;
	char		*cd_path;
	char		*cd_old;
	char		*cd_pwd;
}				t_var;

char			*ft_getline(void);
void			free_args(char **arr);
void			m_loop(t_var *v);
void			m_env(t_var *v);
char			*m_getenv(const char *name, t_var *v);
void			m_cd(t_var *v);
void			m_echo(t_var *v);
int				do_the_fork(t_var *v);
int				m_setenv(const char *name, const char *val, int owrite,
		t_var *v);
int				m_unsetenv(const char *name, t_var *v);
void			init(t_var *v);
void			m_dquote(char *str);
void			m_squote(char *str);
int				m_countq(char *str);
int				m_count_arr(char **arr);
char			*m_argsjoin(char **args);
void			ft_free(char *str);

# define RED "\e[31m"
# define GREEN "\e[32m"
# define YELLOW "\e[33m"
# define BLUE "\e[34m"
# define MAGENTA "\e[35m"
# define CYAN "\e[36m"
# define RESET "\e[0m"

# define CLEAR "\033[H\033[J"

#endif
