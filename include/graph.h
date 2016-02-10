/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 15:26:08 by tvermeil          #+#    #+#             */
/*   Updated: 2016/02/10 16:56:28 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_H
# define GRAPH_H
# include "room.h"
# include "tunnel.h"

void	save_distances(t_room *room, int end_dist);
void	cut_branches(t_room *rooms, t_room *start);
void	remove_dead_tunnels(t_room *rooms);

#endif
