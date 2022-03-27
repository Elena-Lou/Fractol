/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:12:24 by elouisia          #+#    #+#             */
/*   Updated: 2022/03/27 14:28:49 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	def_colour_picker(int i)
{
	const int	colours[10] = {0x000, 0x330000, 0x660000, 0x990000,
		0xCC0000, 0xFF0000, 0xFF3333, 0xFF6666, 0xFF9999, 0xFFCCCC};

	i = (i / 20) % 10;
	return (colours[i]);
}

int	blackout(t_ptr *win)
{
	int	y;
	int	x;

	y = 0;
	while (y < W_HEIGHT)
	{
		x = 0;
		while (x < W_WIDTH)
		{
			my_mlx_pixel_put(win, x, y, 0x000);
			x++;
		}
		y++;
	}
	return (0);
}
