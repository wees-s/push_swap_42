/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wedos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 09:59:12 by wedos-sa          #+#    #+#             */
/*   Updated: 2025/09/12 18:20:29 by wedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    stack_a_organizer(t_stack_node **stack_a);
void	stack_to_a(t_stack_node **stack_a, t_stack_node **stack_b);
int		finder(t_stack_node *stack, int pos_x);

void	stack_order(t_stack_node **stack_a)
{
	stack_to_b(stack_a);
}

void	stack_to_b(t_stack_node **stack_a)
{
	t_stack_node	*stack_b;
	int				midle_stack;
	int				size_list_a;

	size_list_a = ft_list_size_int(*stack_a);
	midle_stack = (size_list_a / 2);
	stack_b = NULL;
	while (ft_list_size_int(*stack_a) >= 4)
	{
		if ((*stack_a) -> pos  > size_list_a - 3)
			ra(stack_a);
		else
		{
			pb(stack_a, &stack_b);
			if (ft_list_size_int(stack_b) >= 2)
			{
				if (stack_b -> pos >= midle_stack)
					rb(&stack_b);
			}
		}
	}
	stack_a_organizer(stack_a);//, &stack_b);
	int i = 0;
	while (i < 4)
	{
		stack_to_a(stack_a, &stack_b);
		i++;
	}
	/**********************************
	 * PRINT TESTE:
	 * LISTA B;
	 * LISTA A;
	 * ********************************/

//	ft_printf("\n====lista B====\n");
//	while (stack_b != NULL)
//	{
//		ft_printf("NUM: %d POS: %d\n", stack_b->num, stack_b->pos);
//		stack_b = stack_b -> next;
//	}
	ft_printf("\n====lista A====\n");
	while (*stack_a != NULL)
	{
		ft_printf("NUM: %d POS: %d\n", (*stack_a)->num, (*stack_a)->pos);
		*stack_a = (*stack_a) -> next;
	}

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
	else
	{
		rra(stack_a);
		sa(stack_a);
	}
}

void	stack_to_a(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int				n;
	t_stack_node	*head;
	t_stack_node	*tail;

	tail = ft_list_last_int(*stack_b);
	head = *stack_b;
	while (head != NULL)
	{
		if (head->pos == (*stack_a)->pos - 1)
			break;
		head = head->next;
	}
	n = finder(*stack_b, head->pos);
	if (n > 0)
	{
		while (head->pos != (*stack_a)->pos - 1)
			rb(stack_b);
		pa(&head, stack_a);
	}
	else
	{
		while(head->pos != (*stack_a)->pos - 1)
			rrb(stack_b);
		pa(&head, stack_a);
	}
}

int	finder(t_stack_node *stack, int pos_x)
{
	int i;
	int	j;

	i = 0;
	while (stack->pos != pos_x)
	{
		i++;
		stack = stack->next;
	}
	j = 0;
	while (stack->pos != pos_x)
	{
		j++;
		stack = stack->prev;
	}
	return (i-j);
	//if valor negativo, percorra de frente
	//caso contrário, percorra de trás
}
