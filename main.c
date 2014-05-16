/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 09:20:41 by hestela           #+#    #+#             */
/*   Updated: 2014/01/20 21:08:20 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <unistd.h>
#include <stdlib.h>
#include "filler.h"	

static int		ft_find_solution(t_play env, int i);
static int		ft_get_player_num(void);
static void		ft_get_functions_1(int (*f[4])(t_play, t_cord));
static void		ft_get_functions_2(int (*g[2])(t_cord*, t_play));

int				main(void)
{
	t_play		env;
	char		*str;
	int			i;

	env.play_num = ft_get_player_num();
	ft_get_map_size(&env.m_size.col, &env.m_size.row);
	env.map = ft_create_map(env.m_size.row, env.m_size.col);
	env.piece = NULL;
	while (ft_find_solution(env, i))
	{
		str = ft_get_map(env.map);
		ft_get_piece_size(str, &env.p_size.col, &env.p_size.row);
		free(str);
		if (env.piece)
			free(env.piece);
		env.piece = ft_create_map(env.p_size.row, env.p_size.col);
		ft_get_piece(env.piece, env.p_size.row);
	}
	ft_printf("%d %d\n", 0, 0);
	free(env.map);
	return (0);
}

static void		ft_get_functions_1(int (*f[4])(t_play, t_cord))
{
	f[0] = &ft_find_place_1;
	f[1] = &ft_find_place_2;
	f[2] = &ft_find_place_3;
	f[3] = &ft_find_place_4;
}

static void		ft_get_functions_2(int (*g[4])(t_cord*, t_play))
{
	g[0] = &ft_find_case_1;
	g[1] = &ft_find_case_2;
	g[2] = &ft_find_case_3;
	g[3] = &ft_find_case_4;
}

static int		ft_find_solution(t_play env, int i)
{
	static int		begin;
	t_cord			piece;
	int				(*f[4])(t_play, t_cord);
	int				(*g[4])(t_cord*, t_play);
	int				j;

	ft_get_functions_1(f);
	ft_get_functions_2(g);
	begin++;
	if (begin == 1)
		return (1);
	i = (begin * 3) % 4;
	j = (begin * 7) % 4;
	ft_random(&piece, j, env);
	while (g[j](&piece, env))
	{
		if (f[i](env, piece))
			return (1);
	}
	return (0);
}

static int		ft_get_player_num(void)
{
	char		*str;

	str = ft_strdup(" ");
	while (ft_strncmp(str, "$$$", 3) != 0)
		ft_gnl(0, &str);
	while (*str != '1' && *str != '2')
		str++;
	return (*str - 48);
}
