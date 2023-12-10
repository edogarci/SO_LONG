/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogarci <edogarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 16:29:37 by edogarci          #+#    #+#             */
/*   Updated: 2023/05/10 17:10:51 by edogarci         ###   ########.fr       */
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

int	get_number_len(int n)
{
	int		cont;
	char	neg;

	neg = ' ';
	if (n < 0)
		neg = 'X';
	cont = 1;
	while (n / 10 != 0)
	{
		n = n / 10;
		cont++;
	}
	if (neg == 'X')
		return (cont + 1);
	else
		return (cont);
}

char	translate_to_char(int digit)
{
	char	ascii;

	if (digit < 0)
		digit = digit * -1;
	ascii = digit + '0';
	return (ascii);
}

void	iterate_number(int n, int len, char *str)
{
	char	ascii_num;
	char	neg_flag;

	neg_flag = ' ';
	if (n < 0)
		neg_flag = 'X';
	str[len] = '\0';
	len--;
	while ((neg_flag == ' ' && len >= 0)
		|| (neg_flag == 'X' && len > 0))
	{
		ascii_num = translate_to_char(n % 10);
		str[len] = ascii_num;
		n = n / 10;
		len--;
	}
	if (neg_flag == 'X')
		str[len] = '-';
}

char	*ft_itoa(int n)
{
	char	*ptr_ret;
	int		len;

	len = get_number_len(n);
	ptr_ret = malloc((len + 1) * sizeof(char));
	if (!ptr_ret)
		return (NULL);
	iterate_number(n, len, ptr_ret);
	return (ptr_ret);
}
