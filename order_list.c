/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wedos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 09:59:12 by wedos-sa          #+#    #+#             */
/*   Updated: 2025/09/13 17:09:59 by wedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rotate_and_push(t_stack_node **stack_b, t_stack_node **stack_a, int pos);
int cost_find_big(t_stack_node *stack_b, t_stack_node *stack_a);
int cost_find_small(t_stack_node *stack_b, int pos);

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
	stack_a_organizer(stack_a);
	while (stack_b != NULL)
	{
		stack_to_a(stack_a, &stack_b);
	}
	/**********************************
	 * PRINT TESTE:
	 * LISTA B;
	 * LISTA A;
	 * ********************************/

	ft_printf("\n====lista B====\n");
	while (stack_b != NULL)
	{
		ft_printf("NUM: %d POS: %d\n", stack_b->num, stack_b->pos);
		stack_b = stack_b -> next;
	}
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
	int				small_pos;
	t_stack_node	*head;

	head = *stack_b;
	small_pos = 1;
	//ft_printf("quantas vezes entrei aqui\n");
	if (cost_find_big(*stack_b, *stack_a) > cost_find_small(*stack_b, small_pos))
	{
	//	ft_printf("eu to no small\n");
		rotate_and_push(stack_b, stack_a, small_pos);
		ra(stack_a);
		small_pos++;
	}
	//else if (cost_find_big(*stack_b, *stack_a) == cost_find_small(*stack_b, small_pos))
	//{
	//	ft_printf("eu to no meio\n");
	//	if
	//	small_pos++;
	//	pa(stack_b, stack_a);
	//	ra(stack_a);
	//}
	else
	{
	//	ft_printf("eu to no big\n");
		while (head->pos + 1 != (*stack_a)->pos)
			head = head->next;
//		ft_printf("valor de stack_a->pos %d", (*stack_a)->pos);
//		ft_printf("valor de head->pos %d", head->pos);
		rotate_and_push(stack_b, stack_a, head->pos);
	}
}

int	cost_find_big(t_stack_node *stack_b, t_stack_node *stack_a)
{
	int	i;
	int mid;

	i = 1;
	mid = ft_list_size_int(stack_b)/2;
	while (stack_b != NULL)
	{
		i++;
		if (stack_b->pos == stack_a->pos - 1)
			break;
		if (i > mid)
		{
			while (stack_b->pos != stack_a->pos - 1)
			{
				stack_b = stack_b -> next;
				i--;
			}
			break;
		}
		stack_b = stack_b -> next;
	}
	return (i);
}

int	cost_find_small(t_stack_node *stack_b, int pos)
{
	int	i;
	int mid;

	i = 0;
	mid = ft_list_size_int(stack_b)/2;
	while (stack_b != NULL)
	{
		i++;
		if (stack_b->pos == pos)
			break;
		if (i > mid)
		{
			while (stack_b->pos != pos)
			{
				i--;
				stack_b = stack_b -> next;
			}
			break;
		}
		stack_b = stack_b -> next;
	}
	return (i);
}

void	rotate_and_push(t_stack_node **stack_b, t_stack_node **stack_a, int pos)
{
	int				i;
	int				mid;
	t_stack_node	*head;
	ft_printf("numero da POS que eu estou procurando: %d", pos);
	head = *stack_b;
	i = 0;
	mid = ft_list_size_int(*stack_b)/2;
	while (head->pos != pos)
	{
		//ft_printf("\ncabeça do while\nvalor de i = %d", i);
		i++;
		if (i > mid)
		{
			//ft_printf("\ndentro de i > mid\nvalor de i = %d", i);
			while (head->pos != pos)
			{
				i--;
				head = head->next;
//				ft_printf("\nhead->pos while i--\nvalor de i = %d", i);
			}
			while (i > 0)
			{
				rrb(stack_b);
				i--;
			}
			pa(stack_b, stack_a);
			break;
		}
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
