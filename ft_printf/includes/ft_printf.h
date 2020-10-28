/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gekans <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 14:04:41 by gekans            #+#    #+#             */
/*   Updated: 2020/10/28 14:04:45 by gekans           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef enum		e_length
{
	LENGTH_DEFAULT,
	LENGTH_L,
	LENGTH_LL,
	LENGTH_BIGL,
	LENGTH_H,
	LENGTH_HH,
}					t_length;

typedef struct		s_printf
{
	int			result;
	const char	*format;
	va_list		ap;
	int			flag_minus;
	int			flag_plus;
	int			flag_hash;
	int			flag_zero;
	int			flag_space;
	int			width;
	int			precision;
	t_length	length;
	char		type;
	char		first_sign;
}					t_printf;

int					ft_printf(const char *format, ...);

void				pr_putchar(t_printf *pr, char c);
void				pr_while(t_printf *pr);
void				pr_read_specific(t_printf *pr);
void				pr_read_flags(t_printf *pr);
void				pr_output(t_printf *pr);
void				pr_output_type_d(t_printf *pr);
void				pr_putstr_reverse(t_printf *pr, char *buf);
void				pr_putstr_repeat(t_printf *pr, int n, char c);
void				pr_output_type_u(t_printf *pr);
void				pr_output_type_с(t_printf *pr);
void				pr_output_type_s(t_printf *pr);
void				pr_output_type_o(t_printf *pr);
void				pr_output_type_x(t_printf *pr);
void				pr_output_type_percent(t_printf *pr);
void				pr_putstr(t_printf *pr, char *buf);
void				pr_putstr_precision(t_printf *pr, char *buf, int n);
void				pr_output_type_f(t_printf *pr);
unsigned long long	pr_pow10(int n);

#endif
