/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyfct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 14:55:04 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/09 14:59:07 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	keyfct(int keycode, t_map *map)
{
	if (keycode == 123)
	{
		mlx_clear_window(map->mlx, map->win);
		map = map_init(map, map->a - 10, map->b, map->zoom);
		aff(map);
	}
	if (keycode == 124)
	{
		mlx_clear_window(map->mlx, map->win);
		map = map_init(map, map->a + 10, map->b, map->zoom);
		aff(map);
	}
	if (keycode == 125)
	{
		mlx_clear_window(map->mlx, map->win);
		map = map_init(map, map->a, map->b + 10, map->zoom);
		aff(map);
	}
	if (keycode == 126)
	{
		mlx_clear_window(map->mlx, map->win);
		map = map_init(map, map->a, map->b - 10, map->zoom);
		aff(map);
	}
}
