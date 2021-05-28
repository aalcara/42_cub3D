/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 09:56:44 by aalcara-          #+#    #+#             */
/*   Updated: 2021/05/26 13:22:22 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>
# include "../lib/minilibx-linux/mlx.h"
# include "structs.h"

# define ROTATE_LEFT	65361
# define ROTATE_RIGHT	65363
# define FORWARD_W		119
# define BACK_S			115
# define RIGHT_D		100
# define LEFT_A			97
# define BUFFER_SIZE	4096

/******************************************************************************
**	cub3d
******************************************************************************/

int		ft_cub(char *str, t_cub *cub);
int		main(int argc, char **argv);

/******************************************************************************
**	cub3d_init
******************************************************************************/

void	ft_init_geral2(t_cub *cub);
void	ft_init_geral(t_cub *cub);

/******************************************************************************
**	cub3d_parsing
******************************************************************************/

int		ft_path_texture(char *str, char **texture, t_cub *cub, int j);
void	ft_texture(char *str, t_cub *cub);
void	ft_color_resolution(char **str, t_cub *cub);
void	ft_parsing(char *filename, t_cub *cub);

/******************************************************************************
**	cub3d_utils
******************************************************************************/

int		ft_strlen2(char *str);
int		ft_charinstr(char *str, char c);
int		ft_atoi_color(const char *str, t_cub *cub);
int		ft_atoi_resol(const char *str, t_cub *cub);

/******************************************************************************
**	cub3d_utils2
******************************************************************************/

int		ft_emptyline(char *str);
int		ft_nb_comma(const char *str);
void	ft_atoi_color_check(const char *str, t_cub *cub);

/******************************************************************************
**	errors
******************************************************************************/

void	ft_verify_errors(t_cub *cub);
void	ft_error2(t_cub *cub);
void	ft_error(t_cub *cub, char *str);

/******************************************************************************
**	exit
******************************************************************************/

int		ft_exit(t_cub *cub);

/******************************************************************************
**	map_parsing
******************************************************************************/

int		ft_copy_map(char *str, t_cub *cub);
int		ft_is_map(char *str, t_cub *cub);
void	ft_mapsize(char *str, t_cub *cub);
int		ft_parsing_map(char *filename, t_cub *cub);

/******************************************************************************
**	map_utils
******************************************************************************/

int		ft_walls_util(char *str);
int		ft_walls(t_cub *cub);
int		ft_start(char c, t_cub *cub, int i, int j);

/******************************************************************************
**	move_keys
******************************************************************************/

int		ft_key_press(int keycode, t_cub *cub);
int		ft_key_release(int keycode, t_cub *cub);

/******************************************************************************
**	raycasting
******************************************************************************/

int		ft_raycasting(t_cub *cub);
int		ft_mlx(t_cub *cub);

/******************************************************************************
**	raycasting_init
******************************************************************************/

void	ft_init_dir(t_cub *cub);
void	ft_init_mlx(t_cub *cub);
void	ft_init_ray2(t_cub *cub);
void	ft_init_ray(t_cub *cub);

/******************************************************************************
**	raycasting_move
******************************************************************************/

void	ft_forward_back(t_cub *cub);
void	ft_left_right(t_cub *cub);
void	ft_rotate_right_left(t_cub *cub);
void	ft_rotate_left(t_cub *cub, double olddirx);

/******************************************************************************
**	raycasting_utils
******************************************************************************/

void	ft_drawstartend(t_cub *cub);
void	ft_incrementray(t_cub *cub);
void	ft_stepsidedist(t_cub *cub);
void	ft_swap(t_cub *cub);

/******************************************************************************
**	save
******************************************************************************/

void	ft_header(t_cub *cub, int fd);
void	ft_save(t_cub *cub);

/******************************************************************************
**	save_check
******************************************************************************/

int		ft_check_save(char *str);

/******************************************************************************
**	sprite
******************************************************************************/

void	ft_dist_order2(t_cub *cub);
void	ft_dist_order(t_cub *cub);
void	ft_draw_spr(t_cub *cub, int y, int texx, int stripe);
void	ft_sprite(t_cub *cub);

/******************************************************************************
**	sprite_init
******************************************************************************/

void	ft_init_sprite(t_cub *cub);
void	ft_init_sprite2(t_cub *cub, int i, int j, int v);

/******************************************************************************
**	texture
******************************************************************************/
void	ft_get_texture_adress(t_cub *cub);
void	ft_get_texture(t_cub *cub);

/******************************************************************************
**	texture_draw
******************************************************************************/

void	ft_draw_texture(t_cub *cub, int x, int y);
int		ft_color_column(t_cub *cub);

/******************************************************************************
**	texture_init
******************************************************************************/

void	ft_init_texture(t_cub *cub);

/******************************************************************************
**	get_next_line
******************************************************************************/

int		ft_strlen(char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_subbuff(char *buff, int start, int len);
int		ft_check(char *str);
int		ft_copy(char **line, char **buff);
int		ft_eof(int ret, char **buff, char **line);
int		ft_free_buff(char **buff, t_cub *cub);
int		get_next_line(int fd, char **line, t_cub *cub);

#endif
