/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <ftrujill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 16:47:17 by ftrujill          #+#    #+#             */
/*   Updated: 2019/07/12 16:48:45 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

int     is_sorted(t_stack *a, t_stack *b, int argc)
{
    int i;

    if (a->size != argc - 1 || b->size != 0)
        return (0);
    i = 0;
    while (i < argc - 2)
    {
        if (a->stack[i] > a->stack[i + 1])
            return (0);
        i++;
    }
    return (1);
}

int     main(int argc, char **argv)
{
    char        **inst;
    t_stack     *a;
    t_stack     *b;

    if (argc == 1)
        return (0);
    if (!check_stack(argc, argv)
        || !(inst = (char**)malloc(sizeof(char*)))
        || !(a = (t_stack*)malloc(sizeof(t_stack)))
        || !(b = (t_stack*)malloc(sizeof(t_stack)))
        || !(a->stack = (int*)malloc(sizeof(int) * argc))
        || !(b->stack = (int*)malloc(sizeof(int) * argc)))
        return(prt_error()); 
    init_stacks(argc, argv, a, b);
    prt_stacks(a, b);
    while (get_next_line(0, inst))
    {
        if (!action(a, b, *inst))
            return (prt_error_but_free(a, b, *inst));
        prt_stacks(a, b);
        free((*inst));
    }
    if (!is_sorted(a, b, argc))
        return (prt_not_sorted(a, b));
    return(prt_sorted(a, b));
}
