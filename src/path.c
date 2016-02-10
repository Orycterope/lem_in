/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 18:34:25 by tvermeil          #+#    #+#             */
/*   Updated: 2016/02/10 16:35:08 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "path.h"

t_room	*get_resonable_path(t_room *room, t_room *start, int ants)
{
	int			max_turns;
	t_tunnel	*tunnel;

	max_turns = ants + start->end_dist - 1; // -2 ?
	tunnel = room->tunnels;
	while (tunnel != NULL)
	{
		if (tunnel->room->ant == 0 && tunnel->room->end_dist != -1
				&& tunnel->room->end_dist <= max_turns)
			return (tunnel->room);
		else if (tunnel->room->ant != 0)
			max_turns -= 1;
		tunnel = tunnel->next;
	}
	return (NULL);
}

