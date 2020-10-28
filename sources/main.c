/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekans <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 16:27:32 by gekans            #+#    #+#             */
/*   Updated: 2020/10/27 16:27:34 by gekans           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_array(char ***src)
{
	char	**arr;
	int		i;

	arr = *src;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	*src = NULL;
}

int		play(t_state *game)
{
	t_list	*moves;

	initialize_turn(game);
	moves = get_legal_moves(game);
	if (!moves)
	{
		write(1, "0 0\n", 4);
		exit(1);
	}
	make_move(game, moves);
	free_array(&(game->map));
	free_array(&(game->piece));
	return (1);
}

int		main(void)
{
	t_state	*game;

	game = malloc(sizeof(t_state));
	assign_players(game);
	while (play(game))
		continue ;
	return (0);
}
