/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wedos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 17:40:50 by wedos-sa          #+#    #+#             */
/*   Updated: 2025/09/17 17:41:31 by wedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	size_max_conteiner(t_stack_node *stack_a)
{
	int	conteiner_max;

	if (ft_list_size_int(stack_a) == 500)
		conteiner_max = 100;
	else if (ft_list_size_int(stack_a) > 199)
		conteiner_max = 60;
	else if (ft_list_size_int(stack_a) > 99)
		conteiner_max = 30;
	else
		conteiner_max = ft_list_size_int(stack_a) / 2;
	return (conteiner_max);
}

void	stack_b(t_stack_node **s_a, t_stack_node **s_b, int size, int i)
{
	int				conteiner_min;
	int				conteiner_max;

	conteiner_max = size_max_conteiner(*s_a);
	conteiner_min = 0;
	while (ft_list_size_int(*s_a) >= 4)
	{
		if ((*s_a)->pos > size - 3)
			ra(s_a);
		else if ((*s_a)->pos <= conteiner_max && (*s_a)->pos >= conteiner_min)
		{
			i++;
			pb(s_a, s_b);
			if ((*s_b)->pos > (conteiner_max + conteiner_min) / 2)
				rb(s_b);
			if (i >= conteiner_max)
			{
				conteiner_min = conteiner_max;
				conteiner_max = conteiner_max + size_max_conteiner(*s_a);
			}
		}
		else
			ra(s_a);
	}
}

void	stack_a_organizer(t_stack_node **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->pos;
	b = (*stack_a)->next->pos;
	c = (*stack_a)->next->next->pos;
	if (a > b && a < c)
		sa(stack_a);
	else if (a > b && b > c)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (a > c && b < c)
		ra(stack_a);
	else if (a < b && a > c)
		rra(stack_a);
	else if (a < b && b > c)
	{
		sa(stack_a);
		ra(stack_a);
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
		if (i++ > mid)
		{
			while ((*stack_b)->pos != pos)
				rrb(stack_b);
			pa(stack_b, stack_a);
			return ;
		}
		head = head->next;
	}
	i--;
	while (i-- > 0)
		rb(stack_b);
	pa(stack_b, stack_a);
	head = NULL;
}
