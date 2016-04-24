/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 11:01:12 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/24 18:34:17 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	ret_size(int xmax, int ymax, int zmax)
{
	int	size;

	size = 0;
	size = (xmax > ymax) ? xmax : ymax;
	size = (size > zmax) ? size : zmax;
	size = ((30 * size) > 2000) ? 2000 : 30 * size;
	size = size < 100 ? 100 : size;
	return (size);
}

int			win_size(t_map *map)
{
	int		xmax;
	int		ymax;
	int		zmax;
	t_map	*tmp;

	xmax = 0;
	ymax = 0;
	zmax = 0;
	tmp = map;
	while (tmp->right)
	{
		tmp = tmp->right;
		xmax++;
	}
	tmp = map;
	while (tmp->down)
	{
		tmp = tmp->down;
		if (tmp->z > zmax)
			zmax = tmp->z;
		ymax++;
	}
	return (ret_size(xmax, ymax, zmax));
}
