/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 18:19:36 by ftrujill          #+#    #+#             */
/*   Updated: 2019/06/10 10:46:03 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H 

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct  s_stack
{
        int     size;
        int     *stack;
}               t_stack;

typedef struct  s_towers
{
        int     *pos;
        int     total;    
}               t_towers;

/*
** Initialization
*/
int             check_stack(int argc, char **argv);
void            init_stacks(int argc, char **argv, t_stack *a, t_stack *b);
/*
** Actions
*/
int             swap(t_stack *s);
int             rotate(t_stack *s);
int             rev_rotate(t_stack *s);
int             push(t_stack *s1, t_stack *s2);
int             action(t_stack *a, t_stack *b, char *inst);
/*
** Aux functions
*/
int             prt_sorted(t_stack *a, t_stack *b);
int             prt_not_sorted(t_stack *a, t_stack *b);
int             prt_error_but_free(t_stack *a, t_stack *b, char *inst);
int             prt_error(void);
void            free_stacks(t_stack *a, t_stack *b);
/*
** Visualization
*/
void            prt_stacks(t_stack *a, t_stack *b);

#endif