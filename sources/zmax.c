/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zmax.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/18 11:46:09 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/18 12:14:01 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int		ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

static t_map	*fill_max(t_map *map, int zmax)
{
	t_map	*start;
	t_map	*vstart;

	vstart = map;
	start = map;
	while (map)
	{
		map->zmax = zmax;
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

t_map			*mapzmax(t_map *map)
{
	t_map	*start;
	t_map	*vstart;
	int		zmax;

	zmax = 0;
	start = map;
	vstart = map;
	while (map)
	{
		if (ft_abs(map->z) > zmax)
			zmax = ft_abs(map->z);
		if (map->right)
			map = map->right;
		else
		{
			start = start->down;
			map = start;
		}
	}
	map = fill_max(vstart, zmax);
	return (map);
}
