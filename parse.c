/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hestela <hestela@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/17 21:52:31 by hestela           #+#    #+#             */
/*   Updated: 2014/01/18 02:45:27 by hestela          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"
#include "filler.h"

void			ft_get_map_size(int *col, int *row)
{
	char		*str;

	str = NULL;
	ft_gnl(0, &str);
	while (ft_strncmp(str, "Plateau", 7) != 0)
		ft_gnl(0, &str);
	*row = ft_atoi(str + 8);
	*col = ft_atoi(str + 8 + ft_strlen(ft_itoa(*row)));
}

void			ft_get_piece_size(char *str, int *col, int *row)
{
	*row = ft_atoi(str + 6);
	*col = ft_atoi(str + 6 + ft_strlen(ft_itoa(*row)));
}

int				**ft_create_map(int row, int col)
{
	int			**map;
	int			i;

	i = 0;
	map = (int**) malloc(sizeof(*map) * row);
	while (i < row)
	{
		map[i] = (int*) malloc(sizeof(**map) * col);
		i++;
	}
	return (map);
}

char			*ft_get_map(int **map)
{
	char		*str;
	int			col;
	int			row;

	row = 0;
	str = ft_strdup(" ");
	while (ft_strncmp(str, "000", 3) != 0)
		ft_gnl(0, &str);
	while (ft_strncmp(str, "Piece", 5) != 0)
	{
		col = 0;
		while (*(str + col + 4))
		{
			if (*(str + 4 + col) == '.')
				map[row][col] = 0;
			if (*(str + 4 + col) == 'o' || *(str + 4 + col) == 'O')
				map[row][col] = 1;
			if (*(str + 4 + col) == 'x' || *(str + 4 + col) == 'X')
				map[row][col] = 2;
			col++;
		}
		row++;
		ft_gnl(0, &str);
	}
	return (str);
}

void			ft_get_piece(int **map, int lines)
{
	char		*str;
	char		*start;
	int			col;
	int			row;

	row = 0;
	start = NULL;
	str = NULL;
	while (row < lines)
	{
		col = 0;
		str = start;
		ft_gnl(0, &str);
		start = str;
		while (*str)
		{
			if (*str == '.')
				map[row][col] = 0;
			else if (*str == '*')
				map[row][col] = 1;
			col++;
			str++;
		}
		row++;
	}
}
