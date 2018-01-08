/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azybert <azybert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/09 00:47:02 by azybert           #+#    #+#             */
/*   Updated: 2017/08/03 21:27:46 by azybert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# define BUFSIZE 1024
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef	struct	s_piece
{
	char	lettre;
	int		xpos[4];
	int		ypos[4];
}				t_piece;

typedef struct	s_noeud
{
	struct s_piece	*piece;
	struct s_noeud	*next;
}				t_noeud;

typedef struct	s_liste
{
	struct s_noeud	*first;
}				t_liste;

t_liste			*struct_creat(char *file);
void			file_check(int fd, t_liste *liste);
void			print_error(void);
t_noeud			*add_noeud(t_noeud *noeud);
int				ft_taille(t_liste *liste);
char			**easy_algo(t_liste *liste, int taille);
char			**initialisation(int smaller_one);
void			display(char **agencement);

#endif
