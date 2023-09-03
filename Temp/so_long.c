/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zabdulza <zabdulza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 15:06:57 by zabdulza          #+#    #+#             */
/*   Updated: 2023/09/03 16:06:32 by zabdulza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*path;
	int		x;
	int		y;
	
	int		pressed;

}t_vars;

int		key_hook(int keycode, t_vars *vars)
{
	vars->pressed++;
	if (keycode == 65307)
	{
		printf("I am exiting\n");
		mlx_destroy_window(vars->mlx, vars->win);	
		exit(0);
	}
	if (keycode == 65362)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->x+32, vars->y+32);
		//mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 300, 300);
		printf("X = %d, Y= %d", vars->x, vars->y);		
		vars->y-= 32;
		//printf("I pressed up\n");	
	}
	if (keycode == 65361)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->x+32, vars->y+32);
		//mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 300, 300);
		printf("X = %d, Y= %d", vars->x, vars->y);		
		vars->x-= 32;
		//printf("I pressed up\n");	
	}
	if (keycode == 65363)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->x+32, vars->y+32);
		//mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 300, 300);
		printf("X = %d, Y= %d", vars->x, vars->y);		
		vars->x+= 32;
		//printf("I pressed up\n");	
	}
	if (keycode == 65364)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img, vars->x+32, vars->y+32);
		//mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 300, 300);
		printf("X = %d, Y= %d", vars->x, vars->y);		
		vars->y+= 32;
		//printf("I pressed up\n");	
	}
	printf("Key was pressed %dx. Key pressed was - %d\n ", vars->pressed, keycode);
	//mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}


int	main()
{
	t_vars	vars;
	int		img_width;
	int		img_height;
	vars.path =  "./texture.xpm";

	vars.x = 100;
	vars.y = 100;
	
	vars.mlx = mlx_init();
	
	vars.win = mlx_new_window(vars.mlx, 700, 700, "42 so long");
	
	vars.img = mlx_xpm_file_to_image(vars.mlx, vars.path, &img_width, &img_height);
	
	
	
	vars.pressed = 0;
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);


	return (0);

}
