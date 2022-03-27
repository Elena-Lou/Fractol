/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_maths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:11:50 by elouisia          #+#    #+#             */
/*   Updated: 2022/03/23 15:56:10 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	belongs_to_set(t_ptr *win, int x, int y)
{
	double	z_re;
	double	z_im;
	double	tmp;
	int		i;

	i = 0;
	z_re = win->maths.c_re;
	z_im = win->maths.c_im;
	while (i < MAX_ITER)
	{
		tmp = z_re * z_re - z_im * z_im + win->maths.k_re;
		z_im = 2 * z_re * z_im + win->maths.k_im;
		z_re = tmp;
		if ((z_re * z_re) + (z_im * z_im) > 4)
			return (0);
		i++;
		my_mlx_pixel_put(win, x, y, colour_picker(i));
	}
	return (1);
}

void	julia(t_ptr *win)
{
	double	y;
	double	x;

	y = -1;
	while (++y < W_HEIGHT)
	{
		win->maths.c_im = ((win->img.max_im / win->keys.zoom - y
					* (win->img.max_im - win->img.min_im)
					/ (W_WIDTH * win->keys.zoom))) + win->keys.u_d;
		x = -1;
		while (++x < W_WIDTH)
		{
			win->maths.c_re = ((win->img.min_re / win->keys.zoom + x
						* (win->img.max_re - win->img.min_re)
						/ (W_HEIGHT * win->keys.zoom))) + win->keys.l_r;
			belongs_to_set(win, x, y);
		}
	}
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img.img, 0, 0);
}