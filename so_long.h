/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolof <hrasolof@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:39:22 by hrasolof          #+#    #+#             */
/*   Updated: 2024/09/08 12:05:36 by hrasolof         ###   ########.fr       */
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
#include "Printf/ft_printf.h"
#include "./mlx/mlx.h"


# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define ESC_KEY 65307


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
int check_elements(char **map, t_count *content);
int is_rectangular(char **map);
void	ft_check_content(t_game *data);
int check_walls(char **map);
char **load_map(char **str, t_game *data);
int validate_map(char **map, t_count *content);
char **parse_map(int fd, t_game *data);
char	*get_map(int fd);
int	ft_check_line(char *map_line, char wall);
void	set_img(t_game *data);
void render_map(t_game *data);
void cleanup(t_game *data);
int ft_height(char **map);
int ft_width(char **map);
void move_player(t_game *data, int x_offset, int y_offset);
int handle_key(int keycode, t_game *data);
int handle_exit(t_game *data);
static void *st_free(char **str);
int ft_free(char **str);
void ft_free_map(char **map);

#endif
