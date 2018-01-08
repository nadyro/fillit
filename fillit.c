/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azybert <azybert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 01:01:23 by azybert           #+#    #+#             */
/*   Updated: 2017/07/23 23:52:32 by azybert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

int		main(int argc, char **argv)
{
	int		taille;
	char	**agencement;
	t_liste *liste;

	if (argc != 2)
	{
		write(1, "usage: /fillit source_file\n", 27);
		exit(0);
	}
	liste = struct_creat(argv[1]);
	taille = ft_taille(liste);
	agencement = easy_algo(liste, taille);
	display(agencement);
	return (0);
}
