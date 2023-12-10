/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks_03.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogarci <edogarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:59:24 by edogarci          #+#    #+#             */
/*   Updated: 2023/12/07 13:15:51 by edogarci         ###   ########.fr       */
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
Free all allocted memory for 'seen' cell list
created while the 'exploring valid paths' check
*/
void	f_free_seen(t_cell **seen)
{
	t_cell	*dummy;

	if (*seen == NULL)
		return ;
	while (*seen != NULL)
	{
		dummy = (*seen)->next;
		free(*seen);
		*seen = dummy;
	}
}

/*
Check if there exist a valid path from player to
every collectable and exit
returns 0 if OK
returns 1 if not
*/
int	f_check_valid_paths(t_map *o_map)
{
	int		elmnts;
	t_cell	*curr;
	t_cell	*seen;

	printf("2\n");
	elmnts = o_map->num_collect + 1;
	curr = o_map->data;
	while (curr->status != 'P')
		curr = curr->next;
	seen = NULL;
	f_explore_paths(curr, o_map, &elmnts, &seen);
	f_free_seen(&seen);
	if (elmnts == 0)
		return (0);
	else
		return (f_show_error(16), 1);
}

/*
Check if move is possible
return 0 if OK
return 1 if not
*/
int	f_is_move_possible(int move, t_cell *curr, t_map *o_map)
{
	int	res;

	res = 0;
	if (move == 0)
	{
		if (curr->y == 0)
			res = 1;
	}
	else if (move == 1)
	{
		if (curr->x == 0)
			res = 1;
	}
	else if (move == 2)
	{
		if (curr->y == (o_map->map_h - 1))
			res = 1;
	}
	else if (move == 4)
	{
		if (curr->y == (o_map->map_w - 1))
			res = 1;
	}
	return (res);
}

/*
check if cell has been already seen during exploring paths
*/
int	f_check_if_seen(t_cell *curr, t_cell **seen, int move)
{
	int		new_x;
	int		new_y;
	t_cell	*dummy;

	dummy = (*seen);
	if (dummy == NULL)
		return (0);
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
	while ((new_x != dummy->x) || (new_y != dummy->y))
	{
		dummy = dummy->next;
		if (dummy == NULL)
			return (0);
	}
	return (1);
}

/*
adds cell to seen list
*/
void	f_add_to_seen(t_cell *curr, t_cell **seen)
{
	t_cell	*dummy;

	dummy = *seen;
	if (*seen != NULL)
	{
		while (dummy->next != NULL)
			dummy = dummy->next;
		dummy->next = malloc(1 * (sizeof(t_cell)));
		dummy->next->status = curr->status;
		dummy->next->x = curr->x;
		dummy->next->y = curr->y;
		dummy->next->next = NULL;
	}
	else
	{
		(*seen) = malloc(1 * (sizeof(t_cell)));
		(*seen)->status = curr->status;
		(*seen)->x = curr->x;
		(*seen)->y = curr->y;
		(*seen)->next = NULL;
	}
}
