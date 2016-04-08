/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/08 11:01:12 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/08 17:30:10 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	win_size(t_map *map)
{
	int		xmax;
	int		ymax;
	int		zmax;
	t_map	*tmp;
	int		size;

	if (DEBUG)
		ft_putendl("win_size");
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
	size = 0;
	size = (xmax > ymax) ? xmax : ymax;
	size = (size > zmax) ? size : zmax;
	return ((30 * size) > 2000 ? 2000 : 30 * size);
}
