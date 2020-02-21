/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 13:39:10 by tpons             #+#    #+#             */
/*   Updated: 2020/02/21 15:26:02 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int ac, char **av)
{
	int			fd;
	t_param		p;
	int			i = 0;

	fd = 0;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		get_param(fd, &p);
	}
	// if (ac == 3) Pour Screenshot
	while (p.s->param[i])
		printf("%s\n", p.s->param[i++]);
	close(fd);
	return (0);
}
