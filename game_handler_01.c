/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_handler_01.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogarci <edogarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:58:56 by edogarci          #+#    #+#             */
/*   Updated: 2023/12/11 12:16:12 by edogarci         ###   ########.fr       */
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
Initialize game
*/
void	f_init_game(t_mlx_data *data, t_map *map)
{
	t_cell	*cell;

	cell = map->data;
	while (cell != NULL)
	{
		f_put_img_in_win(data, cell, cell->status);
		cell = cell->next;
	}
}

/*
Get window size based on map width and height
*/
void	f_get_win_size(t_map *map, int *w, int *h)
{
	int	tile_size;

	tile_size = 32;
	*w = map->map_w * tile_size;
	*h = map->map_h * tile_size;
}

/*
Move player to next position
*/
void	f_move_player(int key, t_map **map, t_mlx_data *data)
{
	int		player_x;
	int		player_y;
	t_cell	*curr;
	t_cell	*new;

	f_set_player_xy(&player_x, &player_y, key, map);
	new = (*map)->data;
	while (new->x != player_x || new->y != player_y)
		new = new->next;
	curr = (*map)->data;
	while (curr->status != 'P')
		curr = curr->next;
	if (new->status == '1')
		return ;
	else if (new->status == 'C')
		(*map)->num_collect--;
	else if (new->status == 'E')
	{
		if ((*map)->num_collect == 0)
			f_destroy_everything(data);
		return ;
	}
	f_set_cells_new_values(curr, new, map, &(data->moves_count));
	f_put_img_in_win(data, curr, curr->status);
	f_put_img_in_win(data, new, new->status);
}

/*
Handle events when a key is pressed
*/
int	f_handle_input(int keysym, t_mlx_data *data)
{
	if (keysym == XK_ESCAPE)
	{
		f_print_msg("Tecla (ESC) pulsada. Juego terminado.\n");
		f_destroy_everything(data);
	}
	else if (keysym == XK_W || keysym == XK_S || keysym == XK_A
		|| keysym == XK_D || keysym == XK_UP || keysym == XK_DOWN
		|| keysym == XK_LEFT || keysym == XK_RIGHT)
		f_move_player(keysym, data->map, data);
	return (0);
}

/*
Initialize game from loaded map
*/
void	f_start_game(t_map	*o_map)
{
	t_mlx_data	mlx;

	mlx.moves_count = 0;
	mlx.conn = mlx_init();
	if (mlx.conn == NULL)
		return (f_show_error(15));
	f_get_win_size(o_map, &(mlx.win_w), &(mlx.win_h));
	mlx.win = mlx_new_window(mlx.conn, mlx.win_w, mlx.win_h, "My Game");
	if (mlx.win == NULL)
	{
		free(mlx.conn);
		return (f_show_error(15));
	}
	mlx.map = &o_map;
	f_check_valid_textures(&mlx);
	mlx_key_hook(mlx.win, f_handle_input, &mlx);
	mlx_hook(mlx.win, 17, 0, f_close_window, &mlx);
	f_init_game(&mlx, o_map);
	mlx_loop(mlx.conn);
}
