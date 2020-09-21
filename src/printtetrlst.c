/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printtetrlst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhilary <fhilary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 19:12:15 by fhilary           #+#    #+#             */
/*   Updated: 2020/09/21 14:43:27 by fhilary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfi.h"

void	printtetrlst(t_list *lst)
{
	while (lst)
	{
		printtetr(lst->content);
		lst = lst->next;
	}
}
