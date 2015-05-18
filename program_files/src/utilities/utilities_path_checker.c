/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_path_checker.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 18:43:10 by abellion          #+#    #+#             */
/*   Updated: 2015/03/14 17:19:13 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_minishell2.h"

char	*path_checker_rights(char *path)
{
	struct stat		infos;
	mode_t			st_mode;
	char			*rights;
	int				ret;

	if (!path)
		return (0);
	ret = lstat(path, &infos);
	if (ret >= 0)
	{
		st_mode = infos.st_mode;
		rights = ft_strnew(3);
		rights[0] = (st_mode & S_IRUSR) ? 'r' : '-';
		rights[1] = (st_mode & S_IWUSR) ? 'w' : '-';
		rights[2] = (st_mode & S_IXUSR) ? 'x' : '-';
		return (rights);
	}
	return (0);
}

int		path_checker_isreg(char *path)
{
	struct stat		infos;
	int				ret;

	if (!path)
		return (0);
	ret = stat(path, &infos);
	if (ret == 0 && S_ISREG(infos.st_mode))
		return (1);
	return (0);
}

int		path_checker_isdir(char *path)
{
	struct stat		infos;
	int				ret;

	if (!path)
		return (0);
	ret = stat(path, &infos);
	if ((ret == 0 && S_ISDIR(infos.st_mode)) || (ret == -1 && errno == EACCES))
		return (1);
	return (0);
}
