/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekans <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 16:27:16 by gekans            #+#    #+#             */
/*   Updated: 2020/10/27 16:27:20 by gekans           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check(t_filler *game, int x, int y, int *placed)
{
	if (x < 0 || y < 0 || x >= game->x || y >= game->y)
		return (0);
	else if (game->map[x][y] == game->opponent ||
			game->map[x][y] == ft_toupper(game->opponent))
		return (0);
	else if (*placed && (game->map[x][y] == game->me ||
			game->map[x][y] == ft_toupper(game->me)))
		return (0);
	else if (game->map[x][y] == game->me ||
			game->map[x][y] == ft_toupper(game->me))
		*placed = 1;
	return (1);
}

int		place_piece(t_filler *game, int top_x, int top_y)
{
	int		placed;
	int		x;
	int		y;

	x = 0;
	y = 0;
	placed = 0;
	while (game->piece[x])
	{
		y = 0;
		while (game->piece[x][y])
		{
			if (game->piece[x][y] == '*')
				if (!check(game, top_x + x, top_y + y, &placed))
					return (0);
			y++;
		}
		x++;
	}
	if (placed == 0)
		return (0);
	return (1);
}

int		*is_valid_move(t_filler *game, int i, int j)
{
	int	*ret;
	int x;
	int y;

	ret = malloc(sizeof(int) * 2);
	x = 0;
	while (game->piece[x])
	{
		y = 0;
		while (game->piece[x][y])
		{
			if (game->piece[x][y] == '*')
				if (place_piece(game, i - x, j - y))
				{
					ret[0] = i - x;
					ret[1] = j - y;
					return (ret);
				}
			y++;
		}
		x++;
	}
	return (NULL);
}

t_list	*get_legal_moves(t_filler *game)
{
	t_list	*moves;
	int		x;
	int		y;
	int		*ret;

	moves = NULL;
	x = 0;
	while (x < game->x)
	{
		y = 0;
		while (y < game->y && game->map[x][y])
		{
			if ((ret = is_valid_move(game, x, y)))
			{
				ft_lstadd(&moves, ft_lstnew((int[]) {ret[0], ret[1]}, 8));
				free(ret);
				ret = NULL;
			}
			y++;
		}
		x++;
	}
	return (moves);
}
