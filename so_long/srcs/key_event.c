/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiskim <jiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 00:44:51 by jiskim            #+#    #+#             */
/*   Updated: 2021/12/16 02:39:19 by jiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdio.h>

int key_pressed(int keycode, void *args)
{
	t_component * component = (t_component *)args;
	if (keycode == 53)
	{
		close_window(args); //ㅎㅎ 이게 아니야?ㅎㅎ
		return 1;
	}
	if (keycode == 13) //W - up
		component->y+=64;
	else if (keycode == 0) //A - left
		component->x-=64;
	else if (keycode == 1) //S - down
		component->y-=64;
	else if (keycode == 2) //D - right
		component->x+=64;
	return 1;
}
