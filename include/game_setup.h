/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_setup.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:31:21 by pnopjira          #+#    #+#             */
/*   Updated: 2024/01/25 17:25:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_SETUP_H
# define GAME_SETUP_H

typedef struct s_color
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}	t_color;

typedef struct s_coor //coordinate
{
	double	x;
	double	y;
}	t_coor;

typedef struct s_ray
{
	t_coor	raydir;
	double	rdx;
	double	rdy;
	double	step_rdx;
	double	step_rdy;
	double	lcpd;
	int		step_side_x;
	int		step_side_y;
	bool	wall_hit_side;
	double	proj_dist;
	int		wall_hight;
	int		wall_y_start;
	int		wall_y_end;
	int		tex_x;
	int		index;
}	t_ray;

typedef struct s_imgdata
{
	void	*img;
	char	*addr;
	int		bpp;
	int		llen;
	int		endian;
}	t_imgdata;

typedef struct s_map
{
	t_list	*iden;
	bool	map_begin;
	bool	close_map;
	int		line_map_begin;
	char	**map_original;
	int		mapx;
	int		mapy;
	int 	mapsize;
	int		**map;
}	t_map;

typedef struct s_player
{
	int		map_x;
	int		map_y;
	t_coor	*pos;
	t_coor	*dir;
	t_coor	*right_dir;
	t_coor	*cam_plane;
	bool	one_player;
	char	d;
	int		psize;
}	t_player;

typedef struct s_frame
{
	int				w;
	int				h;
	unsigned int	floor_color;
	unsigned int	ceiling_color;
	t_player		*p;
	t_map			*map;
}	t_frame;

typedef struct s_viewport
{
	void		*mlx;
	void		*win;
	t_imgdata	*bgimg;
	t_imgdata	*mini_img;
	t_imgdata	tex_so_img;
	t_imgdata	tex_no_img;
	t_imgdata	tex_we_img;
	t_imgdata	tex_ea_img;
	t_frame 	*scene;
}	t_vp;

typedef struct s_even
{
	bool	move_f;
	bool	move_b;
	bool	move_l;
	bool	move_r;
	bool	turn_l;
	bool	turn_r;
}	t_event;

typedef struct s_main
{
	t_vp 			*viewport;
	t_map			*filemap;
	t_player		*player;
	t_ray			*ray;
	t_event			event;
	int				**map;
	unsigned int	floor_color;
	unsigned int	ceiling_color;
	char			*tex_so;
	char			*tex_we;
	char			*tex_ea;
	char			*tex_no;
	bool			one_player;
	int				tex_width;
	int				tex_hight;
}	t_main;

#endif
