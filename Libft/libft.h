/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolof <hrasolof@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 08:28:09 by hrasolof          #+#    #+#             */
/*   Updated: 2024/09/08 11:18:00 by hrasolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
#include <stdio.h>
//# include <string.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list		*ft_lstnew(void *content);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *str);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
void		ft_lstadd_front(t_list **lst, t_list *news);
void		ft_striteri(char *str, void (*function)(unsigned int, char*));
void		*ft_calloc(size_t n_block, size_t size);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		ft_bzero(void *buff, size_t len);
void		*ft_memset(void *buff, int value, size_t len);
void		*ft_memcpy(void *str1, const void *str2, size_t numBytes);
void		*ft_memchr(const void *str, int c, size_t n);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *str, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
char		*ft_strmapi(char const *str, char (*function)(unsigned int, char));
char		**ft_split(char const *str, char separator);
char		*ft_strtrim(char const *s1, char const *set);
// char		*ft_strjoin(char const *dest, char const *src);
char		*ft_strnstr(const char *big, const char *little, size_t n);
char		*ft_substr(char const *str, unsigned int start, size_t len);
char		*ft_strdup(const char *src);
char		*ft_strchr(const char *str, int c);
char		*ft_strrchr(const char *str, int c);
char		*ft_itoa(int n);
int			ft_lstsize(t_list *lst);
int			ft_memcmp(const void *str1, const void *str2, size_t n);
int			ft_strncmp(const char *str1, const char *str2, size_t n);
int			ft_atoi(const char *str);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_isprint(int c);
int			ft_toupper(int chr);
int			ft_tolower(int chr);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);

#endif
