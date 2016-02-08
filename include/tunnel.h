/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tunnel.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 18:46:12 by tvermeil          #+#    #+#             */
/*   Updated: 2016/02/08 14:47:51 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUNNEL_H
# define TUNNEL_H
# include "room.h"

typedef struct		s_tunnel
{
	t_room			*room;
	struct s_tunnel	*next;
}					t_tunnel;

void	*append_new_tunnel_to_room(t_room *room, t_room *neighbor);
int		get_tunnel_nbr(t_room *room);
void	free_tunnels(t_room *room);

#endif
