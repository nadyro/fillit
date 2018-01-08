/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azybert <azybert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 03:48:07 by azybert           #+#    #+#             */
/*   Updated: 2017/07/23 23:55:45 by azybert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

static char	**allocation(int taille)
{
	int		tmp;
	char	**agencement;

	if ((agencement = malloc(sizeof(*agencement) * (taille + 2))) == NULL)
		exit(0);
	agencement[taille + 1] = NULL;
	tmp = -1;
	while (++tmp <= taille)
		if ((agencement[tmp] =
					malloc(sizeof(**agencement) * (taille + 1))) == NULL)
			exit(0);
	return (agencement);
}

static void	tab_set(char **agencement, int taille)
{
	int	tmp;
	int	tmp2;

	tmp = -1;
	while (++tmp <= taille)
	{
		tmp2 = -1;
		while (++tmp2 <= taille)
		{
			if (tmp != taille && tmp2 != taille)
				agencement[tmp][tmp2] = '.';
			else
				agencement[tmp][tmp2] = '\0';
		}
	}
}

char		**initialisation(int taille)
{
	char	**agencement;

	agencement = allocation(taille);
	tab_set(agencement, taille);
	return (agencement);
}
