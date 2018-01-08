/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_use.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azybert <azybert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 08:41:04 by azybert           #+#    #+#             */
/*   Updated: 2017/07/23 23:57:49 by azybert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

t_noeud	*add_noeud(t_noeud *noeud)
{
	t_piece	*new_piece;
	t_noeud	*new_noeud;

	if ((new_piece = malloc(sizeof(*new_piece))) == NULL)
		exit(0);
	if ((new_noeud = malloc(sizeof(*new_noeud))) == NULL)
		exit(0);
	new_noeud->piece = new_piece;
	new_noeud->next = NULL;
	noeud->next = new_noeud;
	noeud = noeud->next;
	return (noeud);
}

t_liste	*struct_creat(char *file)
{
	int		fd;
	t_liste	*liste;
	t_noeud	*noeud;
	t_piece	*piece;

	if ((liste = malloc(sizeof(*liste))) == NULL)
		exit(0);
	if ((noeud = malloc(sizeof(*noeud))) == NULL)
		exit(0);
	if ((piece = malloc(sizeof(*piece))) == NULL)
		exit(0);
	noeud->piece = piece;
	noeud->next = NULL;
	liste->first = noeud;
	fd = open(file, O_RDONLY);
	file_check(fd, liste);
	close(fd);
	return (liste);
}
