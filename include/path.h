/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 18:32:14 by tvermeil          #+#    #+#             */
/*   Updated: 2016/02/09 22:54:32 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_H
# define PATH_H
# include "libft.h"
# include "room.h"
# include "tunnel.h"

t_room	*get_resonable_path(t_room *room, t_room *start, int ants);
void	save_distances(t_room *room, int end_dist);

#endif
