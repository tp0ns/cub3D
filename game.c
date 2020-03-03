/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 10:42:16 by tpons             #+#    #+#             */
/*   Updated: 2020/03/03 17:52:13 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		key_management(int key, void *param)
{
	// if (key != 53)
	// 	printf("%d", key);
	if (key == 53)
		close_win();
	return (0);
}

int		play(t_param *p)
{
	int endian;
	
	endian = 0;
	p->d->image_ptr = mlx_new_image(p->d->mlx_ptr, p->s->x, p->s->y);
	p->d->image_data = mlx_get_data_addr(p->d->image_ptr, &p->d->bpp,
	 	&p->d->size_line, &endian);
	dda(p);
	mlx_put_image_to_window(p->d->mlx_ptr, p->d->win_ptr, p->d->image_ptr, 0, 0);
	return (0);
}

void	game(t_param *p)
{
	p->d->mlx_ptr = mlx_init();
	p->d->win_ptr = mlx_new_window(p->d->mlx_ptr,
		p->s->x, p->s->y, "Cub3D");
	mlx_key_hook(p->d->win_ptr, key_management, (void *)0);
	mlx_hook(p->d->win_ptr, 17, 1, close_win, (void *)0);
	mlx_loop_hook(p->d->mlx_ptr, play, p);
	mlx_loop(p->d->mlx_ptr);
}