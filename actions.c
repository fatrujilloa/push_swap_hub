/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 18:29:34 by ftrujill          #+#    #+#             */
/*   Updated: 2019/06/10 22:38:23 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "push_swap.h"

int    swap(t_stack *s)
{
    int t;

    t = s->stack[0];
    s->stack[0] = s->stack[1];
    s->stack[1] = t;
    write(1, "1\n", 2);
    return (1);
}

int    rotate(t_stack *s)
{
    int i;
    int t;

    i = -1;
    t = s->stack[0];
    while (++i < s->size - 1)
        s->stack[i] = s->stack[i + 1];
    s->stack[i] = t;
        write(1, "1\n", 2);
    return (1);
}

int    rev_rotate(t_stack *s)
{
    int i;
    int t;

    i = s->size;
    t = s->stack[s->size - 1];
    while (--i > 0)
        s->stack[i] = s->stack[i - 1];
    s->stack[0] = t;
        write(1, "1\n", 2);
    return (1);
}

int    rotater(t_stack *s)
{
    int i;
    int t;

    i = -1;
    t = s->stack[0];
    while (++i < s->size - 1)
        s->stack[i] = s->stack[i + 1];
    s->stack[i] = t;
    return (1);
}

int    rev_rotater(t_stack *s)
{
    int i;
    int t;

    i = s->size;
    t = s->stack[s->size - 1];
    while (--i > 0)
        s->stack[i] = s->stack[i - 1];
    s->stack[0] = t;
    return (1);
}

int    push(t_stack *s1, t_stack *s2)
{
    if (s2->size == 0)
        return (1);
    rev_rotater(s1);
    s1->stack[s1->size] = s1->stack[0];
    s1->stack[0] = s2->stack[0];
    s1->size++;
    rotater(s2);
    s2->size--;
    s2->stack[s2->size] = 0;
        write(1, "1\n", 2);
    return (1);
}

int     action(t_stack *a, t_stack *b, char *inst)
{
    if (!ft_strcmp(inst, "sa"))
        return (swap(a));
    else if (!ft_strcmp(inst, "sb"))
        return (swap(b));
    else if (!ft_strcmp(inst, "ss"))
        return (swap(a) && swap(b));
    else if (!ft_strcmp(inst, "pa"))
        return (push(a, b));  
    else if (!ft_strcmp(inst, "pb"))
        return (push(b, a));
    else if (!ft_strcmp(inst, "ra"))
        return (rotate(a));
    else if (!ft_strcmp(inst, "rb"))
        return (rotate(b));
    else if (!ft_strcmp(inst, "rr"))
        return (rotate(a) && rotate(b));
    else if (!ft_strcmp(inst, "rra"))
        return (rev_rotate(a));
    else if (!ft_strcmp(inst, "rrb"))
        return (rev_rotate(b));
    else if (!ft_strcmp(inst, "rrr"))
        return (rev_rotate(a) && rev_rotate(b));
    else
        return (0);    
}