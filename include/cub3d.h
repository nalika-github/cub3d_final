/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 19:09:08 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/25 19:17:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdbool.h>
# include <stdlib.h>

# include "mlx.h"
# include "get_next_line.h"
# include "libft.h"
# include "game_setup.h"

# define GREEN "\033[0;32m"
# define RED "\033[0;31m"
# define RESET "\033[0m"


// #ifdef __APPLE__
// // Define keys for macOS
// # define KEY_DOWN 125
// # define KEY_UP 126
// # define KEY_A 0
// # define KEY_S 1
// # define KEY_D 2
// # define KEY_W 13
// # define KEY_M 14
// # define KEY_LEFT 123
// # define KEY_RIGHT 124
// # define KEY_ESC 53
// #endif

# define EVENT_PRESS 02
# define EVENT_RELEASE 03
# define EVENT_DESTRORY 17

# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_M 109
# define KEY_DOWN 125
# define KEY_UP 126
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_ESC 65307

# define WINDOW_WIDTH 1440
# define WINDOW_HEIGHT 832
# define FOV 90
# define MOVE_SPEED 0.05
# define TURN_SPEED 1
# define TEX_WIDTH 64
# define TEX_HIGHT 64

/*cub3d*/
int				check_invalid_filedata(char *maps_path, t_map \
				*map, t_player *p);
int				raycaster_loop(t_main *main);

/*pnopjira_utils*/

//00map_setup

int				rd_mapdata(char *maps_path, t_map *map, t_player *p);
void			iden_list(t_list **iden);
void			init_plan(t_map *plan);
void			init_player(t_player *player);
void			init_scene(t_frame *scene);

//01map_setup

void			init_main_struct(t_main *main_struc);
void			init_imgdata(t_imgdata *bgimg);
int				is_invalid_input(char *argv, t_main *main);
void			del_nl(char **line);
int				setup_pos(char *dir, int x, int y, t_player *p);

//02map_setup

void			before_map_line(int fd2, int map_begin, char **line);
void			ck_invalid_map(int *err, int fd2, t_map *map, t_player *p);
void			print_map_original(char **map_original);
int				mapsize(t_map *m, t_player *p);
void			key_to_content(t_list *iden, char *key, char *content);

//03map_setup
int				set_vp(t_main *main);
int				allocated_map_int(int ***map, int mapy, int mapx);
int				tranformer(char o_map);
int				char_to_int_map(char **o_map, t_map *plan);
int				ck_map_info(t_map *map);
//04map_setup
int				fillable(t_map *map, int **tab, int y, int x);
void			touch_map_edge(t_map *map, int y, int x);
void			flood_fill(t_map *map, int **tab, int y, int x);
void			mapdup(int **dst, int **src, int mapy, int mapx);
void			ck_closed_walls(int *err, t_map *map, t_player *p);
//05map_setup
int				setup_pos_mapx(char **mapdata, int j, t_map *map, t_player *p);
int				set_main_struct(t_main	*main);
void			get_textures_path(t_main *main);
//check_dataformat
int				init_content(t_list *iden, char **dst, char **src, char *key);
int				ck_no_so_we_ea(char *tmp, t_list *iden);
int				ck_f_c_color(char *tmp, t_list *iden);
void			ck_data_format(char *tmp, int *err, t_map *map);
void			ck_invalid_iden(int *err, int fd1, t_map *map);
//check_invalid

int				explicit_error(int stage);
int				invalid_filepath(char *maps_path, char *path, char *format);
int				invalid_color_code(char *rgb);
int				ck_identify(int *err, t_list *iden);
int				before_map(t_map *map, int *err);

//frame_setup

void			translate_rgb(char *str, t_color *color);
unsigned int	hexcode(t_frame *secen, char *key);
int				set_scene(t_frame *scene);
int				color3f(int r, int g, int b);

//free_allocated01

void			free_player(t_player *p);
void			free_scene(t_frame *scene);
int				cub3d_exit(t_main *main_struc);

//free_allocated02

void			free_color(char **color);
void			del(void *lst);
void			free_int_map(int **tab, int mapy);
void			free_map(t_map *map);

//get_next_line

void			read_next(t_vars *v);
void			get_nlbyte(t_vars *v);
void			consume_token(t_vars *v, char *str);
char			*get_next_line(int fd);

//player_setup

void			find_player_pos(t_player *p);
void			begin_dir_of_player(t_main *main, char d);

/*ptungbun_utils*/

// bresenham.c

void			imgpixelput(t_imgdata *img, int x, int y, int color);
void			bresenham_x(t_imgdata *img, int *x, int *y, int color);
void			bresenham_y(t_imgdata *img, int *x, int *y, int color);
void			drawline(t_imgdata *img, int *x, int *y, int color);

//cube3d_render.c

void			get_y(t_ray ray, int *y1, int *y2, int index);
void			cub3d_render(t_main *main_struc, t_vp *vp);

//draw_wall.c

void			ray_on_wall_pos_cal(t_main *ms, t_ray *ray, t_player *p);
int				get_tex_color(t_imgdata *tex_img, int x, int y);
t_imgdata		*get_texture(t_ray *ray, t_vp *vp);
int				get_tex_y(t_main *ms, t_ray *ray, int *y, int i);
void			draw_wall(t_main *ms, int x, int *y, t_ray *ray);

//init_ray_data.c

void			init_ray(t_main *main_struc);
void			get_step_ray_dist(t_ray *ray);
void			get_first_step_ray_dist(t_ray *ray, t_player *p);
void			perform_dda(t_ray *ray, int **map, t_player *p);
void			cal_ray_projection_dist_n_wall_hight(t_ray *ray);

// movement.c

void			move_l(t_main *ms);
void			move_r(t_main *ms);
void			move_f(t_main *ms);
void			move_b(t_main *ms);

// animate_loop.c

int				animate_loop(t_main *ms);
void			re_calculate_ray(t_main *ms);
void			calculate_movement(t_main *ms);
int				press_event(int key, t_main *ms);
int				release_event(int key, t_main *ms);

//rotate.c

void			rotate(t_main *main_struc, double degree);

//get_tex_image.c

void			bg_init(t_vp *vars);
t_imgdata		get_tex_image(t_vp *vp, char *path, int *w, int *h);

#endif
