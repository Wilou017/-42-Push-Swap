/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 14:11:39 by amaitre           #+#    #+#             */
/*   Updated: 2016/05/17 14:45:53 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ps_lst_stack_free(t_intnode *beginlist)
{
	t_intnode *tmp;
	t_intnode *tmp2;

	if (!beginlist)
		return ;
	tmp = beginlist;
	while (tmp)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		free(tmp2);
	}
}

void	ps_pushback(t_ps_data *data, int value)
{
	t_intnode	*new;

	new = (t_intnode*)malloc(sizeof(t_intnode));
	new->v = value;
	new->prev = data->a_e;
	new->next = NULL;
	if (data->a_e)
		data->a_e->next = new;
	data->a_e = new;
	if (data->a_s == NULL)
		data->a_s = new;
}

void	ps_lstadd(t_dblst *cmd, int value)
{
	t_intnode	*new;

	new = (t_intnode*)malloc(sizeof(t_intnode));
	new->v = value;
	new->next = NULL;
	new->prev = cmd->end;
	if (cmd->end)
		cmd->end->next = new;
	cmd->end = new;
	if (cmd->start == NULL)
		cmd->start = new;
}
