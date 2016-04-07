/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_points.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 17:07:04 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/07 18:02:05 by tfolly           ###   ########.fr       */
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
		mlx_pixel_put(mlx, win, a + ((map->x - map->y) * 0.82 * 0.87) * zoom, b + ((map->x + map->y) * 0.82 * 0.5 + map->z * 0.82) * zoom, 0x00FFFF);
	else
		mlx_pixel_put(mlx, win, a + ((map->x - map->y) * 0.82 * 0.87) * zoom, b + ((map->x + map->y) * 0.82 * 0.5 + map->z * 0.82) * zoom, 0xFF0000);
}

void	print_points(t_map *map)
{
	void	*mlx;
	void	*win;
	int		a;
	int		b;
	t_map	*start;

	if (DEBUG)
		ft_putendl("print points");
	a = 200;
	b = 200;


	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "mlx 42");
	start = map;
	while (map)
	{
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
