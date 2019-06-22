/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_prt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 19:10:55 by ftrujill          #+#    #+#             */
/*   Updated: 2019/06/10 10:35:31 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

void    free_stacks(t_stack *a, t_stack *b)
{
    free(a->stack);
    free(b->stack);
    free(a);
    free(b);
}

int     prt_sorted(t_stack *a, t_stack *b)
{
    free_stacks(a, b);
    write(1, "OK\n", 3);
    return (0);
}

int    prt_not_sorted(t_stack *a, t_stack *b)
{
    free_stacks(a, b);
    write(1, "KO\n", 3);
    return (0);
}

int    prt_error_but_free(t_stack *a, t_stack *b, char *inst)
{
    free(inst);
    free_stacks(a, b);
    write(1, "Error\n", 6);
    return (0);
}

int    prt_error(void)
{
    write(1, "Error\n", 6);
    return (0);
}
