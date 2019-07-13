/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <ftrujill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 18:27:32 by ftrujill          #+#    #+#             */
/*   Updated: 2019/07/13 18:27:58 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

int		action(t_stack *a, t_stack *b, char *inst)
{
	if (!ft_strcmp(inst, "sa"))
		return (swap(a) && ft_printf("%s\n", inst));
	else if (!ft_strcmp(inst, "sb"))
		return (swap(b) && ft_printf("%s\n", inst));
	else if (!ft_strcmp(inst, "ss"))
		return (swap(a) && swap(b) && ft_printf("%s\n", inst));
	else if (!ft_strcmp(inst, "pa"))
		return (push(a, b) && ft_printf("%s\n", inst));
	else if (!ft_strcmp(inst, "pb"))
		return (push(b, a) && ft_printf("%s\n", inst));
	else if (!ft_strcmp(inst, "ra"))
		return (rotate(a) && ft_printf("%s\n", inst));
	else if (!ft_strcmp(inst, "rb"))
		return (rotate(b) && ft_printf("%s\n", inst));
	else if (!ft_strcmp(inst, "rr"))
		return (rotate(a) && rotate(b) && ft_printf("%s\n", inst));
	else if (!ft_strcmp(inst, "rra"))
		return (rev_rotate(a) && ft_printf("%s\n", inst));
	else if (!ft_strcmp(inst, "rrb"))
		return (rev_rotate(b) && ft_printf("%s\n", inst));
	else if (!ft_strcmp(inst, "rrr"))
		return (rev_rotate(a) && rev_rotate(b) && ft_printf("%s\n", inst));
	else
		return (0);
}

int		action_not_prt(t_stack *a, t_stack *b, char *inst)
{
	if (!ft_strcmp(inst, "sa"))
		return (swap(a));
	else if (!ft_strcmp(inst, "sb"))
		return (swap(b));
	else if (!ft_strcmp(inst, "ss"))
		return (swap(a) && swap(b));
	else if (!ft_strcmp(inst, "pa"))
		return (push(a, b));
	else if (!ft_strcmp(inst, "pb"))
		return (push(b, a));
	else if (!ft_strcmp(inst, "ra"))
		return (rotate(a));
	else if (!ft_strcmp(inst, "rb"))
		return (rotate(b));
	else if (!ft_strcmp(inst, "rr"))
		return (rotate(a) && rotate(b));
	else if (!ft_strcmp(inst, "rra"))
		return (rev_rotate(a));
	else if (!ft_strcmp(inst, "rrb"))
		return (rev_rotate(b));
	else if (!ft_strcmp(inst, "rrr"))
		return (rev_rotate(a) && rev_rotate(b));
	else
		return (0);
}
