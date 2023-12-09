/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks_01.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogarci <edogarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:59:15 by edogarci          #+#    #+#             */
/*   Updated: 2023/12/05 21:37:46 by edogarci         ###   ########.fr       */
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

/*
Counts total amount of C/E/P cells
There should be at least one of each
*/
int	f_check_cep_amount(char *map)
{
	int		c_counter;
	int		e_counter;
	int		p_counter;

	c_counter = 0;
	p_counter = 0;
	e_counter = 0;
	while (*map != '\0')
	{
		if (*map == 'C')
			c_counter++;
		if (*map == 'E')
			e_counter++;
		if (*map == 'P')
			p_counter++;
		map++;
	}
	if (e_counter != 1)
		return (f_show_error(9), 1);
	if (c_counter <= 0)
		return (f_show_error(10), 1);
	if (p_counter != 1)
		return (f_show_error(11), 1);
	return (0);
}

/*
Check if cell value is correcto or not
Possible values are:
	0 -> space
	1 -> wall
	C -> collectable
	E -> exit
	P -> player initial pos.
Returns 0 if OK
Returns 1 if not OK
*/
int	f_check_cell_values(char *map)
{
	char	cell;

	cell = *map;
	while (cell != '\0')
	{
		if (cell != '0' && cell != '1' && cell != 'C' && cell != 'E'
			&& cell != 'P' && cell != '\n')
			return (f_show_error(7), 1);
		cell = *(map++);
	}
	return (0);
}

/*
Get map first line length
*/
int	f_get_first_line_len(char *map)
{
	int		first_len;

	first_len = 0;
	while (*map != '\n')
	{
		first_len++;
		map++;
	}
	return (first_len);
}

/*
Check if the map is rectangular...
Returns 0 if OK
Returns 1 if not
*/
int	f_check_is_rectangular(char *map)
{
	int		first_len;
	int		line_len;

	first_len = f_get_first_line_len(map);
	line_len = 0;
	while (*map != '\0')
	{
		if (*map == '\n')
		{
			if (line_len == first_len)
				line_len = 0;
			else
				return (f_show_error(12), 1);
		}
		else
			line_len++;
		map++;
	}
	return (0);
}

/*
Check map integrity:
There is at least one exit
There is at least one object
etc...
Returns 0 if OK
Returns 1 if not OK
*/
int	f_check_map_integrity(char *map)
{
	if (f_check_cell_values(map) == 1
		|| f_check_cep_amount(map) == 1
		|| f_check_is_rectangular(map) == 1
		|| f_check_map_is_closed(map) == 1)
		return (f_show_error(8), 1);
	return (0);
}
