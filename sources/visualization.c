/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <ftrujill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 18:46:31 by ftrujill          #+#    #+#             */
/*   Updated: 2019/07/13 18:47:02 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

void	prt_stacks(t_stack *a, t_stack *b)
{
	int i;

	ft_printf("A: ");
	i = 0;
	while (i < a->size)
		ft_printf("%d ", a->stack[i++]);
	ft_printf("\nB: ");
	i = 0;
	while (i < b->size)
		ft_printf("%d ", b->stack[i++]);
	ft_printf("\n\n");
}
