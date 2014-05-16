/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/18 04:48:48 by hestela           #+#    #+#             */
/*   Updated: 2014/01/20 20:51:13 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "filler.h"

int			ft_find_case_1(t_cord *piece, t_play env)
{
	piece->y++;
	while (piece->x < env.p_size.col)
	{
		while (piece->y < env.p_size.row)
		{
			if (env.piece[piece->y][piece->x] == 1)
				return (1);
			piece->y++;
		}
		piece->y = 0;
		piece->x++;
	}
	return (0);
}

int			ft_find_case_2(t_cord *piece, t_play env)
{
	piece->y--;
	while (piece->x >= 0)
	{
		while (piece->y >= 0)
		{
			if (env.piece[piece->y][piece->x] == 1)
				return (1);
			piece->y--;
		}
		piece->y = env.p_size.row - 1;
		piece->x--;
	}
	return (0);
}

int			ft_find_case_3(t_cord *piece, t_play env)
{
	piece->x--;
	while (piece->y < env.p_size.row)
	{
		while (piece->x >= 0)
		{
			if (env.piece[piece->y][piece->x] == 1)
				return (1);
			piece->x--;
		}
		piece->x = env.p_size.col - 1;
		piece->y++;
	}
	return (0);
}

int			ft_find_case_4(t_cord *piece, t_play env)
{
	piece->x++;
	while (piece->y >= 0)
	{
		while (piece->x < env.p_size.col)
		{
			if (env.piece[piece->y][piece->x] == 1)
				return (1);
			piece->x++;
		}
		piece->x = 0;
		piece->y--;
	}
	return (0);
}

int			ft_check_place(t_play env, t_cord piece, t_cord map)
{
	int		m_x;
	int		m_y;
	int		x;
	int		y;

	x = -1;
	m_x = map.x - piece.x;
	while (x++ < env.p_size.col)
	{
		y = 0;
		m_y = map.y - piece.y;
		if (map.x - piece.x < 0 || m_y + env.p_size.row > env.m_size.row
			|| m_y < 0 || (map.x - piece.x) + env.p_size.col > env.m_size.col)
			return (0);
		while (y < env.p_size.row)
		{
			if (env.map[m_y][m_x] != 0 && (x != piece.x || y != piece.y)
				&& env.piece[y][x] == 1)
				return (0);
			m_y++;
			y++;
		}
		m_x++;
	}
	return (1);
}
