/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wedos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 14:56:26 by wedos-sa          #+#    #+#             */
/*   Updated: 2025/09/09 19:05:16 by wedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_node	*ft_list_last_int(t_stack_node *begin_list)
{
	while (begin_list -> next != NULL)
	{
		begin_list = begin_list -> next;
	}
	return (begin_list);
}

t_stack_node	*ft_create_elem_int(int nb)
{
	t_stack_node	*ptr;

	ptr = malloc(sizeof(t_stack_node));
	if (!ptr)
		return (NULL);
	if (ptr)
	{
		ptr->num = nb;
		ptr->next = NULL;
		ptr->prev = NULL;
	}
	return (ptr);
}

void	ft_list_push_back_int(t_stack_node **begin_list, int data)
{
	t_stack_node	*last;
	t_stack_node	*item;

	item = ft_create_elem_int(data);
	if (!item)
		return ;
	last = ft_list_last_int(*begin_list);
	last->next = item;
	item->prev = last;
}

t_stack_node	*start_stack_a(char **stack)
{
	t_stack_node		*stack_a;
	size_t				i;
	long long int		temp;
	size_t				j;

	stack_a = ft_create_elem_int(ft_atoi(stack[0]));
	i = 1;
	j = 2;
	while (stack[i])
	{
		temp = insert_elem_checker(stack[i], stack, j);
		j++;
		if (temp > 2147483647 || temp < -2147483648)
		{
			ft_printf("Error\n");
			exit(EXIT_FAILURE);
		}
		ft_list_push_back_int(&stack_a, temp);
		i++;
	}
	return (stack_a);
}

int	ft_list_size_int(t_stack_node *begin_list)
{
	int				i;
	t_stack_node	*index;

	index = begin_list;
	i = 0;
	while (index)
	{
		i++;
		index = index -> next;
	}
	return (i);
}
