/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 14:42:04 by tvermeil          #+#    #+#             */
/*   Updated: 2016/01/28 22:52:41 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	error(void)
{
	ft_putstr_fd("ERROR\n");
	exit(0);
}

void	execute_turn(t_room *rooms, int *first_ant, int last_ant, t_path *shortest)
{
	t_room	*room;
	t_path	*path;
	t_room	*start;
	int		ant;
	int		moved;

	start = get_start(rooms);
	ant = *first_ant;
	while (ant <= last_ant)
	{
		room = get_ant_position(ant);
		if (room == NULL)
			continue;
		moved = ant_decide(room, ant - last_ant, rooms, shortest);
		if (room == start)
		{
			if (moved == 1)
				*first_ant++;
			else
				break;
		}
	}
}

void	lem_in(t_room *rooms, int ants, t_room *start, t_room *end)
{
	t_path	*shortest;
	int		first_ant;
	int		i;

	i = 0;
	shortest = NULL;
	first_ant = 1;
	while (shortest == NULL && i < 100)
		shortest = get_shortest_path(start, end, i++, 0);
	if (shortest == NULL)
		error;
	while (start->ant < ants || get_ant_position(ants) != NULL)
	{
		execute_turn(rooms, &first_ant, ants, shortest);
		ft_putchar('\n');
	}
}

int	main(void)
{
	int		ant_nbr;
	t_room	*rooms;
	t_room	*start;
	t_room	*end;

	ant_nbr = get_lem_nbr();
	rooms = save_rooms();
	start = get_start(rooms);
	end = get_end(rooms);
	if (start == NULL || end == NULL || start == end)
		error();
	start->ant = 1;
}
