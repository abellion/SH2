/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abellion <abellion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/14 17:10:47 by abellion          #+#    #+#             */
/*   Updated: 2015/03/14 17:10:49 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../ft_minishell2.h"

char	*cd_option_p(char *path)
{
	struct stat		infos;
	char			cwd[1024];

	if (!lstat(path, &infos) && S_ISLNK(infos.st_mode))
	{
		getcwd(cwd, 1024);
		return (ft_strdup(cwd));
	}
	return (path);
}
