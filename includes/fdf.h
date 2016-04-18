/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 14:12:13 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/18 11:57:13 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/includes/libft.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <math.h>
# include "mlx.h"
# define DEBUG  1

typedef struct			s_map
{
	struct s_map		*right;
	struct s_map		*down;
	int					a;
	int					b;
	int					x;
	int					y;
	int					z;
	int					zmax;
	int					zoom;
	float				ratio;
	void				*mlx;
	void				*win;
}						t_map;

t_map					*map_init(t_map *map, int a, int b, int zoom);
void					aff(t_map *map);
t_map					*read_map(char *av1);
void					print_map(t_map *map);
void					print_points(t_map *map, int size);
int						win_size(t_map *map);
void					one_line(t_map *map);
void					keyfct(int keycode, t_map *map);
t_map					*mapzmax(t_map *map);
#endif
