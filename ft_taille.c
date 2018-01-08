/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_taille.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azybert <azybert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 08:25:34 by azybert           #+#    #+#             */
/*   Updated: 2017/07/23 23:57:29 by azybert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

int	ft_taille(t_liste *liste)
{
	int		surface;
	int		taille;
	t_noeud	*noeud;

	if ((noeud = malloc(sizeof(*noeud))) == NULL)
		exit(0);
	noeud = liste->first;
	surface = 0;
	taille = 0;
	while (noeud != NULL)
	{
		noeud = noeud->next;
		surface++;
	}
	surface = surface * 4;
	while (taille * taille < surface)
		taille++;
	return (taille);
}
