/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcouet <tcouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/20 18:55:19 by tcouet            #+#    #+#             */
/*   Updated: 2015/05/08 19:32:26 by abellion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../libft/libft.h"
# include <fcntl.h>

# define BUFF_SIZE 5000

int		get_next_line(int const fd, char **line);
int		read_fd(int fd, char **part);
char	*get_line(char **part);

#endif
