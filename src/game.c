/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 11:54:48 by amaitre           #+#    #+#             */
/*   Updated: 2016/05/15 21:14:18 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void		ps_getcmd_game(t_ps_data *data)
{
	ft_printf("{lcyan}➜  {eoc}{lpink}");
	get_next_line(0, &(data->cmd));
	while (!ps_valid_cmd(data->cmd))
	{
		if (!ft_strcmp(data->cmd, "help"))
			ps_puthelp();
		else
			ft_printf("{red}Commande invalide, pour avoir de l'aide %s", \
				"tapez help{eoc}\n\n");
		ft_printf("{lcyan}➜  {eoc}{lpink}");
		get_next_line(0, &(data->cmd));
	}
}

static int		ps_select_cmd(char *cmd)
{
	if (!ft_strcmp(cmd, "sa"))
		return (SA);
	else if (!ft_strcmp(cmd, "sb"))
		return (SB);
	else if (!ft_strcmp(cmd, "ss"))
		return (SS);
	else if (!ft_strcmp(cmd, "ra"))
		return (RA);
	else if (!ft_strcmp(cmd, "rb"))
		return (RB);
	else if (!ft_strcmp(cmd, "rr"))
		return (RR);
	else if (!ft_strcmp(cmd, "rra"))
		return (RRA);
	else if (!ft_strcmp(cmd, "rrb"))
		return (RRB);
	else if (!ft_strcmp(cmd, "rrr"))
		return (RRR);
	else if (!ft_strcmp(cmd, "pa"))
		return (PA);
	else if (!ft_strcmp(cmd, "pb"))
		return (PB);
	return (0);
}

int				ps_game(t_ps_data *data)
{
	data->cmd = (char*)data->arg.v[0];
	ft_termcaps_screenclear();
	ps_logo();
	ft_putmessage("Triez les chiffres dans l'ordre croissant");
	ps_puthelp();
	while (ft_strcmp(data->cmd, "exit"))
	{
		if (ps_check_finish(*data))
		{
			ps_end(*data);
			break ;
		}
		ps_showlstint(data->a_s, "a", 0);
		ps_showlstint(data->b_s, "b", 0);
		ps_getcmd_game(data);
		if (ft_strcmp(data->cmd, "exit"))
			ps_pushswap_execmd(data, ps_select_cmd(data->cmd));
	}
	return (0);
}
