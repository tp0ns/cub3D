/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 15:34:19 by tpons             #+#    #+#             */
/*   Updated: 2019/10/14 16:51:42 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
		write(1, &str[i++], 1);
}
