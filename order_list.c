/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wedos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 09:59:12 by wedos-sa          #+#    #+#             */
/*   Updated: 2025/09/16 17:30:25 by wedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_order(t_stack_node **stack_a)
{
	t_stack_node	*stack_b;
	int				size_list;

	size_list = ft_list_size_int(*stack_a);
	stack_b = stack_to_b(stack_a, size_list);
	stack_a_organizer(stack_a);
	while (stack_b != NULL)
		stack_to_a(stack_a, &stack_b);
}

t_stack_node	*stack_to_b(t_stack_node **stack_a, int size_list)
{
	t_stack_node	*stack_b;
	int				i;
	int				conteiner_min;
	int				conteiner_max;
	int				conteiner;

	conteiner = 0;
	conteiner_max = 0;
	conteiner_min = 0;
	i = 0;
	stack_b = NULL;	
	if (ft_list_size_int(*stack_a) >= 499)
		conteiner_max = 35;
	else if (ft_list_size_int(*stack_a) >= 99)
		conteiner_max = 15;
	else
		conteiner_max = ft_list_size_int(*stack_a) / 2;
	conteiner = conteiner_max;
	while (ft_list_size_int(*stack_a) >= 4)
	{
		if ((*stack_a) -> pos > size_list - 3)
			ra(stack_a);
		else
		{
			if ((*stack_a) -> pos <= conteiner_max && (*stack_a) -> pos >= conteiner_min)
			{
				i++;
				pb(stack_a, &stack_b);
				if (i >= conteiner_max)
				{
					conteiner_min = conteiner_max;
					conteiner_max = conteiner_max + conteiner;
				}
			}
			else
				ra(stack_a);
		}
	}
	return (stack_b);
}

void	stack_a_organizer(t_stack_node **stack_a)
{
	if ((*stack_a)->next->next->pos < (*stack_a)->pos
			&& (*stack_a)->pos > (*stack_a)->next->pos)
	{
		ra(stack_a);
		sa(stack_a);
	}
	else if ((*stack_a)->pos > (*stack_a)->next->pos
			&& (*stack_a)->pos < (*stack_a)->next->next->pos)
		sa(stack_a);
	else if ((*stack_a)->pos < (*stack_a)->next->pos
			&& (*stack_a)->next->pos < (*stack_a)->next->next->pos)
		 ;
	else
	{
		rra(stack_a);
		sa(stack_a);
	}
}

void	stack_to_a(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*head;

	head = *stack_b;
	while (head->pos + 1 != (*stack_a)->pos)
		head = head->next;
	rotate_and_push(stack_b, stack_a, head->pos);
}

void	rotate_and_push(t_stack_node **stack_b, t_stack_node **stack_a, int pos)
{
	int				i;
	int				mid;
	t_stack_node	*head;
	head = *stack_b;
	i = 1;
	mid = ft_list_size_int(*stack_b)/2 + 1;
	while (head->pos != pos)
	{
		if (i > mid)
		{
			while ((*stack_b)->pos != pos)
				rrb(stack_b);
			pa(stack_b, stack_a);
			return ;
			//break;
		}
		i++;
		head = head->next;
	}
	i--;
	while (i > 0)
	{
		rb(stack_b);
		i--;
	}
	pa(stack_b, stack_a);
	head = NULL;
}
