/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azybert <azybert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 01:01:23 by azybert           #+#    #+#             */
/*   Updated: 2017/07/23 23:55:55 by azybert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void	display(char **agencement)
{
	int i;
	int	j;

	i = -1;
	while (agencement[++i])
	{
		j = -1;
		if (i != 0)
			write(1, "\n", 1);
		while (agencement[++j][i] != '\0')
			write(1, &(agencement[j][i]), 1);
	}
}
