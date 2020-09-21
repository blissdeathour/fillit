/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfi.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhilary <fhilary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 19:17:56 by fhilary           #+#    #+#             */
/*   Updated: 2020/09/21 14:43:27 by fhilary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFI_H

# define LIBFI_H

# include "libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

# define TETR_SIZE 4
# define F '#'
# define EMPTY '.'

typedef struct	s_coord
{
	int	x;
	int	y;
}				t_coord;

typedef struct	s_tetr
{
	char	body[TETR_SIZE * TETR_SIZE];
	char	color;
	t_coord	uleft;
	t_coord	dright;
}				t_tetr;

typedef struct	s_field
{
	char	**body;
	int		size;
	int		realsize;
}				t_field;

void			printtetr(t_tetr *tetr);
void			printtetrlst(t_list *lst);
void			deltetr(void *content, size_t content_size);
t_list			*gettetrlst(int fd);
int				puttetrlst(t_list *lst, t_field *map);
char			ft_getc(int fd);

#endif
