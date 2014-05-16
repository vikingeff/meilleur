/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/20 20:57:40 by hestela           #+#    #+#             */
/*   Updated: 2014/01/20 21:04:21 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "filler.h"

void		ft_random(t_cord *piece, int i, t_play env)
{
	if (i == 0)
	{
		piece->x = 0;
		piece->y = -1;
	}
	if (i == 2)
	{
		piece->x = env.p_size.col;
		piece->y = 0;
	}
	if (i == 1)
	{
		piece->x = env.p_size.col - 1;
		piece->y = env.p_size.row;
	}
	if (i == 3)
	{
		piece->x = -1;
		piece->y = env.p_size.row - 1;
	}
}
