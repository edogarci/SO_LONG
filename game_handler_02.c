/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_handler_02.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogarci <edogarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:59:01 by edogarci          #+#    #+#             */
/*   Updated: 2023/12/05 21:41:34 by edogarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"
#include "load_map_utils.h"
#include "error_handler.h"
#include "map_checks.h"
#include "map_handler.h"
#include "memory_handler.h"
#include "game_handler.h"
#include "structs_definitions.h"
#include "itoa.h"
#include "mlx/mlx.h"

/*
Put image in the game's window
0 = Free space
1 = Walls
C = Collectables
P = Player
E = Exit
*/
void	f_put_img_in_win(t_mlx_data *data, t_cell *cell, char cell_type)
{
	void	*img;
	char	*path;
	int		img_w;
	int		img_h;

	path = NULL;
	if (cell_type == '1')
		path = "textures/1.xpm";
	else if (cell_type == '0')
		path = "textures/0.xpm";
	else if (cell_type == 'C')
		path = "textures/C.xpm";
	else if (cell_type == 'E')
		path = "textures/E.xpm";
	else if (cell_type == 'P')
		path = "textures/P.xpm";
	img = NULL;
	img = mlx_xpm_file_to_image(data->conn, path, &img_w, &img_h);
	if (img != NULL)
	{
		mlx_put_image_to_window(data->conn, data->win, img,
			(cell->x * 32), (cell->y * 32));
	}
	mlx_destroy_image(data->conn, img);
}

int	f_close_window(t_mlx_data *data)
{
	f_print_msg("Cerra ventana. Juego terminado.\n");
	mlx_destroy_window(data->conn, data->win);
	free(data->conn);
	f_free_omap(data->map);
	exit(1);
}

/*
set new player X,Y
*/
void	f_set_player_xy(int *player_x, int *player_y, int key, t_map **map)
{
	*player_x = (*map)->player_x;
	*player_y = (*map)->player_y;
	if (key == XK_W || key == XK_UP)
		(*player_y)--;
	else if (key == XK_S || key == XK_DOWN)
		(*player_y)++;
	else if (key == XK_A || key == XK_LEFT)
		(*player_x)--;
	else if (key == XK_D || key == XK_RIGHT)
		(*player_x)++;
}

/*
destroy all and close game
*/
void	f_destroy_everything(t_mlx_data *data)
{
	mlx_destroy_window(data->conn, data->win);
	free(data->conn);
	f_free_omap(data->map);
	exit(1);
}

/*
update cells statuses and print total moves done
*/
void	f_set_cells_new_values(t_cell *curr, t_cell *new, t_map **map,
	int *moves)
{
	char	*itoa;

	curr->status = '0';
	new->status = 'P';
	(*map)->player_x = new->x;
	(*map)->player_y = new->y;
	(*moves)++;
	f_print_msg("Movimiento numero: ");
	itoa = ft_itoa((*moves));
	f_print_msg(itoa);
	free(itoa);
	f_print_msg("\n");
}
