/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_controller.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/21 18:39:27 by abellion          #+#    #+#             */
/*   Updated: 2015/05/12 17:48:01 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_minishell2.h"

void		prompt_put_line(char *user_name, char *curent_d)
{
	ft_putchar('[');
	ft_putstr(user_name);
	ft_putstr(" : ");
	ft_putstr(curent_d);
	ft_putstr("] > ");
}

char		*prompt_get_cdir(char *path, char *user_name)
{
	int				len;
	char			*tmp;
	char			*curent_d;

	if ((curent_d = ft_strstr(path, user_name)))
	{
		len = ft_strlen(curent_d) - ft_strlen(user_name);
		curent_d = ft_strsub(curent_d, ft_strlen(user_name), len);
		tmp = curent_d;
		curent_d = ft_strjoin("~", curent_d);
		ft_strdel(&tmp);
		return (curent_d);
	}
	return (ft_strdup(path));
}

void		prompt_get_infos(t_list *env, char **user_name, char **path)
{
	static char		**env_save;
	char			**env_tab;

	if (!env_save)
		env_save = lst_to_tab(env);
	env_tab = (env) ? lst_to_tab(env) : env_save;
	*user_name = env_get_from_tab("USER", env_save);
	*path = env_get_from_tab("PWD", env_tab);
}

char		*prompt_controller(t_list *env, int get_input)
{
	char	*tmp;
	char	*path;
	char	*input;
	char	*user_name;

	prompt_get_infos(env, &user_name, &path);
	prompt_put_line(user_name, prompt_get_cdir(path, user_name));
	ft_strdel(&path);
	ft_strdel(&user_name);
	if (get_input && (get_next_line(0, &input) > 0))
	{
		tmp = ft_strtrim(input);
		ft_strdel(&input);
		return (tmp);
	}
	return (0);
}
