/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <mbaron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 08:31:38 by mbaron            #+#    #+#             */
/*   Updated: 2018/01/11 11:22:57 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "grid.h"

int 	init_grid(char **grid, int grid_size)
{
	int		l;
	int		c;
	
	if (!(grid = (char **)malloc(grid_size * sizeof(char *))))
		return (0);
	l = 0;
	while (l < grid_size)
	{
		if (!(grid[l] = (char *)malloc(grid_size * sizeof(char))))
		{
			del_grid(grid, l - 1);
			return (0);
		}
		c = 0;
		while (c < grid_size)
			grid[l][c++] = C_POINT;
		l++;
	}
	return (1);
}

int 	fill_grid(char **grid, int grid_size, int pieces_nb, t_list **bt)
{
	t_list	*tmp;
	t_piece	*piece;
	char	alphabet[27];
	int		t;
	
	ft_strcpy(alphabet, ALPHABET);
	tmp = *bt;
	t = pieces_nb;
	while (tmp)
	{
		piece = (t_piece *)tmp->content;
		grid[piece->l][piece->c] = alphabet[t];
		t--;
		tmp = tmp->next;
	}
	return (1);
}

int 	write_grid(char **grid, int grid_size)
{
	int		l;
	int		c;
	
	l = 0;
	while (l < grid_size)
	{
		c = 0;
		while (c < grid_size)
		{
			ft_putchar(grid[l][c]);
			c++;
		}
		ft_putchar('\n');
		l++;
	}
	return (1);
}

int 	del_grid(char **grid, int grid_size)
{
	int		l;
	
	l = 0;
	while (l < grid_size)
	{
		free(grid[l]);
		grid[l++] = NULL;
	}
	free(grid);
	grid = NULL;
	return (1);
}