/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wedos-sa <wedos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 09:59:12 by wedos-sa          #+#    #+#             */
/*   Updated: 2025/10/01 13:59:10 by wedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_order(t_stack_node **stack_a)
{
	t_stack_node	*s_b;
	int				size_list;
	int				i;

	i = 0;
	s_b = NULL;
	size_list = ft_list_size_int(*stack_a);
	if (size_list == 2)
	{
		two_args(stack_a);
		return (1);
		//free_stack(*stack_a);
		//exit(EXIT_SUCCESS);
	}
	if (check_list(stack_a) == 1)
	{
		//free_stack(*stack_a);
		return (1);
		//exit(EXIT_SUCCESS);
	}
	else
	{
		stack_b(stack_a, &s_b, size_list, i);
		stack_a_organizer(stack_a);
		while (s_b != NULL)
			stack_to_a(stack_a, &s_b);
	}
	return (0);
}

int	check_list(t_stack_node **stack_a)
{
	t_stack_node	*head;

	head = *stack_a;
	while (head->next != NULL)
	{
		if (head->pos + 1 != head->next->pos)
			return (0);
		head = head->next;
	}
	return (1);
}

void	two_args(t_stack_node **stack_a)
{
	if ((*stack_a)->pos > (*stack_a)->next->pos)
		sa(stack_a);
	else
		return ;
}
