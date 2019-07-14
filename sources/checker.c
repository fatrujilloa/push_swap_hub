/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 18:31:14 by ftrujill          #+#    #+#             */
/*   Updated: 2019/07/14 01:56:18 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

int		checker_continuation(int argc, t_stack *a, t_stack *b)
{
	int		i;
	int		r;
	char	inst[4];

	r = 1;
	while (r)
	{
		i = 0;
		while (i < 4)
			inst[i++] = 0;
		i = 0;
		while (i < 4 && (r = read(0, &inst[i], 1)) && inst[i] != '\n')
			i++;
		if (i == 0 && r == 0)
			break ;
		if (inst[i] != '\n')
			return (prt_error_but_free(a, b));
		inst[i] = 0;
		if (!action_not_prt(a, b, inst))
			return (prt_error_but_free(a, b));
	}
	if (!is_sorted(a, b, argc))
		return (prt_not_sorted(a, b));
	return (prt_sorted(a, b));
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
			return (-1);
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
	return (checker_continuation(argc, a, b));
}
