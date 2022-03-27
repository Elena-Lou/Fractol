/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:43:46 by elouisia          #+#    #+#             */
/*   Updated: 2022/03/23 17:32:11 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	keys_init(t_ptr *win)
{
	win->keys.u_d = 0;
	win->keys.l_r = 0;
	win->keys.zoom = 1;
	win->keys.x_pos = 0;
	win->keys.y_pos = 0;
}

int	close_window(t_ptr *win)
{
	mlx_destroy_image(win->mlx_ptr, win->img.img);
	mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	mlx_destroy_display(win->mlx_ptr);
	free(win->mlx_ptr);
	exit (0);
}

void	key_moves(int key, t_ptr *win)
{
	blackout(win);
	if (key == XK_Right)
		win->keys.l_r += 0.2 / win->keys.zoom;
	else if (key == XK_Left)
		win->keys.l_r -= 0.2 / win->keys.zoom;
	else if (key == XK_Up)
		win->keys.u_d += 0.2 / win->keys.zoom;
	else if (key == XK_Down)
		win->keys.u_d -= 0.2 / win->keys.zoom;
	else if (key == XK_a)
		win->keys.zoom *= 1.5;
	else if (key == XK_z)
		win->keys.zoom *= 0.5;
	else if (key == XK_space)
		keys_init(win);
	if (win->frac.julia == 1)
		julia(win);
	else
		mandelbrot(win);
}

int	key_check(int key, t_ptr *win)
{
	if (key == XK_Escape)
		close_window(win);
	else
		key_moves(key, win);
	return (0);
}

int	mouse_zoom(int key, int x, int y, t_ptr *win)
{
	win->keys.x_pos = x;
	win->keys.y_pos = y;
	if (key == 4)
		win->keys.zoom *= 1.5;
	else if (key == 5)
	{
		blackout(win);
		win->keys.zoom *= 0.5;
	}	
	if (win->frac.julia == 1)
		julia(win);
	else
		mandelbrot(win);
	return (0);
}
