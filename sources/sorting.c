/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <ftrujill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 18:43:46 by ftrujill          #+#    #+#             */
/*   Updated: 2019/07/13 19:34:38 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

void	min_tower(t_stack *a, t_stack *b)
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
		ns(b, 1) ? action(a, b, "sb") && action(a, b, "pb") :
			action(a, b, "pb");
	}
}

void	aux_first_split(t_stack *a, t_stack *b)
{
	if (a->stack[a->size - 1] < b->stack[0])
		(a->stack[0] > b->stack[0] || !(a->stack[0] > a->stack[a->size - 1])) ?
		action(a, b, "pb") && action(a, b, "pb") :
		action(a, b, "ra") && action(a, b, "ra");
	else
		(a->stack[0] > a->stack[a->size - 1] || !(a->stack[0] > b->stack[0])) ?
		action(a, b, "ra") && action(a, b, "ra") :
		action(a, b, "pb") && action(a, b, "pb");
}

void	first_split(t_stack *a, t_stack *b, int argc, int i)
{
	while (i < argc - 1)
	{
		if (i == argc - 2)
		{
			a->stack[0] > b->stack[0] ? action(a, b, "pb") : action(a, b, "ra");
			break ;
		}
		ns(a, 0) ? action(a, b, "sa") : 0;
		if (i <= argc - 5 && a->stack[0] < ft_min_int(a->stack[a->size - 1],
			b->stack[0]) && ft_min_int(a->stack[3], a->stack[2]) <
			ft_max_int(a->stack[1], a->stack[0]))
		{
			min_tower(a, b);
			i = i + 4;
		}
		else
		{
			aux_first_split(a, b);
			i = i + 2;
		}
	}
}

void	merge(t_stack *a, t_stack *b)
{
	int x;
	int y;
	int t_a;
	int t_b;
	int z;

	while (b->size)
	{
		y = 0;
		x = 0;
		t_a = twr_size(a, 0);
		t_b = twr_size(b, 1);
		while (x < t_a && y < t_b)
		{
			z = b->stack[0] - a->stack[a->size - 1];
			z > 0 ? action(a, b, "pa") : action(a, b, "rra");
			z > 0 ? y++ : x++;
		}
		while (y++ < t_b)
			action(a, b, "pa");
		while (x++ < t_a)
			action(a, b, "rra");
	}
}

void	split(t_stack *a, t_stack *b)
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
