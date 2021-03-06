/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettetrlst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhilary <fhilary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 19:06:29 by fhilary           #+#    #+#             */
/*   Updated: 2020/09/21 14:43:27 by fhilary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfi.h"

static int		get_frstpos(char *line, int *frst)
{
	int	i;

	i = 0;
	while (i < TETR_SIZE)
	{
		if (line[i] == F)
		{
			if (*frst == -1 || *frst > i)
				*frst = i;
			return (OK);
		}
		++i;
	}
	return (ERR);
}

static void		get_lastpos(char *line, int *last)
{
	int	i;

	i = 0;
	while (i < TETR_SIZE)
	{
		if (line[i] == F)
		{
			if (*last == -1 || *last < i)
				*last = i;
		}
		++i;
	}
}

static int		validate(const char *tetr)
{
	int	ctr_nei;
	int	ctr_pcs;
	int	i;
	int	j;

	ctr_nei = 0;
	ctr_pcs = 0;
	i = -1;
	while (++i < TETR_SIZE)
	{
		j = -1;
		while (++j < TETR_SIZE)
		{
			if (tetr[i * TETR_SIZE + j] == F && (++ctr_pcs))
			{
				ctr_nei += (j > 0 && tetr[i * TETR_SIZE + (j - 1)] == F) +
					(j < TETR_SIZE - 1 && tetr[i * TETR_SIZE + (j + 1)] == F) +
					(i > 0 && tetr[(i - 1) * TETR_SIZE + j] == F) +
					(i < TETR_SIZE - 1 && tetr[(i + 1) * TETR_SIZE + j] == F);
			}
			else if (tetr[i * TETR_SIZE + j] != EMPTY)
				return (ERR);
		}
	}
	return (ctr_nei >= 6 && ctr_pcs == TETR_SIZE ? OK : ERR);
}

static int		gettetr(int fd, t_tetr *tetr, char color)
{
	int	i;

	i = -1;
	tetr->uleft.y = -1;
	tetr->uleft.x = -1;
	tetr->dright.x = -1;
	while (++i < TETR_SIZE)
	{
		if (read(fd, tetr->body + i * TETR_SIZE, TETR_SIZE) != TETR_SIZE)
			return (ERR);
		if (get_frstpos(tetr->body + i * TETR_SIZE, &(tetr->uleft.x)) == OK)
		{
			if (tetr->uleft.y == -1)
				tetr->uleft.y = i;
			tetr->dright.y = i;
			get_lastpos(tetr->body + i * TETR_SIZE, &(tetr->dright.x));
		}
		if (ft_getc(fd) != '\n')
			return (ERR);
	}
	tetr->color = color;
	if (((i = ft_getc(fd)) != '\n' && i) || validate(tetr->body) == ERR)
		return (ERR);
	return (i ? OK : END);
}

t_list			*gettetrlst(int fd)
{
	t_list	*lst;
	t_list	*ptr;
	t_tetr	tetr;
	int		err;
	char	color;

	color = 'A';
	lst = NULL;
	if ((err = gettetr(fd, &tetr, color++)) != ERR)
	{
		if (!(lst = ft_lstnew(&tetr, sizeof(t_tetr))))
			return (NULL);
		ptr = lst;
		while (err == OK)
		{
			if ((err = (color > 'Z' ? ERR : OK)) == ERR)
				break ;
			err = gettetr(fd, &tetr, color++);
			ptr->next = ft_lstnew(&tetr, sizeof(t_tetr));
			ptr = ptr->next;
		}
		if (err == ERR)
			ft_lstdel(&lst, &deltetr);
	}
	return (lst);
}
