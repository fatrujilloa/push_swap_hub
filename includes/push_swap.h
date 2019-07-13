/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <ftrujill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 19:35:16 by ftrujill          #+#    #+#             */
/*   Updated: 2019/07/13 19:36:14 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_stack
{
	int		size;
	int		*stack;
}				t_stack;

typedef struct	s_towers
{
	int		*pos;
	int		total;
}				t_towers;

/*
** Initialization
*/
int				check_stack(int argc, char **argv);
void			init_stacks(int argc, char **argv, t_stack *a, t_stack *b);
int				small_list(int argc, t_stack *a, t_stack *b);
int				first_tower(t_stack *a, t_stack *b, int argc);
/*
** Actions
*/
int				swap(t_stack *s);
int				rotate(t_stack *s);
int				rev_rotate(t_stack *s);
int				push(t_stack *s1, t_stack *s2);
int				action(t_stack *a, t_stack *b, char *inst);
int				action_not_prt(t_stack *a, t_stack *b, char *inst);
/*
** Sorting
*/
int				ns(t_stack *s, int x);
int				twr_size(t_stack *s, int x);
int				nbr_towers(t_stack *a);
int				is_sorted(t_stack *a, t_stack *b, int argc);
void			min_tower(t_stack *a, t_stack *b);
void			first_split(t_stack *a, t_stack *b, int argc, int i);
void			merge(t_stack *a, t_stack *b);
void			split(t_stack *a, t_stack *b);
/*
** Aux functions
*/
int				ft_sizetab_mod(char const *s, char c);
char			**ft_strsplit_mod(char const *s, char c);
void			free_tab(char **tab, int argc);
void			free_stacks(t_stack *a, t_stack *b);
/*
** Aux print functions
*/
int				prt_sorted(t_stack *a, t_stack *b);
int				prt_not_sorted(t_stack *a, t_stack *b);
int				prt_error_but_free(t_stack *a, t_stack *b, char *inst);
int				prt_error(void);
/*
** Visualization
*/
void			prt_stacks(t_stack *a, t_stack *b);

#endif
