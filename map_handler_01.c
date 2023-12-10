/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler_01.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogarci <edogarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:59:28 by edogarci          #+#    #+#             */
/*   Updated: 2023/12/05 21:38:14 by edogarci         ###   ########.fr       */
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

/*
Returns current amount of collectables in map
*/
void	f_get_num_collect(char *map, int *amount)
{
	*amount = 0;
	while (*map != '\0')
	{
		if (*map == 'C')
			(*amount)++;
		map++;
	}
}

/*
Returns map width and height
*/
void	f_get_map_w_h(char *map, int *w, int *h)
{
	*w = 0;
	*h = 0;
	while (*map != '\n')
	{
		(*w)++;
		map++;
	}
	if (*w != 0)
		(*h) = 1;
	map++;
	while (*map != '\0')
	{
		if ((*map) == '\n')
			(*h)++;
		map++;
	}
}

/*
Returns current player X,Y
*/
void	f_get_player(char *map, int *x, int *y)
{
	*x = 0;
	*y = 0;
	while (*map != '\0')
	{
		if (*map == '\n')
		{
			(*x) = 0;
			(*y)++;
		}
		else if (*map == 'P')
			break ;
		else
			(*x)++;
		map++;
	}
}

/*
Returns EXIT position (x, y)
*/
void	f_get_exit(char *map, int *x, int *y)
{
	*x = 0;
	*y = 0;
	while (*map != '\0')
	{
		if (*map == '\n')
		{
			(*x) = 0;
			(*y)++;
		}
		else if (*map == 'E')
			break ;
		else
			(*x)++;
		map++;
	}
}

/*
Create an instance of an object map.
Returns object pointer if OK
Returns NULL if not
*/
t_map	*f_create_object_map(char *map)
{
	t_map	*o_map;

	o_map = NULL;
	o_map = malloc(1 * sizeof(t_map));
	if (o_map == NULL)
		return (f_show_error(14), NULL);
	f_get_num_collect(map, &(o_map->num_collect));
	f_get_map_w_h(map, &(o_map->map_w), &(o_map->map_h));
	f_get_player(map, &(o_map->player_x), &(o_map->player_y));
	f_get_exit(map, &(o_map->exit_x), &(o_map->exit_y));
	f_get_cells(map, &(o_map->data));
	return (o_map);
}
