/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <ftrujill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 18:42:50 by ftrujill          #+#    #+#             */
/*   Updated: 2019/07/14 10:56:34 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

int		ns(t_stack *s, int x)
{
	if (s->size <= 1)
		return (0);
	if (x == 0)
		return (s->stack[0] > s->stack[1] ? 1 : 0);
	return (s->stack[0] < s->stack[1] ? 1 : 0);
}

int		twr_size(t_stack *s, int x)
{
	int i;

	if (s->size == 1)
		return (1);
	if (x == 0)
	{
		i = s->size - 1;
		while (i && s->stack[i] > s->stack[i - 1])
			i--;
		return (i == 0 ? s->size : s->size - i);
	}
	if (x == 1)
	{
		i = 0;
		while (i < s->size - 1 && s->stack[i] > s->stack[i + 1])
			i++;
		return (i == s->size - 1 ? s->size : i + 1);
	}
	i = 0;
	while (i < s->size - 1 && s->stack[i] < s->stack[i + 1])
		i++;
	return (i == s->size - 1 ? s->size : i + 1);
}

int		nbr_towers(t_stack *a)
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

int		is_sorted(t_stack *a, t_stack *b, int argc)
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
