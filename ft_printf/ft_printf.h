/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:30:41 by jiskim            #+#    #+#             */
/*   Updated: 2021/09/21 06:49:27 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define INT_MIN -2147483648
# define INT_MAX 2147483647
# include "libft/libft.h"
# include <stdarg.h>

/*flag -> width -> .precision*/
typedef struct s_format_option
{
	char	type;
	int		precision;
	int		width;
	int		length;
	int		flag_minus;
	int		flag_zero;
	int		flag_hash;
	int		flag_space;
	int		flag_plus;
}				t_format_option;

void	parse_format(const char **format, t_format_option *options);
int		ft_print_dec(t_format_option *options, int value);
int		ft_print_space(int n);
int		ft_print_zero(int n);

int	ft_print_sign(t_format_option *options, int value);
#endif
