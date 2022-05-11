/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdutel-l <cdutel-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:47:44 by cdutel-l          #+#    #+#             */
/*   Updated: 2022/02/06 17:37:06 by cdutel-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# include <stdio.h>

char	*get_next_line(int fd);
int		ft_strchr(char *s, int c);
char	*ft_strjoingnl(char *s1, char *s2);
char	*ft_fullstr(char *str, int fd);
char	*ft_select(char *str);
char	*ft_static(char *str);
int		ft_strlen(char *str);

#endif