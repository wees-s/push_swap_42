/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wedos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 09:59:51 by wedos-sa          #+#    #+#             */
/*   Updated: 2025/09/16 17:43:22 by wedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	index_list(t_stack_node **stack_a)
{
	t_stack_node	*temp;
	t_stack_node	*i;
	t_stack_node	*res;
	int				x;

	x = 0;
	i = *stack_a;
	temp = *stack_a;
	res = temp;
	while (temp != NULL)
	{
		while (i != NULL)
		{
			if (temp->num > i->num)
				x++;
			i = i->next;
		}
		temp->pos = x + 1;
		x = 0;
		temp = temp->next;
		i = *stack_a;
	}
	*stack_a = res;
}
