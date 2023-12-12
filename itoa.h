/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edogarci <edogarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:04:32 by edogarci          #+#    #+#             */
/*   Updated: 2023/12/04 16:06:11 by edogarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITOA_H
# define ITOA_H

# include "include/memory_leaks.h"



char	*ft_itoa(int n);
void	iterate_number(int n, int len, char *str);
char	translate_to_char(int digit);
int		get_number_len(int n);

#endif