/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolof <hrasolof@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 20:39:22 by hrasolof          #+#    #+#             */
/*   Updated: 2024/09/10 11:58:38 by hrasolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include "GNL/get_next_line.h"
# include "Libft/libft.h"
# include "Printf/ft_printf.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

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
}			t_img;

typedef struct s_count
{
	char	exit;
	char	collectible;
	char	player;
	char	wall;
	char	space;
	int		p_count;
	int		e_count;
	int		c_count;
}			t_count;

typedef struct s_pos
{
	int		x;
	int		y;
}			t_pos;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	char	**map;
	t_count	content;
	t_img	img;
	t_pos	pos;
	int		count;
}			t_game;

typedef struct s_ff_data
{
	char	**map;
	int		max_x;
	int		max_y;
	int		collectibles_left;
}			t_ff_data;

void		content_set(t_count *content);
void		set_img(t_game *data);
void		render_map(t_game *data);
void		cleanup(t_game *data);
void		move_player(t_game *data, int x_offset, int y_offset);
void		ft_free_map(char **map);
char		**load_map(char **str, t_game *data);
char		**parse_map(int fd, t_game *data);
char		*get_map(int fd);
int			ft_height(char **map);
int			ft_width(char **map);
int			handle_key(int keycode, t_game *data);
int			handle_exit(t_game *data);
int			ft_free(char **str);
int			ft_temp(char **map, int start_x, int start_y,
				int total_collectibles);
int			find_player_position(char **map, int *x, int *y);
int			count_collectibles(char **map);
int			check_file_extension(const char *filename);
int			check_if_file_exists(const char *filename);
int			check_elements(char **map, t_count *content);
int			is_rectangular(char **map);
int			check_walls(char **map);
int			validate_map(char **map, t_count *content);
int			check_ec(t_ff_data *data, int x, int y);

#endif
