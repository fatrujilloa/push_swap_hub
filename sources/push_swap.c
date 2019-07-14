/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <ftrujill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 18:41:46 by ftrujill          #+#    #+#             */
/*   Updated: 2019/07/14 13:29:12 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

int		ps_continuation(int argc, t_stack *a, t_stack *b)
{
	if (is_sorted(a, b, argc))
	{
		free_stacks(a, b);
		return (0);
	}
	if (argc <= 6)
		return (small_list(argc, a, b));
	first_split(a, b, argc, first_tower(a, b, argc));
	merge(a, b);
	while (!(is_sorted(a, b, argc)))
	{
		split(a, b);
		merge(a, b);
	}
	free_stacks(a, b);
	return (0);
}

int		main(int argc, char **argv)
{
	char		**tab;
	t_stack		*a;
	t_stack		*b;

	if (argc == 1)
		return (0);
	if (argc == 2)
	{
		if (!(tab = ft_strsplit_mod(argv[1], ' ')))
			return (prt_error());
		argc = 1;
		while (tab[argc])
			argc++;
	}
	else
		tab = argv;
	if (!check_stack(argc, tab)
		|| !(a = (t_stack*)malloc(sizeof(t_stack)))
		|| !(b = (t_stack*)malloc(sizeof(t_stack)))
		|| !(a->stack = (int*)malloc(sizeof(int) * argc))
		|| !(b->stack = (int*)malloc(sizeof(int) * argc)))
		return (prt_error());
	init_stacks(argc, tab, a, b);
	tab == argv ? 0 : free_tab(tab, argc);
	return (ps_continuation(argc, a, b));
}
