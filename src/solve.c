/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 14:51:02 by amaitre           #+#    #+#             */
/*   Updated: 2016/05/15 21:31:03 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		*ps_sortinttab(int *tab, int size)
{
	int save_size;

	save_size = size;
	if (!tab)
		return (NULL);
	while (!ft_inttabsorted(tab, size))
	{
		while (--size > 0)
			if (tab[size] < tab[size - 1])
				ft_intswap(&tab[size], &tab[size - 1]);
		size = save_size;
	}
	return (tab);
}

int		ps_select_median(int *tab, int size)
{
	int *tmp;
	int median;

	tmp = ft_inttabdup(tab, size);
	tmp = ps_sortinttab(tmp, size);
	median = tmp[(size - 1) / 2];
	free(tmp);
	return (median);
}

void	ps_getcmd_solve(t_ps_data *data)
{
	ft_printf("{lcyan}➜  {eoc}{lpink}");
	get_next_line(0, &(data->cmd));
}

void	ps_solve(t_ps_data *data)
{
	ft_printf("{lcyan}1 ➜  {pink}LittleButterfly{eoc}\n");
	ft_printf("{lcyan}2 ➜  {pink}ChagasseEnflame{eoc}\n\n");
	while (1)
	{
		ps_getcmd_solve(data);
		if (!ft_strcmp(data->cmd, "exit"))
			return ;
		else if (!ft_strcmp(data->cmd, "LittleButterfly") ||
			!ft_strcmp(data->cmd, "1"))
		{
			ps_solve_littlebutterfly(data);
			break ;
		}
		else if (!ft_strcmp(data->cmd, "ChagasseEnflame") ||
			!ft_strcmp(data->cmd, "2"))
		{
			ps_solve_chagasseenflame(data);
			break ;
		}
		ft_printf("{red}Aucun algorithme ne porte ce nom{eoc}\n\n");
	}
	if (ps_check_finish(*data))
		ps_end(*data);
}
