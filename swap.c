/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wedos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:18:33 by wedos-sa          #+#    #+#             */
/*   Updated: 2025/09/05 18:57:49 by wedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack_node **stack_a)
{
	t_stack_node *first;
	t_stack_node *second;
	first = *stack_a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack_a = second;
}
/*
t_stack_node	sb(void)
{
	 exit(EXIT_SUCCESS);
}

t_stack_node	ss(void)
{
	 exit(EXIT_SUCCESS);
}
*/
