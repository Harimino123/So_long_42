/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolof <hrasolof@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 12:22:53 by hrasolof          #+#    #+#             */
/*   Updated: 2024/09/09 00:02:23 by hrasolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

char	*get_next_line(int fd);
char	*ft_strjoin(const char *dest, const char *src);
char	*ft_strdup(const char *src);
char	*copy_char(char *str, int index);
char	*copy_rem_char(char *str, int index);
char	*ft_strcpy1(char *dest, char *src);
int		contains_newline(char *buf);
int		index_of_newline(char *buf);
size_t	ft_strlen(const char *str);

#endif
