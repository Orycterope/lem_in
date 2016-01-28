/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 18:32:14 by tvermeil          #+#    #+#             */
/*   Updated: 2016/01/28 20:30:36 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_H
# define PATH_H

typedef struct		s_path
{
	t_room			*room;
	struct s_path	*next;
}					t_path;

t_path	*append_new_room_to_path(t_room *room, t_path *path);
t_path	*get_shortest_path(t_room *start, t_room *end, int depth, int ignore);
int		path_length(t_path *path);
void	free_path(t_path *path);

#endif
