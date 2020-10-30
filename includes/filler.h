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

typedef struct		s_filler
{
	char			**map;
	char			**piece;
	char			me;
	char			opponent;
	int				x;
	int				y;
}					t_filler;

int					main(void);
int					play(t_filler *game);

void				assign_players(t_filler *game);
void				get_map_size(t_filler *game);
void				get_map(t_filler *game);
void				get_piece(t_filler *game);
void				initialize_turn(t_filler *game);

int					check(t_filler *game, int x, int y, int *placed);
int					place_piece(t_filler *game, int top_x, int top_y);
int					*is_valid_move(t_filler *game, int i, int j);
t_list				*get_legal_moves(t_filler *game);

int					is_best_move(int *pos, int oldx, int oldy, int *dir);
int					*max_distance(t_filler *game, int i, int j);
int					*get_best_direction(t_filler *game, int avg_x, int avg_y);
void				make_move(t_filler *game, t_list *moves);

#endif
