/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clev_rot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 16:42:59 by amaitre           #+#    #+#             */
/*   Updated: 2016/05/15 21:03:23 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		ps_clev_rot_b(t_ps_data data)
{
	int			i_start;
	t_intnode	*tmp;
	t_intnode	*tmp_prev;

	i_start = 0;
	tmp = data.b_s;
	tmp_prev = data.b_e;
	while (tmp)
	{
		if ((tmp->v < data.a_s->v && data.a_s->v < tmp_prev->v) ||
			(data.a_s->v > data.max && tmp->v == data.max) ||
			(data.a_s->v < data.min && tmp_prev->v == data.min))
			break ;
		tmp_prev = tmp;
		tmp = tmp->next;
		i_start++;
	}
	if (i_start > (data.nb_nbb / 2))
		return (0);
	return (1);
}

int		ps_clev_rot_b2(t_ps_data data)
{
	int			i_start;
	t_intnode	*tmp;

	i_start = 0;
	tmp = data.b_s;
	while (tmp)
	{
		if (tmp->v == data.max)
			break ;
		tmp = tmp->next;
		i_start++;
	}
	if (i_start > (data.nb_nbb / 2))
		return (0);
	return (1);
}
