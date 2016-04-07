/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 14:13:12 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/07 15:56:29 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int ac, char **av)
{
	t_map	*map;

	if (!(map = (t_map*)ft_memalloc(sizeof(t_map))))
			return (0);
	if (ac == 1)
		return (0);
	map = read_map(av[1], map);
	return (0);
}