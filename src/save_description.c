/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_description.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 17:25:30 by tvermeil          #+#    #+#             */
/*   Updated: 2016/01/27 19:32:31 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "room.h"

int		get_lem_nbr(void)
{
	char	*line;
	int		i;
	int		cont;

	cont = 1;
	while (cont || line[0] == '#')
	{
		cont = 0;
		if (get_next_line(0, &line) < 1)
			return (-1);
	}
	i = 0;
	while (line[i] != '\0')
		if (!ft_isdigit(line[i]))
			return (-1);
	return (ft_atoi(line));
}

static int	is_valid_room_desc(char *line)
{
	int		i;
	int		j;

	i = 0;
	while (line[i] != ' ' && line[i] != '\0')
		i++;
	if (line[i] == ' ')
		line[i++] == '\0';
	j = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
			j++;
		else if (!ft_isdigit(line[i]))
			return (0);
		i++;
	}
	return (j == 2);
}

t_room	*save_rooms(void)
{
	t_room	*room_lst;
	char	*line;
	char	start_end;

	start_end = 0;
	while (get_next_line(0, &line) > 1)
	{
		if (ft_strcmp("##start", line) == 0)
			start_end = 's';
		if (ft_strcmp("##end", line) == 0)
			start_end = 'e';
		if (line[0] == '#')
			continue;
		if (!(start_end = is_valid_room_desc(line)))
			break;
		room_lst = append_new_room(line, room_lst, start_end);
		start_end = 0;
	}
	return (room_lst);
}
