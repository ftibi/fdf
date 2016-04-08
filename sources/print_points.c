/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_points.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 17:07:04 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/08 17:48:04 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_map *map_init(t_map *map, void *mlx, void *win, int a, int b);
static void aff(t_map *map);
static int my_key_funct(int keycode, t_map *map)
{
	if (DEBUG)
		ft_putendl("my key fct");
	ft_putstr("key event :");
	ft_putnbr(keycode);
	ft_putchar('\n');
	if (keycode == 53)
	{
		ft_putendl("exit");
		exit(0);
	}
	if (keycode == 35)
	{
		ft_putendl("zoom");
		map->zoom++;
		ft_putnbr(map->zoom);
		ft_putendl("");
		mlx_clear_window(map->mlx, map->win);
		map = map_init(map, map->mlx, map->win, map->a, map->b);
		aff(map);
	}
	if (keycode == 33)
	{
		ft_putendl("zoom");
		if (map->zoom > 1)
			map->zoom--;
		ft_putnbr(map->zoom);
		ft_putendl("");
		mlx_clear_window(map->mlx, map->win);
		map = map_init(map, map->mlx, map->win, map->a, map->b);
		aff(map);
	}
	if (keycode == 123)
	{
		ft_putendl("left");
		mlx_clear_window(map->mlx, map->win);
		map = map_init(map, map->mlx, map->win, map->a - 10, map->b);
		aff(map);
	}
	if (keycode == 124)
	{
		ft_putendl("right");
		mlx_clear_window(map->mlx, map->win);
		map = map_init(map, map->mlx, map->win, map->a + 10, map->b);
		aff(map);
	}
	if (keycode == 125)
	{
		ft_putendl("down");
		mlx_clear_window(map->mlx, map->win);
		map = map_init(map, map->mlx, map->win, map->a, map->b + 10);
		aff(map);
	}
	if (keycode == 126)
	{
		ft_putendl("up");
		mlx_clear_window(map->mlx, map->win);
		map = map_init(map, map->mlx, map->win, map->a, map->b - 10);
		aff(map);
	}
	return (0);
}

//static void	one_point(t_map *map, void *mlx, void *win, int a, int b)
//{
//	int zoom;
//
//	zoom = map->zoom;
//	if (DEBUG)
//		ft_putendl("one point");
//	if (map->z)
//		mlx_pixel_put(mlx, win, a + ((map->x - map->y) * 0.82 * 0.87) * zoom, b + ((map->x + map->y) * 0.82 * 0.5 - map->z * 0.82) * zoom, 0x00FFFF);
//	else
//		mlx_pixel_put(mlx, win, a + ((map->x - map->y) * 0.82 * 0.87) * zoom, b + ((map->x + map->y) * 0.82 * 0.5 - map->z * 0.82) * zoom, 0xFF0000);
//}

static void one_line(t_map *map, void *mlx, void *win, int a, int b)
{
	int zoom;
	float x;
	float y;
	float z;

//	if (DEBUG)
//		ft_putendl("one line");
	zoom = map->zoom;
	if (map->right)
	{
		x = map->x;
		z = map->z;
		while (x <= map->right->x)
		{
			mlx_pixel_put(mlx, win, a + ((x - map->y) * 0.82 * 0.87) * zoom, b + ((x + map->y) * 0.82 * 0.5 - z * 0.82) * zoom, 0x00FF00);
			x = x + 0.01;
			z = z + 0.01 * (map->right->z - map->z);
		}
	}
	if (map->down)
	{
		y = map->y;
		z = map->z;
		while (y <= map->down->y)
		{
			mlx_pixel_put(mlx, win, a + ((map->x - y) * 0.82 * 0.87) * zoom, b + ((map->x + y) * 0.82 * 0.5 - z * 0.82) * zoom, 0x00FF00);
			y = y + 0.01;
			z = z + 0.01 * (map->down->z - map->z);
		}
	}
}

static void aff(t_map *map)
{
	t_map *start;

	if (DEBUG)
		ft_putendl("aff");
	start = map;
	while (map)
	{
		one_line(map, map->mlx, map->win, map->a, map->b);
//		one_point(map, map->mlx, map->win, map->a, map->b);
		map = map->right;
		if (!map && start->down)
		{
			map = start->down;
			start = map;
		}
	}
}

static t_map *map_init(t_map *map, void *mlx, void *win, int a, int b)
{
	int zoom;

	t_map *start;
	t_map *vstart;
	zoom = map->zoom;

	if (DEBUG)
		ft_putendl("map init");
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

void	print_points(t_map *map, int size)
{
	if (DEBUG)
		ft_putendl("print points");
	map->a = size / 2.5;
	map->b = size / 3;

	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, size, size, "mlx 42");
	map = map_init(map, map->mlx, map->win, map->a, map->b);
	aff(map);
	mlx_pixel_put(map->mlx, map->win, map->a, map->b, 0xFFFFFF);
	mlx_key_hook(map->win, my_key_funct, map);
	mlx_loop(map->mlx);
}
