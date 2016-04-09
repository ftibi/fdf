/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 15:44:50 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/09 12:44:15 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	print_map(t_map *map)
{
	t_map *start;

	if (DEBUG)
		ft_putendl("print_map");
	start = map;
	while (map)
	{
		while (map)
		{
			ft_putnbr(map->z);
			ft_putchar(' ');
			map = map->right;
		}
		ft_putchar('\n');
		map = start->down;
		start = map;
	}
}
