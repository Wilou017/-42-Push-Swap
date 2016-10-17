/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 21:28:35 by amaitre           #+#    #+#             */
/*   Updated: 2016/05/15 21:29:14 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ps_promptlst(t_intnode *beginlist)
{
	t_intnode *tmp;

	tmp = beginlist;
	while (tmp)
	{
		(tmp->v == SA) ? ft_putstr("sa ") : 0;
		(tmp->v == SB) ? ft_putstr("sb ") : 0;
		(tmp->v == SS) ? ft_putstr("ss ") : 0;
		(tmp->v == RA) ? ft_putstr("ra ") : 0;
		(tmp->v == RB) ? ft_putstr("rb ") : 0;
		(tmp->v == RR) ? ft_putstr("rr ") : 0;
		(tmp->v == RRA) ? ft_putstr("rra ") : 0;
		(tmp->v == RRB) ? ft_putstr("rrb ") : 0;
		(tmp->v == RRR) ? ft_putstr("rrr ") : 0;
		(tmp->v == PA) ? ft_putstr("pa ") : 0;
		(tmp->v == PB) ? ft_putstr("pb ") : 0;
		tmp = tmp->next;
	}
	ft_putchar('\n');
}

void	ps_puthelp(void)
{
	ft_printf("{lred}➜  {lgreen}%s {eoc}\n\n", "Aide");
	ft_printf("{lblue}help{lwhite}: affiche cette notice.\n\n");
	ft_printf("{lblue}exit{lwhite}: quitte le programme.\n\n{lblue}sa{lwhite}");
	ft_printf(": swap a - intervertit les 2 premiers éléments au sommet de la");
	ft_printf(" pile a.\n(ne fait rien s’il n’y en a qu’un ou aucun).\n\n");
	ft_printf("{lblue}sb{lwhite}: swap b - intervertit les 2 premiers élémen");
	ft_printf("ts au sommet de la pile b.\n(ne fait rien s’il n’y en a");
	ft_printf(" qu’un ou aucun).\n\n{lblue}ss{lwhite}: sa et sb en même temp");
	ft_printf("s.\n\n{lblue}pa{lwhite}: push a - prend le premier élément");
	ft_printf(" au sommet de b et le met sur a.\n(ne fait rien si b est vide");
	ft_printf(").\n\n{lblue}pb{lwhite}: push b - prend le premier élément a");
	ft_printf("u sommet de a et le met sur b.\n(ne fait rien si a est vide)");
	ft_printf(".\n\n{lblue}ra{lwhite}: rotate a - décale d’une position tou");
	ft_printf("s les élements de la pile a.\n(vers le haut, le premier élém");
	ft_printf("ent devient le dernier).\n\n{lblue}rb{lwhite}: rotate b - dé");
	ft_printf("cale d’une position tous les élements de la pile b.\n(ve");
	ft_printf("rs le haut, le premier élément devient le dernier).\n\n");
	ft_printf("{lblue}rr{lwhite}: ra et rb en meme temps.\n\n{lblue}rra");
	ft_printf("{lwhite}: reverse rotate a\n(vers le bas, le dernier élément ");
	ft_printf("devient le premier).\n\n{lblue}rrb{lwhite}: reverse rotate b\n");
	ft_printf("(vers le bas, le dernier élément devient le premier).\n\n");
	ft_printf("{lblue}rrr{lwhite}: rra et rrb en même temps.{eoc}\n\n\n");
}

void	ps_logo(void)
{
	ft_printf("{lwhite} _  (`-')            (`-').-> (`-').-> (`-').->     .-");
	ft_printf(">    (`-')  _  _  (`-') \n \\-.(OO )     .->    ( OO)_   (OO )");
	ft_printf("__  ( OO)_   (`(`-')/`) (OO ).-/  \\-.(OO ) \n _.'    \\,--.(,");
	ft_printf("--.  (_)--\\_) ,--. ,'-'(_)--\\_) ,-`( OO).', / ,---.   _.'   ");
	ft_printf(" \\ \n(_...--''|  | |(`-')/    _ / |  | |  |/    _ / |  |\\  |");
	ft_printf("  | | \\ /`.\\ (_...--'' \n|  |_.' ||  | |(OO )\\_..`--. |  `-");
	ft_printf("'  |\\_..`--. |  | '.|  | '-'|_.' ||  |_.' | \n|  .___.'|  | |");
	ft_printf(" |  \\.-._)   \\|  .-.  |.-._)   \\|  |.'.|  |(|  .-.  ||  .__");
	ft_printf("_.' \n|  |     \\  '-'(_ .'\\       /|  | |  |\\       /|   ,'");
	ft_printf(".   | |  | |  ||  |      \n`--'      `-----'    `-----' `--' `");
	ft_printf("--' `-----' `--'   '--' `--' `--'`--'     \n");
}

int		ps_end(t_ps_data data)
{
	ft_putmessage("Les chiffres sont bien triés");
	ps_showlstint(data.a_s, "a", 0);
	ps_showlstint(data.b_s, "b", 0);
	return (0);
}

void	ps_showlstint(t_intnode *start, char *tabname, int rev)
{
	int			i;
	t_intnode	*tmp;

	ft_printf("\n");
	if (start == NULL)
		ft_printf("  {lyellow}%s {lcyan}➜ {lred} 0 element{eoc}\n", tabname);
	tmp = start;
	i = 0;
	while (tmp)
	{
		ft_printf("  {lyellow}%s{lred}[{lcyan}%d{lred}]{eoc} = ", tabname, i);
		ft_printf("{lgreen}%d{eoc}\n", tmp->v);
		if (!rev)
			tmp = tmp->next;
		else
			tmp = tmp->prev;
		i++;
	}
	ft_printf("\n");
}
