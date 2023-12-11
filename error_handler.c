/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogarci <edogarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:58:41 by edogarci          #+#    #+#             */
/*   Updated: 2023/12/11 12:10:45 by edogarci         ###   ########.fr       */
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

void	f_print_msg(char *msg)
{
	int	pos;

	pos = 0;
	while (msg[pos] != '\0')
	{
		write(1, &msg[pos], 1);
		pos++;
	}
}

void	f_show_error(int msg)
{
	f_print_msg("Error\n");
	if (msg <= 9)
	{
		if (msg == 1)
			f_print_msg("El mapa no se cargó correctamente.\n");
		else if (msg == 2)
			f_print_msg("Numero de parametros incorrecto.\n");
		else if (msg == 3)
			f_print_msg("No se pudo reservar memoria para crear el path.\n");
		else if (msg == 4)
			f_print_msg("No se pudo abrir el fichero '*.BER' indicado.\n");
		else if (msg == 5)
			f_print_msg("No se pudo reservar memoria para cargar el mapa.\n");
		else if (msg == 6)
			f_print_msg("El mapa esta vacío.\n");
		else if (msg == 7)
			f_print_msg("Se ha encontrado un caracter invalido en el mapa.\n");
		else if (msg == 8)
			f_print_msg("El mapa esta mal construido.\n");
		else if (msg == 9)
			f_print_msg("El mapa tiene un numero incorrecto de salidas.\n");
	}
	else
		f_show_error_continued(msg);
}

void	f_show_error_continued(int msg)
{
	if (msg <= 18)
	{
		if (msg == 10)
			f_print_msg("El mapa no tiene coleccionables.\n");
		else if (msg == 11)
			f_print_msg("En el mapa no hay jugador (P).\n");
		else if (msg == 12)
			f_print_msg("El mapa no es rectangular.\n");
		else if (msg == 13)
			f_print_msg("El mapa no esta completamente cerrado por muros.\n");
		else if (msg == 14)
			f_print_msg("Error reservando memoria para crear objeto mapa.\n");
		else if (msg == 15)
			f_print_msg("Error iniciando MiniLibX.\n");
		else if (msg == 16)
			f_print_msg("No hay un camino valido a alguno de los elementos.\n");
		else if (msg == 17)
			f_print_msg("Error al cargar alguna de las texturas.\n");
	}
}
