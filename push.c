/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wedos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 15:22:08 by wedos-sa          #+#    #+#             */
/*   Updated: 2025/09/08 19:13:23 by wedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//PRECISO ARRUMAR EM UMA FUNÇÃO SÓ PARA SER CHAMADA
void	pa(t_stack_node **begin_list_b, t_stack_node **begin_list_a)
{
	t_stack_node	*temp;

	temp = *begin_list_b;
	(*begin_list_b)->next->prev = NULL;
	*begin_list_b = (*begin_list_b)->next;
	if (*begin_list_a == NULL)
	{
		*begin_list_a = temp;
		(*begin_list_a)->next = NULL;
	}
	else
	{
		temp->next = *begin_list_a;
		*begin_list_a = temp;
	}
}


void	pb(t_stack_node **begin_list_a, t_stack_node **begin_list_b)
{
	t_stack_node	*temp;

	temp = *begin_list_a;
	(*begin_list_a)->next->prev = NULL;
	*begin_list_a = (*begin_list_a)->next;
	if (*begin_list_b == NULL)
	{
		*begin_list_b = temp;
		(*begin_list_b)->next = NULL;
	}
	else
	{
		temp->next = *begin_list_b;
		*begin_list_b = temp;
	}
}
