/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tunnel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 18:49:06 by tvermeil          #+#    #+#             */
/*   Updated: 2016/01/28 18:59:59 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tunnel.h"


void	*append_new_tunnel_to_room(t_room *room, t_room *neighbor)
{
	t_tunnel	*new;

	new = (t_tunnel*)malloc(sizeof(t_tunnel));
	if (new == NULL)
		return (NULL);
	new->room = neighbor;
	new->next = room->tunnels;
	room->tunnels = new;
	return (new);
}

int		get_tunnel_nbr(t_room *room)
{
	int			n;
	t_tunnel	*tunnel;

	n = 0;
	tunnel = room->tunnels;
	while (tunnel != NULL)
	{
		n++;
		tunnel = tunnel->next;
	}
	return (n);
}

void	free_tunnels(t_room *room)
{
	t_tunnel	*next;
	t_tunnel	*tunnel;

	tunnel = room->tunnels;
	while (tunnel != NULL)
	{
		next = tunnel->next;
		free(tunnel);
		tunnel = next;
	}
}
