/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekans <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 16:27:39 by gekans            #+#    #+#             */
/*   Updated: 2020/10/27 16:38:05 by gekans           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include <stdio.h>
# include <fcntl.h>
# include "ft_printf.h"

typedef struct		s_state
{
	char			**map;
	char			**piece;
	char			me;
	char			opponent;
	int				x;
	int				y;
}					t_state;

/*
**	Main functions
*/

int					main(void);
int					play(t_state *game);

/*
**	Initializers
*/

void				assign_players(t_state *game);
void				get_map_size(t_state *game);
void				get_map(t_state *game);
void				get_piece(t_state *game);
void				initialize_turn(t_state *game);

/*
**	Checkers
*/

int					check(t_state *game, int x, int y, int *placed);
int					place_piece(t_state *game, int top_x, int top_y);
int					*is_valid_move(t_state *game, int i, int j);
t_list				*get_legal_moves(t_state *game);

/*
**	Movers
*/

int					is_best_move(int *pos, int oldx, int oldy, int *dir);
int					*max_distance(t_state *game, int i, int j);
int					*get_best_direction(t_state *game, int avg_x, int avg_y);
void				make_move(t_state *game, t_list *moves);

#endif
