/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 18:32:14 by tvermeil          #+#    #+#             */
/*   Updated: 2016/02/09 18:26:32 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_H
# define PATH_H
# include "libft.h"
# include "room.h"
# include "tunnel.h"

//t_room	*get_shortest_path(t_room *start, t_room *end, int depth, int ignore);
t_room	*get_resonable_path(t_room *room, t_room *start, int ants); //ants are ants at start
void	save_distances(t_room *room, int end_dist);

#endif
