/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 18:32:14 by tvermeil          #+#    #+#             */
/*   Updated: 2016/02/08 14:29:20 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_H
# define PATH_H
# include "libft.h"
# include "room.h"
# include "tunnel.h"

typedef struct		s_path
{
	t_room			*room;
	struct s_path	*next;
}					t_path;

t_path	*append_new_room_to_path(t_room *room, t_path *path);
t_path	*get_shortest_path(t_room *start, t_room *end, int depth, int ignore);
t_path	*get_resonable_path(t_room *s, t_room *e, int ants, t_path *shortest); //ants are ants at start
int		path_length(t_path *path);
void	free_path(t_path *path);

#endif
