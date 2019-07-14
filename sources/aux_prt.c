/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_prt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <ftrujill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 18:29:37 by ftrujill          #+#    #+#             */
/*   Updated: 2019/07/14 13:32:07 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

int		prt_sorted(t_stack *a, t_stack *b)
{
	free_stacks(a, b);
	write(1, "OK\n", 3);
	return (0);
}

int		prt_not_sorted(t_stack *a, t_stack *b)
{
	free_stacks(a, b);
	write(1, "KO\n", 3);
	return (0);
}

int		prt_error_but_free(t_stack *a, t_stack *b)
{
	free_stacks(a, b);
	write(1, "Error\n", 6);
	return (0);
}

int		prt_error(void)
{
	write(1, "Error\n", 6);
	return (0);
}
