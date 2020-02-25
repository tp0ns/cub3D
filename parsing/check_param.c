/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 10:31:01 by tpons             #+#    #+#             */
/*   Updated: 2020/02/25 12:01:02 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	map_size(t_param *p)
{
	int	x;
	int y;
	
	x = 0;
	while (p->s->brut_map[x])
	{
		y = 0;
		while (p->s->brut_map[x][y])
			y++;
		if (y > p->s->max_y)
			p->s->max_y = y;
		x++;
	}
	p->s->max_x = x;
}

void	init_map(t_param *p)
{
	int	x;
	int	y;

	x = 0;
	map_size(p);
	if(!(p->s->map = malloc(sizeof(char *) * (p->s->max_x + 1))))
		leave("Something went wrong during map initialization");
	p->s->map[p->s->max_x] = 0;
	while (x < p->s->max_x)
	{
		y = 0;
		if(!(p->s->map[x] = malloc(sizeof(char) * (p->s->max_y + 1))))
			leave("Something went wrong during map initialization");
		while (y < p->s->max_y)
		{
			p->s->map[x][y] = -1;
			y++;
		}
		p->s->map[x][p->s->max_y] = '\0';
		x++;
	}
}

void	check_param(t_param *p)
{
	if (!p->s->c_col || !p->s->f_col || !p->s->x || !p->s->y || !p->s->north
		 || !p->s->south || !p->s->west || !p->s->east || !p->s->sprite)
		leave("Not enough informations in scene file");
	init_map(p);
}