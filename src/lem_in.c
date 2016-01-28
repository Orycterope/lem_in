/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvermeil <tvermeil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 14:42:04 by tvermeil          #+#    #+#             */
/*   Updated: 2016/01/28 18:00:26 by tvermeil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	error(void)
{
	ft_putstr_fd("ERROR\n");
	exit(0);
}

int	maint(void)
{
	int		ant_nbr;
	t_room	*rooms;

	ant_nbr = get_lem_nbr();
	rooms = save_rooms();
}
