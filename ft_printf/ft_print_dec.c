/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 02:59:35 by jiskim            #+#    #+#             */
/*   Updated: 2021/09/21 06:09:10 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static  int get_decimal_len(int n)
{
	int	len;

	len= 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int     ft_print_without_precision(t_format_option *options, int value)
{
    int ret;

    ret = 0;
    if(options->flag_minus)
    {
        //부호 숫자 width
        ret += ft_print_sign();
        ret += ft_print_dec();
        ret += ft_print_space();
    }
    else
    {
        if(options->flag_zero)
        {
            //부호 width 숫자
            ret += ft_print_sign();
            ret += ft_print_zero();
        }
        else
        {
            //width 부호 숫자
            ret += ft_print_space();
            ret += ft_print_sign();
        }
        ret += ft_print_dec();
    }
    return (ret);
}

/**
 * 1. precision이 원래 너비보다 넓으면 앞을 0으로 채운다.
 * 2. 좁으면 그대로
 * 3. width가 원래 너비보다 넓으면 앞을 공백으로 채운다.
 * 4. 좁으면 그대로.
 * 
**/
int     ft_print_dec(t_format_option *options, int value)
{
    int     ret;
    int     zero;
    int     left_space;
    int     right_space;

    ret = 0;
    left_space = 0;
    right_space = 0;
    options->length = get_decimal_len(value);
    if(value < 0 || options->flag_plus || options->flag_space)//부호가 있어요
        options->width -= 1;
    zero = options->precision - options->length;
    if (options->precision < 0 && options->flag_zero && !options->flag_minus)
        zero = options->width - options->length;
    if (options->flag_minus)
        right_space = options->width - options->precision - options->length;
    else
        left_space = options->width - options->precision - options->length;
    ft_print_space(left_space);
    ft_print_sign(options);
    ft_print_zero(zero);
    ft_print_integer(value);
    ft_print_space(right_space);
    return (ret);
}
