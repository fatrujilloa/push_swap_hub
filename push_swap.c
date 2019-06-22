/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 17:29:00 by ftrujill          #+#    #+#             */
/*   Updated: 2019/06/11 00:07:18 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
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
    ns(a, 0) ? swap(a) && push(b, a) : push(b, a);
    ns(a, 0) ? swap(a) && push(b, a) : push(b, a);
    ns(a, 0) && ns(b, 1) ? action(a, b, "ss") : 0;
    ns(a, 0) ? swap(a) : 0;
    ns(b, 1) ? swap(b) : 0;
    //printf("\nThe numbers are %d, %d, %d, %d \n", a->stack[0], a->stack[1], b->stack[0], b->stack[1]);
    if (min == 3)
        {
        rotate(a) && push(a, b) && push(a, b) && rotate(a) && rotate(a)
        && rotate(a);
        //printf("\nThe numbers are in a %d, %d, %d, %d \n", a->stack[a->size - 1], a->stack[a->size - 2], a->stack[a->size - 3], a->stack[a->size - 4]);
        }
    else
    {
        push(b, a);
        ns(b, 1) ? swap(b) && push(b, a) : push(b, a);
          //  printf("\nThe numbers are in b%d, %d, %d, %d \n", b->stack[0], b->stack[1], b->stack[2], b->stack[3]);
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
               // printf("We got in here\n");
                min_tower(a, b);
                i = i + 4;
            }
        else
        {
            if (a->stack[a->size - 1] < b->stack[0])
                (a->stack[0] > b->stack[0] || !(a->stack[0] > a->stack[a->size - 1])) ? 
                    push(b, a) && push(b, a) : rotate(a) && rotate(a);
            else
                (a->stack[0] > a->stack[a->size - 1] || !(a->stack[0] > b->stack[0])) ? 
                    rotate(a) && rotate(a) : push(b, a) && push(b, a);
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
        //printf("\nTowers Size %d, %d\nStacks size %d, %d\n", t_a, t_b, a->size, b->size);
        //prt_stacks(a, b);
        while(x < t_a && y < t_b)
            if (b->stack[0] > a->stack[a->size - 1])
            {
                push(a, b);
                y++;
            }
            else
            {
                rev_rotate(a);
                x++;
            }
        while (y++ < t_b)
            push(a, b);
        while (x++ < t_a)
            rev_rotate(a);
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
        //printf("\nSize %d\n", i);
        while (i > 0)
        {
            push(b, a);
            i--;
        }
        t--;
        //prt_stacks(a, b);
    }
}

int     first_tower(t_stack *a, t_stack *b, int argc)
{
    int i;

    push(b, a);
    push(b, a);
    if (ns(a, 0))
        ns(b, 1) ? swap(a) && swap(b) : swap(a);
    rotate(a);
    i = 2;
    while (++i < argc - 1 && a->stack[0] > a->stack[a->size - 1]) 
        rotate(a);
    ns(b, 1) ? swap(b) : 0;
    //prt_stacks(a, b);
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
    prt_stacks(a, b);
    printf("\n%d\n", first_tower(a, b, argc));
    first_split(a, b, argc, first_tower(a, b, argc));
    merge(a, b);
    //split(a, b);
    //prt_stacks(a, b);
    //merge(a, b);
    //split(a, b);
    //prt_stacks(a, b);
    //printf("\nMERGING\n");
    //prt_stacks(a, b);
    //printf("\nSPLITTING\n");
    while (!(is_sorted(a, b, argc)))
        {
            split(a, b);
            merge(a, b);
        }
     prt_stacks(a, b);
    return (0);
}