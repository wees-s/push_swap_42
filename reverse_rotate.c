/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wedos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:29:16 by wedos-sa          #+#    #+#             */
/*   Updated: 2025/09/09 14:42:15 by wedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack_node **begin_list)
{
	t_stack_node	*last_item;

	if (*begin_list == NULL || (*begin_list)->next == NULL)
		return ;
	last_item = ft_list_last_int(*begin_list);
	last_item->prev->next = NULL;
	last_item->prev = NULL;
	last_item->next = *begin_list;
	(*begin_list)->prev = last_item;
	*begin_list = last_item;
}

void	rra(t_stack_node **stack_a)
{
	reverse_rotate(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_stack_node **stack_b)
{
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}
