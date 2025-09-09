/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wedos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:25:04 by wedos-sa          #+#    #+#             */
/*   Updated: 2025/09/09 14:39:48 by wedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack_node **begin_list)
{
	t_stack_node	*last_item;
	t_stack_node	*temp;

	if (*begin_list == NULL || (*begin_list)->next == NULL)
		return ;
	last_item = ft_list_last_int(*begin_list);
	(*begin_list)->prev = last_item;
	temp = (*begin_list)->next;
	temp->prev = NULL;
	(*begin_list)->next = NULL;
	last_item->next = *begin_list;
	*begin_list = temp;
}

void	ra(t_stack_node	**stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

void	rb(t_stack_node **stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

void	rr(t_stack_node **stack_a, t_stack_node **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
