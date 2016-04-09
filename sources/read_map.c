/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 18:08:11 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/09 14:16:27 by tfolly           ###   ########.fr       */
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
	new_pt->a = 0;
	new_pt->b = 0;
	new_pt->x = x;
	new_pt->y = y;
	new_pt->z = z;
	new_pt->zoom = 10;
	new_pt->ratio = 1;
	new_pt->mlx = NULL;
	new_pt->win = NULL;
	return (new_pt);
}

static t_map	*fill_line(char *line)
{
	t_map	*start;
	t_map	*tmp;
	char	**split_line;
	int		var;

	split_line = ft_strsplit(line, ' ');
	start = NULL;
	tmp = NULL;
	while (split_line && *split_line)
	{
		if (!start)
		{
			start = new_point(0, 0, ft_atoi(*split_line));
			tmp = start;
		}
		else
		{
			var = ft_atoi(*split_line);
			tmp->right = new_point(tmp->x + 1, 0, var);
			if (abs(var) > start->zmax)
				start->zmax = abs(var);
			tmp = tmp->right;
		}
		split_line++;
	}
	return (start);
}

static int		link_prev(t_map *prev_line, t_map *chain_line)
{
	while (prev_line && chain_line)
	{
		prev_line->down = chain_line;
		chain_line->y = prev_line->y + 1;
		prev_line = prev_line->right;
		chain_line = chain_line->right;
	}
	return (0);
}

t_map			*read_map(char *av1)
{
	char	*line;
	int		fd;
	t_map	*start;
	t_map	*chain_line;
	t_map	*prev_line;

	start = NULL;
	chain_line = NULL;
	prev_line = NULL;
	line = NULL;
	if ((fd = open(av1, O_RDONLY)) == -1)
		exit(0);
	while (get_next_line(fd, &line))
	{
		chain_line = fill_line(line);
		if (!start)
			start = chain_line;
		if (prev_line)
			link_prev(prev_line, chain_line);
		prev_line = chain_line;
	}
	close(fd);
	return (start);
}
