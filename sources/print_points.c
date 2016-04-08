/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_points.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 17:07:04 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/08 12:07:49 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int my_key_funct(int keycode, void *param)
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
	param = 0;
	return (0);
}

static void	one_point(t_map *map, void *mlx, void *win, int a, int b)
{
	int zoom;

	zoom = 15;
	if (DEBUG)
		ft_putendl("one point");
	if (map->z)
		mlx_pixel_put(mlx, win, a + ((map->x - map->y) * 0.82 * 0.87) * zoom, b + ((map->x + map->y) * 0.82 * 0.5 - map->z * 0.82) * zoom, 0x00FFFF);
	else
		mlx_pixel_put(mlx, win, a + ((map->x - map->y) * 0.82 * 0.87) * zoom, b + ((map->x + map->y) * 0.82 * 0.5 - map->z * 0.82) * zoom, 0xFF0000);
}

static void one_line(t_map *map, void *mlx, void *win, int a, int b)
{
	int zoom = 15;
	float x;
	float y;
	float z;

	x = map->x;
	y = map->y;
	z = map->z;
	if (map->right)
	{
		while (x < map->right->x)
		{
			mlx_pixel_put(mlx, win, a + ((x - map->y) * 0.82 * 0.87) * zoom, b + ((x + map->y) * 0.82 * 0.5 - z * 0.82) * zoom, 0x00FF00);
			x = x + 0.01;
			z = z + 0.01 * (map->right->z - map->z);
		}
	}
	if (map->down)
	{
		while (y < map->down->y)
		{
			mlx_pixel_put(mlx, win, a + ((map->x - y) * 0.82 * 0.87) * zoom, b + ((map->x + y) * 0.82 * 0.5 - z * 0.82) * zoom, 0x00FF00);
			y = y + 0.01;
			z = z + 0.01 * (map->down->z - map->z);
		}
	}
}

void	print_points(t_map *map, int size)
{
	void	*mlx;
	void	*win;
	int		a;
	int		b;
	t_map	*start;

	if (DEBUG)
		ft_putendl("print points");
	a = size / 2.5;
	b = size / 2.5;


	mlx = mlx_init();
	win = mlx_new_window(mlx, size, size, "mlx 42");
	start = map;
	while (map)
	{
		one_line(map, mlx, win, a, b);
		one_point(map, mlx, win, a, b);
		map = map->right;
		if (!map && start->down)
		{
			map = start->down;
			start = map;
		}
	}
	mlx_pixel_put(mlx, win, a, b, 0xFFFFFF);
	mlx_key_hook(win, my_key_funct, 0);
	mlx_loop(mlx);
}
