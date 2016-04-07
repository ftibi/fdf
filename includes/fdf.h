/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 14:12:13 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/07 18:11:17 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/includes/libft.h"
# include "get_next_line.h"
# include <fcntl.h>
# include "mlx.h"
# define DEBUG  1

typedef struct			s_map
{
    struct s_map		*right;
    struct s_map		*down;
	int					x;
	int					y;
	int					z;

}						t_map;

t_map					*read_map(char *av1);
void					print_map(t_map *map);
void					print_points(t_map *map);
void					print_lines(t_map *map);
#endif
