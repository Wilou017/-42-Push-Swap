/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 16:37:46 by amaitre           #+#    #+#             */
/*   Updated: 2016/05/15 20:05:10 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		ps_push_stack_pb(t_ps_data *data)
{
	t_intnode *tmp;

	tmp = data->a_s;
	data->a_s = tmp->next;
	if (data->nb_nba == 1)
		data->a_e = NULL;
	else
		data->a_s->prev = NULL;
	tmp->prev = NULL;
	tmp->next = data->b_s;
	if (data->nb_nbb == 0)
		data->b_e = tmp;
	else
		data->b_s->prev = tmp;
	data->b_s = tmp;
	data->nb_nbb++;
	data->nb_nba--;
	return (1);
}

int		ps_push_stack_pa(t_ps_data *data)
{
	t_intnode *tmp;

	tmp = data->b_s;
	data->b_s = tmp->next;
	if (data->nb_nbb == 1)
		data->b_e = NULL;
	else
		data->b_s->prev = NULL;
	tmp->prev = NULL;
	tmp->next = data->a_s;
	if (data->nb_nba == 0)
		data->a_e = tmp;
	else
		data->a_s->prev = tmp;
	data->a_s = tmp;
	data->nb_nba++;
	data->nb_nbb--;
	return (1);
}

int		ps_rev_stack(t_intnode **start, t_intnode **end, int rev)
{
	t_intnode *tmp;

	if (rev)
	{
		tmp = *start;
		*start = (*start)->next;
		(*start)->prev = NULL;
		tmp->next = NULL;
		(*end)->next = tmp;
		tmp->prev = *end;
		*end = tmp;
		return (1);
	}
	tmp = *start;
	(*start)->prev = *end;
	*start = *end;
	*end = (*end)->prev;
	(*end)->next = NULL;
	(*start)->prev = NULL;
	(*start)->next = tmp;
	(*start)->next = tmp;
	return (1);
}
