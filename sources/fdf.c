/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 14:13:12 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/18 15:08:33 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void		ft_error(void)
{
	ft_putchar('\n');
	exit(0);
}

int				main(int ac, char **av)
{
	t_map	*map;

	if (ac == 1)
		ft_error();
	map = read_map(av[1]);
	if (!map)
		ft_error();
	map = mapzmax(map);
	print_points(map, win_size(map));
	return (0);
}
