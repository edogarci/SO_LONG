/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks_04.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogarci <edogarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:59:24 by edogarci          #+#    #+#             */
/*   Updated: 2023/12/11 12:20:49 by edogarci         ###   ########.fr       */
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

void	f_check_valid_textures(t_mlx_data *data)
{
	char		*path;
	char		*cell_type;
	int			img_w;
	int			img_h;

	cell_type = "10CEP";
	path = "textures/1.xpm";
	while (*cell_type != '\0')
	{
		if (*cell_type == '0')
			path = "textures/0.xpm";
		else if (*cell_type == 'C')
			path = "textures/C.xpm";
		else if (*cell_type == 'E')
			path = "textures/E.xpm";
		else if (*cell_type == 'P')
			path = "textures/P.xpm";
		if (mlx_xpm_file_to_image(data->conn, path, &img_w, &img_h) == NULL)
		{
			f_show_error(17);
			f_destroy_everything(data);
		}
		cell_type++;
	}
}
