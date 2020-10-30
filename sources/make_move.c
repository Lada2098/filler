/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekans <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 16:28:02 by gekans            #+#    #+#             */
/*   Updated: 2020/10/27 16:28:04 by gekans           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			is_best_move(int *pos, int oldx, int oldy, int *dir)
{
	int	old;
	int	new;

	new = ft_abs(dir[0] - pos[0]) + ft_abs(dir[1] - pos[1]);
	old = ft_abs(dir[0] - oldx) + ft_abs(dir[1] - oldy);
	return ((new > old));
}

int			*max_distance(t_filler *game, int i, int j)
{
	int	*ret;
	int x;
	int y;

	x = 0;
	ret = malloc(sizeof(int) * 2);
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			if (game->map[x][y] == '.')
				if (is_best_move((int[]){x, y}, ret[0], ret[1], (int[]) {i, j}))
				{
					ret[0] = x;
					ret[1] = y;
				}
			y++;
		}
		x++;
	}
	return (ret);
}

static void	init_params(int *count, int *x, int *y)
{
	*count = 0;
	*x = 0;
	*y = 0;
}

int			*get_best_direction(t_filler *game, int avg_x, int avg_y)
{
	int	count;
	int x;
	int y;

	init_params(&count, &x, &y);
	while (game->map[x])
	{
		while (game->map[x][y])
		{
			if (game->map[x][y] == game->me ||
				game->map[x][y] == ft_toupper(game->me))
			{
				avg_x += x;
				avg_y += y;
				count++;
			}
			y++;
		}
		y = 0;
		x++;
	}
	avg_x /= count;
	avg_y /= count;
	return (max_distance(game, avg_x, avg_y));
}

void		make_move(t_filler *game, t_list *moves)
{
	t_list	*head;
	int		x;
	int		y;
	int		*dir;

	dir = get_best_direction(game, 0, 0);
	x = ((int *)(moves->content))[0];
	y = ((int *)(moves->content))[1];
	head = moves;
	while (moves)
	{
		if (!is_best_move(moves->content, x, y, dir))
		{
			x = ((int *)(moves->content))[0];
			y = ((int *)(moves->content))[1];
		}
		moves = moves->next;
	}
	ft_putnbr(x);
	write(1, " ", 1);
	ft_putnbr(y);
	write(1, "\n", 1);
	free(head);
}
