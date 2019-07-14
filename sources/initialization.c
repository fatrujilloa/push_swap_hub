/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <ftrujill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 18:33:45 by ftrujill          #+#    #+#             */
/*   Updated: 2019/07/14 13:19:40 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

int		check_stack(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	while (i < argc)
	{
		if (!*argv[i] || !ft_isstrnum(argv[i]) ||
			ft_atoi_ovflw(argv[i]) == 2147483648)
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

void	init_stacks(int argc, char **argv, t_stack *a, t_stack *b)
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

int		small_list_2(int argc, t_stack *a, t_stack *b)
{
	action(a, b, "pb") && action(a, b, "pb");
	ns(a, 0) && ns(b, 1) ? action(a, b, "ss") : 0;
	ns(a, 0) && !ns(b, 1) ? action(a, b, "sa") : 0;
	!ns(a, 0) && ns(b, 1) ? action(a, b, "sb") : 0;
	if (argc == 5)
		merge(a, b);
	else
	{
		if (a->stack[2] < a->stack[1] && a->stack[2] < a->stack[0])
			action(a, b, "rra");
		else if (a->stack[2] < a->stack[1])
			action(a, b, "pb") && action(a, b, "sa") && action(a, b, "pa");
		merge(a, b);
	}
	free_stacks(a, b);
	return (0);
}

int		small_list(int argc, t_stack *a, t_stack *b)
{
	if (argc == 3)
		ns(a, 0) ? action(a, b, "sa") : 0;
	else if (argc == 4)
	{
		a->stack[2] < a->stack[1] && a->stack[2] < a->stack[0] ?
			action(a, b, "rra") : 0;
		if (is_sorted(a, b, argc))
		{
			free_stacks(a, b);
			return (0);
		}
		ns(a, 0) ? action(a, b, "sa") : 0;
		is_sorted(a, b, argc) ? 0 : action(a, b, "pb") &&
			action(a, b, "sa") && action(a, b, "pa");
	}
	if (argc > 4)
		return (small_list_2(argc, a, b));
	free_stacks(a, b);
	return (0);
}

int		first_tower(t_stack *a, t_stack *b, int argc)
{
	int i;

	action(a, b, "pb");
	action(a, b, "pb");
	if (ns(a, 0))
		ns(b, 1) ? action(a, b, "sa") && action(a, b, "sb") :
			action(a, b, "sa");
	action(a, b, "ra");
	i = 2;
	while (++i < argc - 1 && a->stack[0] > a->stack[a->size - 1])
		action(a, b, "ra");
	ns(b, 1) ? action(a, b, "sb") : 0;
	return (i);
}
