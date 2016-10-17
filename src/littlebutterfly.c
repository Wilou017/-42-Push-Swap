/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   littlebutterfly.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 20:22:21 by amaitre           #+#    #+#             */
/*   Updated: 2016/05/17 14:46:11 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		ps_ft_intlstmax(t_intnode *start)
{
	t_intnode	*tmp;
	int			max;

	tmp = start;
	max = start->v;
	while (tmp)
	{
		if (tmp->v > max)
			max = tmp->v;
		tmp = tmp->next;
	}
	return (max);
}

int		ps_ft_intlstmin(t_intnode *start)
{
	t_intnode	*tmp;
	int			min;

	tmp = start;
	min = start->v;
	while (tmp)
	{
		if (tmp->v < min)
			min = tmp->v;
		tmp = tmp->next;
	}
	return (min);
}

int		ps_clev_rot(t_ps_data data)
{
	int			i_start;
	t_intnode	*tmp;

	i_start = 0;
	tmp = data.a_s;
	while (tmp)
	{
		if (tmp->v == data.min)
			break ;
		tmp = tmp->next;
		i_start++;
	}
	if (i_start > (data.nb_nba / 2))
		return (RRA);
	return (RA);
}

void	ps_solve_littlebutterfly(t_ps_data *data)
{
	int does;

	does = -1;
	data->min = ps_ft_intlstmin(data->a_s);
	while (data->nb_nba > 1 && !ps_intlistsorted(data->a_s))
	{
		if (data->a_s->v > data->a_s->next->v)
			ps_pushswap_execmd(data, SA);
		if (does == -1)
			does = ps_clev_rot(*data);
		if (data->a_s->v == data->min)
		{
			if (ps_intlistsorted(data->a_s))
				break ;
			ps_pushswap_execmd(data, PB);
			does = -1;
			data->min = ps_ft_intlstmin(data->a_s);
		}
		if (does != -1)
			ps_pushswap_execmd(data, does);
	}
	while (data->nb_nbb)
		ps_pushswap_execmd(data, PA);
}
