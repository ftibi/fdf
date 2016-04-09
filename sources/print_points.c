/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_points.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 17:07:04 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/09 14:59:46 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int				my_key_funct(int keycode, t_map *map)
{
	if (keycode == 53)
	{
		ft_putendl("exit");
		exit(0);
	}
	if (keycode == 35)
	{
		map->zoom++;
		ft_putnbr(map->zoom);
		ft_putendl("");
		mlx_clear_window(map->mlx, map->win);
		aff(map);
	}
	if (keycode == 33)
	{
		if (map->zoom > 1)
			map->zoom--;
		mlx_clear_window(map->mlx, map->win);
		map = map_init(map, map->a, map->b, map->zoom);
		aff(map);
	}
	keyfct(keycode, map);
	return (0);
}

static void		one_line2(t_map *map)
{
	int		zoom;
	float	y;
	float	z;

	zoom = map->zoom;
	if (map->down)
	{
		y = map->y;
		z = map->z;
		while (y <= map->down->y)
		{
			mlx_pixel_put(map->mlx, map->win, map->a + ((map->x - y)
						* 0.82 * 0.87) * zoom, map->b + ((map->x + y)
							* 0.82 * 0.5 - z * 0.82) * zoom, 0x00FF00);
			y = y + 0.01;
			z = z + 0.01 * (map->down->z - map->z);
		}
	}
}

void			one_line(t_map *map)
{
	int		zoom;
	float	x;
	float	z;

	zoom = map->zoom;
	if (map->right)
	{
		x = map->x;
		z = map->z;
		while (x <= map->right->x)
		{
			mlx_pixel_put(map->mlx, map->win, map->a + ((x - map->y)
						* 0.82 * 0.87) * zoom, map->b + ((x + map->y)
							* 0.82 * 0.5 - z * 0.82) * zoom, 0x00FF00);
			x = x + 0.01;
			z = z + 0.01 * (map->right->z - map->z);
		}
	}
	one_line2(map);
}

t_map			*map_init(t_map *map, int a, int b, int zoom)
{
	void	*mlx;
	void	*win;
	t_map	*start;
	t_map	*vstart;

	mlx = map->mlx;
	win = map->win;
	start = map;
	vstart = map;
	while (map)
	{
		map->zoom = zoom;
		map->mlx = mlx;
		map->win = win;
		map->a = a;
		map->b = b;
		if (map->right)
			map = map->right;
		else
		{
			start = start->down;
			map = start;
		}
	}
	return (vstart);
}

void			print_points(t_map *map, int size)
{
	map->a = size / 2.5;
	map->b = size / 3;
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, size, size, "mlx 42");
	map = map_init(map, map->a, map->b, map->zoom);
	aff(map);
	mlx_pixel_put(map->mlx, map->win, map->a, map->b, 0xFFFFFF);
	mlx_key_hook(map->win, my_key_funct, map);
	mlx_loop(map->mlx);
}
