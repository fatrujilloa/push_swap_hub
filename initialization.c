/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 11:59:29 by ftrujill          #+#    #+#             */
/*   Updated: 2019/06/10 10:39:01 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

int     check_stack(int argc, char **argv)
{
    int i;
    int j;

    i = 1;
    while (i < argc)
    {   
        if (!*argv[i] || !ft_isstrnum(argv[i]))
            return (0);
        j = 1;
        while (j < i)
        {
            if (ft_atoi(argv[i]) == ft_atoi(argv[j++]))
                return (0);
        }
        i++;
    }
    return (1);
}

void    init_stacks(int argc, char **argv, t_stack *a, t_stack *b)
{
    int i;

    i = 0;
    a->size = argc - 1;
    b->size = 0;
    while (i < argc - 1)
    {
        a->stack[i] = ft_atoi(argv[i + 1]);
        b->stack[i] = 0;
        i++;
    }
}