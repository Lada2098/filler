/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekans <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 17:28:11 by gekans            #+#    #+#             */
/*   Updated: 2020/10/27 17:28:13 by gekans           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	assign_players(t_filler *game)
{
	char	*line;
	int		i;

	if (!get_next_line(STDIN_FILENO, &line))
		exit(0);
	i = 0;
	while (line[i] && line[i] != 'p')
		i++;
	if (line[i + 1] == '1')
	{
		game->me = 'o';
		game->opponent = 'x';
	}
	else
	{
		game->me = 'x';
		game->opponent = 'o';
	}
	free(line);
}

void	get_map_size(t_filler *game)
{
	char	*line;
	int		i;

	i = 0;
	if (!get_next_line(STDIN_FILENO, &line))
		exit(0);
	while (!ft_isdigit(line[i]))
		i++;
	game->x = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	game->y = ft_atoi(&line[i + 1]);
	free(line);
}

void	get_map(t_filler *game)
{
	char	*line;
	int		i;

	i = 0;
	game->map = (char**)malloc(sizeof(char*) * (game->x + 1));
	get_next_line(STDIN_FILENO, &line);
	free(line);
	i = 0;
	while (i < game->x)
	{
		get_next_line(STDIN_FILENO, &line);
		game->map[i] = ft_strdup(line + 4);
		free(line);
		i++;
	}
	game->map[i] = NULL;
}

void	get_piece(t_filler *game)
{
	char	*line;
	int		i;
	int		size;

	i = 0;
	get_next_line(STDIN_FILENO, &line);
	while (line[i] && !ft_isdigit(line[i]))
		i++;
	if (line[i] == '0')
		size = 0;
	else
		size = ft_atoi(&line[i]);
	free(line);
	game->piece = (char**)malloc(sizeof(char*) * (size + 1));
	i = 0;
	while (i < size)
	{
		get_next_line(STDIN_FILENO, &line);
		game->piece[i] = ft_strdup(line);
		free(line);
		i++;
	}
	game->piece[i] = NULL;
}

void	initialize_turn(t_filler *game)
{
	get_map_size(game);
	get_map(game);
	get_piece(game);
}
