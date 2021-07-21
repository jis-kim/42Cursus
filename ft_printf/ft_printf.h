/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 12:30:41 by jiskim            #+#    #+#             */
/*   Updated: 2021/07/09 17:39:16 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
# define INT_TYPE

#ifndef FT_PRINTF_H
//flag -> width(숫자) -> .precision(숫자)
typedef	struct s_format_option
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
}				t_format_option
