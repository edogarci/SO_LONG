/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler_02.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogarci <edogarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:59:33 by edogarci          #+#    #+#             */
/*   Updated: 2023/12/05 21:38:21 by edogarci         ###   ########.fr       */
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
Clear all memory allocated for o_map
in case of error
*/
void	f_clear_omap_data(t_cell ***head)
{
	t_cell	*dummy;
	t_cell	*nxt;

	dummy = **head;
	while (dummy != NULL)
	{
		nxt = dummy->next;
		free(dummy);
		dummy = NULL;
		dummy = nxt;
	}
}

/*
Set X and Y when \n is found
mainly to reduce lines in f_get_cells
*/
void	f_map_is_n(int *x_cont, int *y_cont, char **map)
{
	*x_cont = 0;
	(*y_cont)++;
	(*map)++;
}

/*
set values for dummy cell
*/
void	f_set_dummy(t_cell *dummy, int *x_cont, int *y_cont, char **map)
{
	dummy->x = *x_cont;
	dummy->y = *y_cont;
	dummy->status = **map;
	dummy->next = NULL;
	(*x_cont)++;
	(*map)++;
}

/*
allocate memory for dummy cell
*/
void	f_allocate_dummy(t_cell **dummy)
{
	(*dummy)->next = malloc(1 * sizeof(t_cell));
	(*dummy) = (*dummy)->next;
}

/*
Fill a linked list for cells in map
*/
void	f_get_cells(char *map, t_cell **head)
{
	int		x_cont;
	int		y_cont;
	t_cell	*dummy;

	x_cont = 0;
	y_cont = 0;
	while (*map != '\0')
	{
		if (*map == '\n')
		{
			f_map_is_n(&x_cont, &y_cont, &map);
			continue ;
		}
		if (x_cont == 0 && y_cont == 0)
		{
			*head = malloc(1 * sizeof(t_cell));
			dummy = *head;
		}
		else
			f_allocate_dummy(&dummy);
		if (dummy == NULL)
			return (f_show_error(14), f_clear_omap_data(&head));
		f_set_dummy(dummy, &x_cont, &y_cont, &map);
	}
}
