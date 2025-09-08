/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wedos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:18:33 by wedos-sa          #+#    #+#             */
/*   Updated: 2025/09/08 18:55:46 by wedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s_swap(t_stack_node **stack)
{
	t_stack_node	*first;
	t_stack_node	*second;

	if (stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->prev = second;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	*stack = second;
}

void	sa(t_stack_node **stack_a)
{
	s_swap(stack_a);
	ft_printf("sa\n");
}

void	sb(t_stack_node **stack_b)
{
	s_swap(stack_b);
	ft_printf("sb\n");
}

void	ss(t_stack_node **stack_a, t_stack_node **stack_b)
{
	s_swap(stack_a);
	s_swap(stack_b);
	ft_printf("ss\n");
}
