/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 14:33:56 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/09 14:37:29 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	aff(t_map *map)
{
	t_map *start;

	start = map;
	while (map)
	{
		one_line(map);
		map = map->right;
		if (!map && start->down)
		{
			map = start->down;
			start = map;
		}
	}
}
