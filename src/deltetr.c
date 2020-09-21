/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deltetr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhilary <fhilary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 19:06:10 by fhilary           #+#    #+#             */
/*   Updated: 2020/09/21 14:43:27 by fhilary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfi.h"

void	deltetr(void *content, size_t content_size)
{
	if (content && content_size)
		free(content);
}
