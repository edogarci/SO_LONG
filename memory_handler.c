/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogarci <edogarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:59:38 by edogarci          #+#    #+#             */
/*   Updated: 2023/12/05 21:38:28 by edogarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "general.h"
#include "load_map_utils.h"
#include "error_handler.h"
#include "map_checks.h"
#include "map_handler.h"
#include "memory_handler.h"
#include "memory_handler.h"
#include "game_handler.h"
#include "structs_definitions.h"
#include "itoa.h"

/*
Free allocated memory for object map (O_MAP)
*/
void	f_free_omap(t_map **o_map)
{
	t_cell	*dummy;
	t_cell	*nxt;

	if (*o_map == NULL)
		return ;
	dummy = (*o_map)->data;
	while (dummy != NULL)
	{
		nxt = dummy->next;
		free(dummy);
		dummy = NULL;
		dummy = nxt;
	}
	free(*o_map);
}

/*
Free allocated memory for map variable
*/
void	f_free_map(char **map)
{
	if ((*map) != NULL)
		free(*map);
}
