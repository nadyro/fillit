/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azybert <azybert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 01:01:23 by azybert           #+#    #+#             */
/*   Updated: 2017/07/23 23:57:03 by azybert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

static void	check_fill(int *xpos, int *ypos)
{
	int bloc_1;
	int	bloc_2;
	int	bloc_liaisons;

	bloc_1 = -1;
	bloc_liaisons = 0;
	while (++bloc_1 < 4)
	{
		bloc_2 = bloc_1;
		while (++bloc_2 < 4)
		{
			if (xpos[bloc_1] + 1 == xpos[bloc_2]
					&& ypos[bloc_1] == ypos[bloc_2])
				bloc_liaisons++;
			if (ypos[bloc_1] + 1 == ypos[bloc_2]
					&& xpos[bloc_1] == xpos[bloc_2])
				bloc_liaisons++;
		}
	}
	if (bloc_liaisons < 3)
		print_error();
}

static void	struct_fill(int nb_bloc, int y, int x, t_noeud *noeud)
{
	if (nb_bloc == 4)
		print_error();
	noeud->piece->xpos[nb_bloc] = x;
	noeud->piece->ypos[nb_bloc] = y;
}

static void	block_check(char *buffer, t_noeud *noeud)
{
	int line;
	int	char_line;
	int	nb_bloc;

	nb_bloc = -1;
	line = -1;
	while (++line < 4)
	{
		char_line = -1;
		while (++char_line < 4)
		{
			if (*buffer != '.' && *buffer != '#')
				print_error();
			if (*buffer == '#')
				struct_fill(++nb_bloc, line, char_line, noeud);
			buffer++;
		}
		if (*(buffer)++ != '\n')
			print_error();
	}
	check_fill(noeud->piece->xpos, noeud->piece->ypos);
	if (nb_bloc != 3)
		print_error();
}

void		file_check(int fd, t_liste *liste)
{
	int		m;
	int		n;
	char	l;
	char	buffer[BUFSIZE];
	t_noeud *noeud;

	noeud = liste->first;
	l = 'A';
	if ((n = read(fd, buffer, BUFSIZE)) % 21 != 20 || n > 545)
		print_error();
	m = -1;
	while ((++m) * 21 < n)
	{
		if (m != 0 && buffer[m * 21 - 1] != '\n')
			print_error();
		block_check(buffer + (m * 21), noeud);
		noeud->piece->lettre = l++;
		if ((m + 1) * 21 < n)
			noeud = add_noeud(noeud);
	}
}
