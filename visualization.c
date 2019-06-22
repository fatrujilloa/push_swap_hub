/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 12:02:15 by ftrujill          #+#    #+#             */
/*   Updated: 2019/06/10 10:39:32 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"
#include <stdio.h>

void    prt_stacks(t_stack *a, t_stack *b)
{
    int i;

    printf("A: ");
    i = 0;
    while (i < a->size)
        printf("%d ", a->stack[i++]);
    printf("\nB: ");
    i = 0;   
    while (i < b->size)
        printf("%d ", b->stack[i++]);
    printf("\n\n");
}