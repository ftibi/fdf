/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 14:13:12 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/18 11:57:15 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int ac, char **av)
{
	t_map	*map;

	if (ac == 1)
		return (0);
	map = read_map(av[1]);
	map = mapzmax(map);
	print_points(map, win_size(map));
	return (0);
}
