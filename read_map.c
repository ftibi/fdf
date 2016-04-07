/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfolly <tfolly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/05 18:08:11 by tfolly            #+#    #+#             */
/*   Updated: 2016/04/07 14:03:40 by tfolly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "libft/includes/libft.h"
#include "getnextline/get_next_line.h"

int	main(int ac, char *av)
{
	int 	lec;
	char	*tmp;
	lec = 1;
	tmp = NULL;
	while (lec)
	{
		lec = get_next_line();
	}
	return (0);
}

