/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 14:36:27 by amaitre           #+#    #+#             */
/*   Updated: 2016/05/17 14:48:53 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		ps_valinlist(t_intnode *a_s, int val)
{
	t_intnode *tmp;

	tmp = a_s;
	while (tmp)
	{
		if (tmp->v == val)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int		ps_gettab(t_ps_data *data)
{
	int				i;
	int				val;
	char			*al;

	al = NULL;
	i = (data->bonus) ? 2 : 1;
	while (i < data->arg.c)
	{
		val = ft_atoi(data->arg.v[i]);
		if (!ft_strisdigit(data->arg.v[i]) ||
			ps_valinlist(data->a_s, val) ||
			ft_strcmp((al = ft_itoa(val, 10)), \
				data->arg.v[i]))
		{
			free(al);
			ps_lst_stack_free(data->a_s);
			return (0);
		}
		if (al)
			ft_strdel(&al);
		ps_pushback(data, val);
		data->tab.tab[i - ((data->bonus) ? 2 : 1)] = val;
		i++;
	}
	return (1);
}

int		ps_initdata(t_ps_data *data, int argc, char const **argv)
{
	data->bonus = (!ft_strcmp(argv[1], "-bonus")) ? 1 : 0;
	data->arg.c = argc;
	data->arg.v = argv;
	data->nb_nba = ((data->bonus) ? argc - 1 : argc) - 1;
	data->nb_nbb = 0;
	data->tab.size = data->nb_nba;
	data->tab.tab = ft_inttabnew(data->tab.size);
	data->cmdlst.size = 0;
	data->cmdlst.start = NULL;
	data->cmdlst.end = NULL;
	data->a_s = NULL;
	data->a_e = NULL;
	if (!ps_gettab(data))
		return (0);
	data->cmd = NULL;
	data->b_s = NULL;
	data->b_e = NULL;
	return (1);
}

int		ps_bonus(t_ps_data *data)
{
	if (ps_check_finish(*data))
		return (ps_end(*data));
	ft_putmessage("Plusieurs modes sont diponibles, selectionez en un");
	ft_printf("{lcyan}➜  {lwhite}Jeux{eoc}\n");
	ft_printf("{lcyan}➜  {lwhite}Auto{eoc}\n\n");
	while (1)
	{
		ps_getcmd_solve(data);
		if (!ft_strcmp(data->cmd, "exit"))
			return (0);
		if (!ft_strcmp(data->cmd, "Jeux"))
			return (ps_game(data));
		if (!ft_strcmp(data->cmd, "Auto"))
		{
			ft_termcaps_screenclear();
			ps_logo();
			ft_putmessage("Il y a plusieurs algorithmes, selectionez en un");
			ps_solve(data);
			return (0);
		}
		ft_printf("{red}Mode non recunnu\n\n");
	}
	return (0);
}

int		main(int argc, char const *argv[])
{
	t_ps_data	data;

	if (argc == 1 || (!ft_strcmp(argv[1], "-bonus") && argc == 2) ||
		!ps_initdata(&data, argc, argv))
		return (ft_printf("Error\n") ? 1 : 0);
	if (data.bonus == 1)
	{
		ft_termcaps_screenclear();
		ps_logo();
		ps_bonus(&data);
		ft_printf("{pink}Commande : ");
		ps_promptlst(data.cmdlst.start);
		ft_printf("\nNombre de commande : %zu{eoc}\n", data.cmdlst.size);
	}
	else
	{
		(data.nb_nba > 25) ? ps_solve_chagasseenflame(&data) : \
		ps_solve_littlebutterfly(&data);
		ps_promptlst(data.cmdlst.start);
	}
	ps_lst_stack_free(data.cmdlst.start);
	ps_lst_stack_free(data.a_s);
	ps_lst_stack_free(data.b_s);
	return (0);
}
