/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <ftrujill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 18:30:29 by ftrujill          #+#    #+#             */
/*   Updated: 2019/07/14 10:53:57 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

int		swap(t_stack *s)
{
	int t;

	if (s->size <= 1)
		return (1);
	t = s->stack[0];
	s->stack[0] = s->stack[1];
	s->stack[1] = t;
	return (1);
}

int		rotate(t_stack *s)
{
	int i;
	int t;

	if (s->size <= 1)
		return (1);
	i = -1;
	t = s->stack[0];
	while (++i < s->size - 1)
		s->stack[i] = s->stack[i + 1];
	s->stack[i] = t;
	return (1);
}

int		rev_rotate(t_stack *s)
{
	int i;
	int t;

	if (s->size <= 1)
		return (1);
	i = s->size;
	t = s->stack[s->size - 1];
	while (--i > 0)
		s->stack[i] = s->stack[i - 1];
	s->stack[0] = t;
	return (1);
}

int		push(t_stack *s1, t_stack *s2)
{
	if (s2->size == 0)
		return (1);
	rev_rotate(s1);
	s1->stack[s1->size] = s1->stack[0];
	s1->stack[0] = s2->stack[0];
	s1->size++;
	rotate(s2);
	s2->size--;
	s2->stack[s2->size] = 0;
	return (1);
}
