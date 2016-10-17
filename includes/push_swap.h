/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaitre <amaitre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/09 21:31:58 by amaitre           #+#    #+#             */
/*   Updated: 2016/09/28 17:01:25 by amaitre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <ft_termcaps.h>

typedef struct		s_intnode
{
	int					v;
	struct s_intnode	*next;
	struct s_intnode	*prev;
}					t_intnode;

typedef struct		s_arg
{
	const char		**v;
	int				c;
}					t_arg;

typedef struct		s_pstab
{
	int				*tab;
	int				size;
}					t_pstab;

typedef struct		s_dblst
{
	t_intnode		*start;
	t_intnode		*end;
	size_t			size;
}					t_dblst;

typedef struct		s_ps_data
{
	char			*cmd;
	t_intnode		*a_s;
	t_intnode		*a_e;
	t_intnode		*b_s;
	t_intnode		*b_e;
	t_dblst			cmdlst;
	t_pstab			tab;
	t_pstab			med;
	int				nb_nba;
	int				nb_nbb;
	int				min;
	int				max;
	int				bonus;
	t_arg			arg;
}					t_ps_data;

typedef enum		e_cmd
{
	SA,
	SB,
	SS,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	PA,
	PB
}					t_cmd;

void				ps_puthelp(void);
int					ps_pushswap_execmd(t_ps_data *data, int cmd);
int					ps_game(t_ps_data *data);
int					ps_check_finish(t_ps_data data);
void				ps_solve(t_ps_data *data);
int					ps_valid_cmd(char *cmd);
void				ps_promptlst(t_intnode *beginlist);
int					ps_select_median(int *tab, int size);
int					*ps_solve_littlebutterflyinttab(int *tab, int size);
void				ps_getcmd_solve(t_ps_data *data);
void				ps_solve_algo1(t_ps_data *data);
void				ps_solve_algo2(t_ps_data *data);
void				ps_solve_algo3(t_ps_data *data);
void				ps_showlstint(t_intnode *start, char *tabname, int rev);
void				ps_logo(void);
int					ps_push_stack_pb(t_ps_data *data);
int					ps_push_stack_pa(t_ps_data *data);
int					ps_rev_stack(t_intnode **start, t_intnode **end, int rev);
int					ps_intlistsorted(t_intnode *a_s);
int					ps_intlistsorted_rev(t_intnode *a_s);
void				ps_solve_littlebutterfly(t_ps_data *data);
void				ps_solve_chagasseenflame(t_ps_data *data);
void				ps_qsort(t_ps_data *data);
int					ps_ft_intlstmin(t_intnode *start);
int					ps_ft_intlstmax(t_intnode *start);
int					ps_end(t_ps_data data);
void				ps_lst_stack_free(t_intnode *beginlist);
void				ps_pushback(t_ps_data *data, int value);
int					ps_clev_rot_b(t_ps_data data);
int					ps_clev_rot_b2(t_ps_data data);
void				ps_lstadd(t_dblst *cmd, int value);

#endif
