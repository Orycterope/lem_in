/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tunnel.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 18:46:12 by tvermeil          #+#    #+#             */
/*   Updated: 2016/01/28 19:50:21 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUNNEL_H
# define TUNNEL_H

typedef struct		s_tunnel
{
	t_room			*room;
	struct s_path	*next;
}					t_tunnel;

void	*append_new_tunnel_to_room(t_room *room, t_room *neighbor);
int		get_tunnel_nbr(t_room *room);
void	free_tunnels(t_room *room);

#endif
