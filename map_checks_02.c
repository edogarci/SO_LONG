/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks_02.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogarci <edogarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:59:19 by edogarci          #+#    #+#             */
/*   Updated: 2023/12/05 21:38:02 by edogarci         ###   ########.fr       */
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
Check if first/last line is fully closed
returns 0 if ok
returns 1 if not
*/
int	f_check_first_last_closed(char **map, int *h)
{
	while (*(*map) != '\n')
	{
		if (*(*map) != '1')
			return (f_show_error(13), 1);
		(*map)++;
	}
	(*map)++;
	(*h)--;
	return (0);
}

/*
check if lines in the middle start and finish
with a wall
returns 0 if ok
returns 1 if not
*/
int	f_check_middle_lines_closed(char **map, int *h)
{
	char	prev;

	if (*(*map) != '1')
		return (f_show_error(13), 1);
	(*map)++;
	while ((*(*map) != '\0') && ((*h) > 1))
	{
		while (*(*map) != '\n')
		{
			prev = *(*map);
			(*map)++;
		}
		if (prev != '1')
			return (f_show_error(13), 1);
		(*map)++;
		(*h)--;
	}
	return (0);
}

/*
Check if map is closed by walls.
returns 0 if ok
returns 1 if not
*/
int	f_check_map_is_closed(char *map)
{
	int	w;
	int	h;

	f_get_map_w_h(map, &w, &h);
	if (f_check_first_last_closed(&map, &h) == 1)
		return (1);
	if (f_check_middle_lines_closed(&map, &h) == 1)
		return (1);
	if (f_check_first_last_closed(&map, &h) == 1)
		return (1);
	return (0);
}

/*
get new cell after move while exploring paths
*/
void	f_get_new(t_cell *curr, t_cell **new, t_cell *data, int move)
{
	int	new_x;
	int	new_y;

	new_x = curr->x;
	new_y = curr->y;
	if (move == 0)
		new_y = curr->y - 1;
	else if (move == 1)
		new_x = curr->x - 1;
	else if (move == 2)
		new_y = curr->y + 1;
	else if (move == 3)
		new_x = curr->x + 1;
	while ((data->x != new_x) || (data->y != new_y))
		data = data->next;
	(*new) = data;
}

/*
Check next position while exploring valid paths
returns 0 if OK
returns 1 if not
*/
void	f_explore_paths(t_cell *curr, t_map *o_map, int *elmnts, t_cell **seen)
{
	int		move;
	char	celltype;
	t_cell	*new;

	f_add_to_seen(curr, seen);
	move = 0;
	new = NULL;
	while (move < 4 && *elmnts > 0)
	{
		if (f_is_move_possible(move, curr, o_map) == 0
			&& f_check_if_seen(curr, seen, move) == 0)
		{
			f_get_new(curr, &new, o_map->data, move);
			celltype = new->status;
			if (celltype == '0')
				f_explore_paths(new, o_map, elmnts, seen);
			else if (celltype == 'C' || celltype == 'E')
			{
				(*elmnts)--;
				f_explore_paths(new, o_map, elmnts, seen);
			}
		}
		move++;
	}
}
