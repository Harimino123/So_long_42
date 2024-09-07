/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolof <hrasolof@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:39:22 by hrasolof          #+#    #+#             */
/*   Updated: 2024/09/02 20:39:22 by hrasolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "GNL/get_next_line.h"
#include "Libft/libft.h"
#include "./mlx/mlx.h"

typedef struct img_s
{
	void	*img_floor;
	void	*img_player;
	void	*img_exit;
	void	*img_wall;
	void	*img_collect;
	int		height;
	int		width;
	char	*player;
	char	*floor;
	char	*wall;
	char	*collect;
	char	*exit;
}				t_img;

typedef struct s_count
{
    char    exit;
    char    collectible;
    char    player;
    char    wall;
    char    space;
    int     p_count;
    int     e_count;
    int     c_count;
}   t_count;


typedef struct s_pos
{
    int x;
    int y;
} t_pos;

typedef struct s_game
{
    void *mlx_ptr;
    void *win_ptr;
    char **map;
    t_count content;
    t_img	img;
	t_pos	pos;
    int     count;
} t_game;

void content_set(t_count *content);
int check_file_extension(const char *filename);
int check_if_file_exists(const char *filename);
int is_rectangular(char **map);
void	ft_check_content(t_game *data);
int check_walls(char **map);
char **load_map(char **str, t_game *data);
int validate_map(char **map, t_count *content);
char **parse_map(int fd, t_game *data);
char	*get_map(int fd);
int	ft_check_line(char *map_line, char wall);
void	*ft_free_map(t_game *data);

#endif
