/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftrujill <ftrujill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 18:28:36 by ftrujill          #+#    #+#             */
/*   Updated: 2019/07/13 18:29:08 by ftrujill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

int		ft_sizetab_mod(char const *s, char c)
{
	int		i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		i = *s ? i + 1 : i;
		while (*s && *s != c)
			s++;
	}
	return (i);
}

char	**ft_strsplit_mod(char const *s, char c)
{
	int		i;
	int		j;
	int		size;
	char	**tab;

	if (!s)
		return (NULL);
	size = ft_sizetab_mod(s, c);
	if (!(tab = (char**)malloc(sizeof(char*) * (size + 2))))
		return (NULL);
	tab[0] = 0;
	i = 0;
	while (++i <= size)
	{
		while (*s == c)
			s++;
		j = 0;
		while (s[j] && s[j] != c)
			j++;
		if (!(tab[i] = ft_strsub(s, 0, j)))
			return (NULL);
		s = s + j;
	}
	tab[i] = 0;
	return (tab);
}

void	free_tab(char **tab, int argc)
{
	int i;

	i = 1;
	while (i < argc)
		free(tab[i++]);
	free(tab);
}

void	free_stacks(t_stack *a, t_stack *b)
{
	free(a->stack);
	free(b->stack);
	free(a);
	free(b);
}
