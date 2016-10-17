/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 11:53:44 by amaitre           #+#    #+#             */
/*   Updated: 2016/05/17 14:46:11 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int			ps_valid_cmd(char *cmd)
{
	if (ft_strcmp(cmd, "pa") && ft_strcmp(cmd, "exit") &&
				ft_strcmp(cmd, "sa") && ft_strcmp(cmd, "ss") &&
				ft_strcmp(cmd, "sb") && ft_strcmp(cmd, "rra") &&
				ft_strcmp(cmd, "rrb") && ft_strcmp(cmd, "rrr") &&
				ft_strcmp(cmd, "pb") && ft_strcmp(cmd, "ra") &&
				ft_strcmp(cmd, "rr") && ft_strcmp(cmd, "rb"))
		return (0);
	return (1);
}

int			ps_intlistsorted(t_intnode *a_s)
{
	t_intnode *tmp;

	tmp = a_s;
	while (tmp && tmp->next)
	{
		if (tmp->v > tmp->next->v)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int			ps_intlistsorted_rev(t_intnode *a_s)
{
	t_intnode *tmp;

	tmp = a_s;
	while (tmp && tmp->next)
	{
		if (tmp->v < tmp->next->v)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int			ps_check_finish(t_ps_data data)
{
	if (data.nb_nbb == 0 && ps_intlistsorted(data.a_s))
		return (1);
	return (0);
}

int			ps_pushswap_execmd(t_ps_data *data, int cmd)
{
	ps_lstadd(&data->cmdlst, cmd);
	data->cmdlst.size++;
	if (data->nb_nba > 1 && (cmd == SA || cmd == SS))
		return (ft_intswap(&data->a_s->v, &data->a_s->next->v));
	if (data->nb_nbb > 1 && (cmd == SB || cmd == SS))
		return (ft_intswap(&data->b_s->v, &data->b_s->next->v));
	if ((data->nb_nba) > 1 && (cmd == RA || cmd == RR))
		return (ps_rev_stack(&data->a_s, &data->a_e, 1));
	if ((data->nb_nbb) > 1 && (cmd == RB || cmd == RR))
		return (ps_rev_stack(&data->b_s, &data->b_e, 1));
	if ((data->nb_nba) > 1 && (cmd == RRA || cmd == RRR))
		return (ps_rev_stack(&data->a_s, &data->a_e, 0));
	if ((data->nb_nbb) > 1 && (cmd == RRB || cmd == RRR))
		return (ps_rev_stack(&data->b_s, &data->b_e, 0));
	if ((data->nb_nbb) > 0 && cmd == PA)
		return (ps_push_stack_pa(data));
	if ((data->nb_nba) > 0 && cmd == PB)
		return (ps_push_stack_pb(data));
	return (0);
}
