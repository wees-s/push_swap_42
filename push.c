/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wedos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:22:08 by wedos-sa          #+#    #+#             */
/*   Updated: 2025/09/11 11:54:43 by wedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack_node **from, t_stack_node **to)
{
	t_stack_node	*temp;

	temp = *from;
	if ((*from)->next)
		(*from)->next->prev = NULL;
	*from = (*from)->next;
	if (*to == NULL)
	{
		*to = temp;
		(*to)->next = NULL;
	}
	else
	{
		temp->next = *to;
		temp->next->prev = temp;
		temp->prev = NULL;
		*to = temp;
	}
}

void	pa(t_stack_node **begin_list_b, t_stack_node **begin_list_a)
{
	push(begin_list_b, begin_list_a);
	ft_printf("pa\n");
}

void	pb(t_stack_node **begin_list_a, t_stack_node **begin_list_b)
{
	push(begin_list_a, begin_list_b);
	ft_printf("pb\n");
}
