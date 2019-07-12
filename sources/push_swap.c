/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <ftrujill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 17:29:00 by ftrujill          #+#    #+#             */
/*   Updated: 2019/07/12 16:45:07 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

int     ns(t_stack *s, int x)
{
    if (x == 0)
        return (s->stack[0] > s->stack[1] ? 1 : 0);
    return (s->stack[0] < s->stack[1] ? 1 : 0);
}

void    min_tower(t_stack *a, t_stack *b)
{
    int min;

    min = a->stack[0] < a->stack[1] ? 0 : 1;
    min = a->stack[min] < a->stack[2] ? min : 2;
    min = a->stack[min] < a->stack[3] ? min : 3;
    ns(a, 0) ? action(a, b, "sa") && action(a, b, "pb") : action(a, b, "pb");
    ns(a, 0) ? action(a, b, "sa") && action(a, b, "pb") : action(a, b, "pb");
    ns(a, 0) && ns(b, 1) ? action(a, b, "ss") : 0;
    ns(a, 0) ? action(a, b, "sa") : 0;
    ns(b, 1) ? action(a, b, "sb") : 0;
    if (min == 3)
    {
        action(a, b, "ra") && action(a, b, "pa") && action(a, b, "pa") &&
        action(a, b, "ra") && action(a, b, "ra") && action(a, b, "ra");
    }
    else
    {
        action(a, b, "pb");
        ns(b, 1) ? action(a, b, "sb") && action(a, b, "pb") : action(a, b, "pb");
    }
}

void    first_split(t_stack *a, t_stack *b, int argc, int i)
{
    while (i < argc - 1)
    {
        if (i == argc - 2)
        {
            a->stack[0] > b->stack[0] ? push(b, a) : rotate(a);
            break;
        }
        ns(a, 0) ? swap(a) : 0;
        if (i <= argc - 5 && a->stack[0] < ft_min_int(a->stack[a->size - 1], b->stack[0])
            && ft_min_int(a->stack[3], a->stack[2]) < ft_max_int(a->stack[1], a->stack[0]))
        {
            min_tower(a, b);
            i = i + 4;
        }
        else
        {
            if (a->stack[a->size - 1] < b->stack[0])
                (a->stack[0] > b->stack[0] || !(a->stack[0] > a->stack[a->size - 1])) ? 
                    action(a, b, "pb") && action(a, b, "pb") :
                    action(a, b, "ra") && action(a, b, "ra");
            else
                (a->stack[0] > a->stack[a->size - 1] || !(a->stack[0] > b->stack[0])) ? 
                    action(a, b, "ra") && action(a, b, "ra") : action(a, b, "pb") && action(a, b, "pb");
            i = i + 2;
        }
    }
}

int     twr_size(t_stack *s, int x)
{
    int i;

    if (s->size == 1)
        return (1);
    if (x == 0)
    {
        i = s->size - 1;
        while(i && s->stack[i] > s->stack[i - 1])
            i--;
        return (i == 0 ? s->size : s->size - i);
    }
    if (x == 1)
    {
        i = 0;
        while(i < s->size - 1 && s->stack[i] > s->stack[i + 1])
            i++;
        return (i == s->size - 1 ? s->size : i + 1);
    }
    i = 0;
    while(i < s->size - 1 && s->stack[i] < s->stack[i + 1])
        i++;
    return (i == s->size - 1 ? s->size : i + 1);
}

void    merge(t_stack *a, t_stack *b)
{
    int x;
    int y;
    int t_a;
    int t_b;

    while (b->size)
    {
        y = 0;
        x = 0;
        t_a = twr_size(a, 0);
        t_b = twr_size(b, 1);
        while(x < t_a && y < t_b)
            if (b->stack[0] > a->stack[a->size - 1])
            {
                action(a, b, "pa");
                y++;
            }
            else
            {
                action(a, b, "rra");
                x++;
            }
        while (y++ < t_b)
            action(a, b, "pa");
        while (x++ < t_a)
            action(a, b, "rra");
    }
}

int     nbr_towers(t_stack *a)
{
    int i;
    int n;

    i = 0;
    n = 0;
    while (i < a->size)
        {
            while (i < a->size - 2 && a->stack[i] < a->stack[i + 1])
                i++;
            i++;
            n++;
        }
    return (n);
}

void    split(t_stack *a, t_stack *b)
{
    int t;
    int i;

    t = nbr_towers(a) / 2;
    while (t > 0)
    {
        i = twr_size(a, 2);
        while (i > 0)
        {
            action(a, b, "pb");
            i--;
        }
        t--;
    }
}

int     first_tower(t_stack *a, t_stack *b, int argc)
{
    int i;

    action(a, b, "pb");
    action(a, b, "pb");
    if (ns(a, 0))
        ns(b, 1) ? action(a, b, "sa") && action(a, b, "sb") : action(a, b, "sa");
    action(a, b, "ra");
    i = 2;
    while (++i < argc - 1 && a->stack[0] > a->stack[a->size - 1]) 
        action(a, b, "ra");
    ns(b, 1) ? action(a, b, "sb") : 0;
    return (i);
}

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
    first_split(a, b, argc, first_tower(a, b, argc));
    merge(a, b);
    while (!(is_sorted(a, b, argc)))
        {
            split(a, b);
            merge(a, b);
        }
     prt_stacks(a, b);
    return (0);
}