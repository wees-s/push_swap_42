/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wedos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 09:59:12 by wedos-sa          #+#    #+#             */
/*   Updated: 2025/09/15 19:24:14 by wedos-sa         ###   ########.fr       */
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
	//ft_printf("\n==stack_to_b==\nsize_list_a: %d\n", size_list_a);
	midle_stack = (size_list_a / 2);
	//ft_printf("\n==stack_to_b==\nmidle_stack: %d\n", midle_stack);
	stack_b = NULL;
	while (ft_list_size_int(*stack_a) >= 4)
	{
	//	ft_printf("\n==stack_to_b==\nwhile list_size >= 4 %d\n", ft_list_size_int(*stack_a));
		if ((*stack_a) -> pos  > size_list_a - 3)
		{
	//		ft_printf("(if stack_a -> pos = %d) > (size_list_a - 3 = %d)\n estou rodando:\n", (*stack_a) -> pos, size_list_a - 3);
			ra(stack_a);
		}
		else
		{
	//		ft_printf("valor de stack_a -> pos = %d não é um dos 3 maiores:\n estou rodando:\n", (*stack_a)->pos);
			pb(stack_a, &stack_b);
			if (ft_list_size_int(stack_b) >= 2)
			{
	//			ft_printf("se tem mais de um item na lista_b:\n");
				if (stack_b -> pos >= midle_stack)
				{
	//				ft_printf("separo maiores para baixo\nstack_b -> pos = %d >= midle_stack: %d\n", stack_b -> pos, midle_stack);
					rb(&stack_b);
				}	
			}
		}
	}
	//ft_printf("entrando em stack_a organizer...\n");
	stack_a_organizer(stack_a);	
	//t_stack_node *lista_b = stack_b;
	//t_stack_node *lista_a = *stack_a;
	//ft_printf("\n====lista B====\n");
	//while (lista_b != NULL)
	//{
	//	ft_printf("NUM: %d POS: %d\n", lista_b->num, lista_b->pos);
	//	lista_b = lista_b -> next;
	//}
	//ft_printf("\n====lista A====\n");
	//while (lista_a != NULL)
	//{
	//	ft_printf("NUM: %d POS: %d\n", lista_a->num, lista_a->pos);
	//	lista_a = lista_a -> next;
	//}
	//ft_printf("\n\nentrando em stack_b to stack_a\n");
	//int x = 0;
	int	small_pos = 1;
	while (stack_b != NULL)
	{	
	//	x++;
	//	ft_printf("QUANTAS VEZES ENTREI NO WHILE DE STACK_B != NULL: %d\n", x);
		small_pos = stack_to_a(stack_a, &stack_b, small_pos);
	}
	/**********************************
	 * PRINT TESTE:
	 * LISTA B;
	 * LISTA A;
	 * ********************************/
/*
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
*/
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
/*	ft_printf("\n\nLISTA A ESTÁ ORGANIZADA?\n");
	ft_printf("stack_a item 1, POS: %d\n", (*stack_a)->pos);
	ft_printf("stack_a item 2, POS: %d\n", (*stack_a)->next->pos);
	ft_printf("stack_a item 3, POS: %d\n", (*stack_a)->next->next->pos);*/
}

int	stack_to_a(t_stack_node **stack_a, t_stack_node **stack_b, int small_pos)
{
	//ft_printf("estou dentro de stack_to_a\n");
	t_stack_node	*head;

	head = *stack_b;
	//ft_printf("valor de SMALL_POS = %d\n", small_pos);
	//ft_printf("COST_FIND_BIG = %d\nCOST_FIND_SMALL = %d\n", cost_find_big(*stack_b, *stack_a), cost_find_small(*stack_b, small_pos));
	if (cost_find_big(*stack_b, *stack_a) > cost_find_small(*stack_b, small_pos))
	{
	//	ft_printf("entrei em small, o valor de small_pos deve ser alterado nas próximas chamadas\n");
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
	//	ft_printf("cost find big e cost find small são iguais. adicionarei o BIG;\n");
	//	ft_printf("while head -> pos +1 != stack_a->pos, head = head->next percorrendo lista\n");
		while (head->pos + 1 != (*stack_a)->pos)
		{
			head = head->next;
	//		ft_printf("valor de HEAD->pos = %d\n", head->pos);
		}
//		ft_printf("valor de stack_a->pos %d", (*stack_a)->pos);
//		ft_printf("valor de head->pos %d", head->pos);
	//	ft_printf("entrando em rotate and push passando o valor de head\n");
		rotate_and_push(stack_b, stack_a, head->pos);
	}
	return (small_pos);
}

int	cost_find_big(t_stack_node *stack_b, t_stack_node *stack_a)
{
	int	i;
	int mid;

	i = 1;
	mid = ft_list_size_int(stack_b)/2;
	//ft_printf("\ncost_find_big, o valor de MID é IMPAR ou PAR = %d\n", mid);
	//ft_printf("\nstack_b -> pos == stack_a->pos -1\n");
	while (stack_b != NULL)
	{
	//	ft_printf("valor de stack_b->pos = %d\nvalor de stack_a->pos = %d\n", stack_b->pos, stack_a->pos);
		i++;
		if (stack_b->pos == stack_a->pos - 1)
			break;
	//	ft_printf("valor de i = %d\n", i);
		if (i > mid + 1)
		{
			while (stack_b->pos != stack_a->pos - 1)
			{
	//			ft_printf("valor de i = %d\n", i);
				stack_b = stack_b -> next;
	//			ft_printf("valor de stack_b->pos = %d\nvalor de stack_a->pos = %d\n", stack_b->pos, stack_a->pos);
				i--;
			}
			if (ft_list_size_int(stack_b) % 2 == 0)
				i++;
			break;
		}
		stack_b = stack_b -> next;
	//	ft_printf("valor de stack_b->pos = %d\nvalor de stack_a->pos = %d\n", stack_b->pos, stack_a->pos);
	}
	return (i);
}

int	cost_find_small(t_stack_node *stack_b, int pos)
{
	int	i;
	int mid;

	i = 1;
	mid = ft_list_size_int(stack_b)/2;
	//ft_printf("\ncost_find_small, o valor de MID é IMPAR ou PAR = %d\n", mid);
	//ft_printf("\nstack_b -> pos == SMALL_POS %d\n", pos);
	while (stack_b != NULL)
	{
		//ft_printf("valor de stack_b->pos = %d\nvalor de SMALL_POS = %d\n", stack_b->pos, pos);
		if (stack_b->pos == pos)
			break;
		//ft_printf("valor de i = %d\n", i);
		if (i > mid + 1)
		{
			while (stack_b->pos != pos)
			{
		//		ft_printf("valor de i = %d\n", i);
				stack_b = stack_b -> next;
		//		ft_printf("valor de stack_b->pos = %d\nvalor de SMALL_POS = %d\n", stack_b->pos, pos);
				i--;
			}	
			if (ft_list_size_int(stack_b) % 2 == 0)
				i++;
			break;
		}
		stack_b = stack_b -> next;
		i++;
		//ft_printf("valor de stack_b->pos = %d\nvalor de SMALL_POS = %d\n", stack_b->pos, pos);
	}
	return (i);
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
		//ft_printf("\ncabeça do while\nvalor de i = %d", i);
		if (i > mid)
		{
			//ft_printf("\ndentro de i > mid\nvalor de i = %d", i);
			//while (head->pos != pos)
			while ((*stack_b)->pos != pos)
			{
				rrb(stack_b);
				//i--;
				//head = head->next;
//				ft_printf("\nhead->pos while i--\nvalor de i = %d", i);
			}
			//while (i > 0)
			//{
			//	rrb(stack_b);
			//	i--;
			//}
			pa(stack_b, stack_a);
			return ;
			break;
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
