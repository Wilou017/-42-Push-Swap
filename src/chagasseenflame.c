/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chagasseenflame.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 10:05:27 by amaitre           #+#    #+#             */
/*   Updated: 2016/05/17 14:51:19 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		ps_solve_chagasseenflame_init(t_ps_data *data, int *does, int *mina)
{
	*does = -1;
	if (data->nb_nba == 2)
	{
		ps_pushswap_execmd(data, SA);
		return (1);
	}
	if (data->a_s->v > data->a_s->next->v)
		ps_pushswap_execmd(data, SA);
	if (ps_check_finish(*data))
		return (1);
	ps_pushswap_execmd(data, PB);
	ps_pushswap_execmd(data, PB);
	data->max = ps_ft_intlstmax(data->b_s);
	data->min = ps_ft_intlstmin(data->b_s);
	*mina = ps_ft_intlstmin(data->a_s);
	return (0);
}

int		ps_solve_chagasseenflame_ifpb(t_ps_data *data, int *does, int *mina)
{
	if (((data->b_s->v < data->a_s->v && data->a_s->v < data->b_e->v) ||
			(data->a_s->v > data->max && data->b_s->v == data->max) ||
			(data->a_s->v < data->min && data->b_e->v == data->min)))
	{
		if (data->nb_nba == 1 && data->max < data->a_s->v)
			return (0);
		data->max = (data->max < data->a_s->v) ? data->a_s->v : data->max;
		data->min = (data->min > data->a_s->v) ? data->a_s->v : data->min;
		*mina = (*mina == data->a_s->v) ? ps_ft_intlstmin(data->a_s) : *mina;
		ps_pushswap_execmd(data, PB);
		*does = -1;
	}
	return (1);
}

int		ps_solve_chagasseenflame_ifpb_n(t_ps_data *data, int *does, int *mina)
{
	if (((data->b_s->v < data->a_s->next->v &&
		data->a_s->next->v < data->b_e->v) || (data->a_s->next->v > data->max &&
		data->b_s->v == data->max) || (data->a_s->next->v < data->min &&
		data->b_e->v == data->min)))
	{
		if (data->nb_nba == 1 && data->max < data->a_s->next->v)
			return (0);
		data->max = (data->max < data->a_s->next->v) ? data->a_s->next->v : \
		data->max;
		data->min = (data->min > data->a_s->next->v) ? data->a_s->next->v : \
		data->min;
		*mina = (*mina == data->a_s->next->v) ? ps_ft_intlstmin(data->a_s) : \
		*mina;
		ps_pushswap_execmd(data, SA);
		ps_pushswap_execmd(data, PB);
		*does = -1;
	}
	return (1);
}

void	ps_chagasse_end(t_ps_data *data)
{
	int does;

	does = ps_clev_rot_b2(*data);
	while (data->b_s->v != data->max)
		if (does == 1)
			ps_pushswap_execmd(data, RB);
		else if (does == 0)
			ps_pushswap_execmd(data, RRB);
	while (data->nb_nbb)
		ps_pushswap_execmd(data, PA);
}

void	ps_solve_chagasseenflame(t_ps_data *data)
{
	int does;
	int ma;

	if (ps_solve_chagasseenflame_init(data, &does, &ma))
		return ;
	while (data->nb_nba > 0)
	{
		if (ps_intlistsorted(data->a_s) && data->nb_nba != 1 && ma > data->max)
			break ;
		if (does == -1)
			does = ps_clev_rot_b(*data);
		if (data->nb_nba > 1 && !ps_solve_chagasseenflame_ifpb_n(data, &does,\
			&ma))
			break ;
		if (!ps_solve_chagasseenflame_ifpb(data, &does, &ma))
			break ;
		else if (does == 1)
			ps_pushswap_execmd(data, RB);
		else if (does == 0)
			ps_pushswap_execmd(data, RRB);
	}
	ps_chagasse_end(data);
}
