/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wedos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 09:59:12 by wedos-sa          #+#    #+#             */
/*   Updated: 2025/09/16 18:31:30 by wedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_order(t_stack_node **stack_a)
{
	t_stack_node	*stack_b;
	int				size_list;

	stack_b = NULL;
	size_list = ft_list_size_int(*stack_a);
	stack_b = stack_to_b(stack_a, &stack_b, size_list);
	stack_a_organizer(stack_a);
	while (stack_b != NULL)
		stack_to_a(stack_a, &stack_b);
}

int	size_max_conteiner(t_stack_node *stack_a)
{
	int	conteiner_max;

	if (ft_list_size_int(stack_a) >= 499)
		conteiner_max = 35;
	else if (ft_list_size_int(stack_a) >= 99)
		conteiner_max = 15;
	else
		conteiner_max = ft_list_size_int(stack_a) / 2;
	return (conteiner_max);
}

t_stack_node	*stack_to_b(t_stack_node **s_a, t_stack_node **s_b, int size)
{
	int				i;
	int				conteiner_min;
	int				conteiner_max;
	int				conteiner;

	conteiner_max = size_max_conteiner(*s_a);
	conteiner_min = 0;
	i = 0;
	conteiner = conteiner_max;
	while (ft_list_size_int(*s_a) >= 4)
	{
		if ((*s_a)->pos > size - 3)
			ra(s_a);
		else
		{
			if ((*s_a)->pos <= conteiner_max
				&& (*s_a)->pos >= conteiner_min)
			{
				i++;
				pb(s_a, s_b);
				if (i >= conteiner_max)
				{
					conteiner_min = conteiner_max;
					conteiner_max = conteiner_max + conteiner;
				}
			}
			else
				ra(s_a);
		}
	}
	return (*s_b);
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
	mid = ft_list_size_int(*stack_b) / 2 + 1;
	while (head->pos != pos)
	{
		if (i > mid)
		{
			while ((*stack_b)->pos != pos)
				rrb(stack_b);
			pa(stack_b, stack_a);
			return ;
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
