/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   explore.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/19 20:02:48 by hestela           #+#    #+#             */
/*   Updated: 2014/01/20 08:58:28 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "filler.h"

int			ft_find_place_1(t_play env, t_cord piece)
{
	t_cord		map;

	map.x = 0;
	while (map.x < env.m_size.col)
	{
		map.y = 0;
		while (map.y < env.m_size.row)
		{
			if (env.map[map.y][map.x] == env.play_num)
			{
				if (ft_check_place(env, piece, map))
				{
					ft_printf("%d %d\n", map.y - piece.y, map.x - piece.x);
					return (1);
				}
			}
			map.y++;
		}
		map.x++;
	}
	return (0);
}

int			ft_find_place_2(t_play env, t_cord piece)
{
	t_cord		map;

	map.y = 0;
	while (map.y < env.m_size.row)
	{
		map.x = env.m_size.col - 1;
		while (map.x >= 0)
		{
			if (env.map[map.y][map.x] == env.play_num)
			{
				if (ft_check_place(env, piece, map))
				{
					ft_printf("%d %d\n", map.y - piece.y, map.x - piece.x);
					return (1);
				}
			}
			map.x--;
		}
		map.y++;
	}
	return (0);
}

int			ft_find_place_4(t_play env, t_cord piece)
{
	t_cord		map;

	map.x = env.m_size.col - 1;
	while (map.x >= 0)
	{
		map.y = env.m_size.row - 1;
		while (map.y >= 0)
		{
			if (env.map[map.y][map.x] == env.play_num)
			{
				if (ft_check_place(env, piece, map))
				{
					ft_printf("%d %d\n", map.y - piece.y, map.x - piece.x);
					return (1);
				}
			}
			map.y--;
		}
		map.x--;
	}
	return (0);
}

int			ft_find_place_3(t_play env, t_cord piece)
{
	t_cord		map;

	map.y = env.m_size.row - 1;
	while (map.y >= 0)
	{
		map.x = 0;
		while (map.x < env.m_size.col)
		{
			if (env.map[map.y][map.x] == env.play_num)
			{
				if (ft_check_place(env, piece, map))
				{
					ft_printf("%d %d\n", map.y - piece.y, map.x - piece.x);
					return (1);
				}
			}
			map.x++;
		}
		map.y--;
	}
	return (0);
}
