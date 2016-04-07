/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 18:08:11 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/07 15:57:33 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_map	*new_point(int x, int y, int z)
{
	t_map	*new_pt;

	if (!(new_pt = (t_map*)ft_memalloc(sizeof(t_map))))
		return (0);
	new_pt->right = NULL;
	new_pt->down = NULL;
	new_pt->x = x;
	new_pt->y = y;
	new_pt->z = z;
	return (new_pt);
}

static t_map	*fill_line(char *line)
{
	t_map	*start;
	t_map	*tmp;
	char	**split_line;

	split_line = ft_strsplit(line, ' ');
	start = NULL;
	tmp = NULL;
	while (split_line)
	{
		if (!start)
		{
			start = new_point(0, 0, ft_atoi(*split_line));
			tmp = start;
		}
		else
		{
			tmp->right = new_point(0, 0, ft_atoi(*split_line));
			tmp = tmp->right;
		}
		split_line++;
	}
	return (start);
}

t_map			*read_map(char *av1, t_map *map)
{
	int 	lec;
	char	*line;
	int		fd;
	t_map	*chain_line;

	chain_line = NULL;
	lec = 1;
	line = NULL;
	if ((fd = open(av1, O_RDONLY)) == -1)
		return (0);
	while (lec)
	{
		lec = get_next_line(fd, &line);
	}
	return (0);
}
