/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azybert <azybert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 06:28:07 by azybert           #+#    #+#             */
/*   Updated: 2017/07/23 23:52:25 by azybert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

static void	cancel(int x, int y, t_noeud *noeud, char **agencement)
{
	int	boucle;
	int	depx;
	int	depy;

	boucle = -1;
	while (++boucle < 4)
	{
		depx = noeud->piece->xpos[boucle] - noeud->piece->xpos[0];
		depy = noeud->piece->ypos[boucle] - noeud->piece->ypos[0];
		agencement[x + depx][y + depy] = '.';
	}
}

static int	placement(int x, int y, t_noeud *noeud, char **agencement)
{
	int	boucle;
	int depx;
	int depy;

	boucle = -1;
	while (++boucle < 4)
	{
		depx = noeud->piece->xpos[boucle] - noeud->piece->xpos[0];
		depy = noeud->piece->ypos[boucle] - noeud->piece->ypos[0];
		if (x + depx < 0 || y + depy < 0 ||
				agencement[x + depx][y + depy] != '.')
			return (0);
	}
	boucle = -1;
	while (++boucle < 4)
	{
		depx = noeud->piece->xpos[boucle] - noeud->piece->xpos[0];
		depy = noeud->piece->ypos[boucle] - noeud->piece->ypos[0];
		agencement[x + depx][y + depy] = noeud->piece->lettre;
	}
	return (1);
}

static int	recursive(t_noeud *noeud, char **agencement, int taille)
{
	int x;
	int	y;

	if (noeud == NULL)
		return (1);
	y = -1;
	while (++y < taille)
	{
		x = -1;
		while (++x < taille)
		{
			if (placement(x, y, noeud, agencement) == 1)
			{
				if (recursive(noeud->next, agencement, taille) == 0)
					cancel(x, y, noeud, agencement);
				else
					return (1);
			}
		}
	}
	return (0);
}

char		**easy_algo(t_liste *liste, int taille)
{
	int		rec;
	char	**agencement;

	rec = -1;
	while (rec != 1)
	{
		agencement = initialisation(taille);
		rec = recursive(liste->first, agencement, taille);
		taille++;
	}
	return (agencement);
}
