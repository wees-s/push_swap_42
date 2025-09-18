/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wedos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 17:29:50 by wedos-sa          #+#    #+#             */
/*   Updated: 2025/09/18 18:11:58 by wedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **arr_arr)
{
	int	i;

	i = 0;
	while (arr_arr[i])
	{
		free(arr_arr[i]);
		i++;
	}
	free(arr_arr);
}

void	free_stack(t_stack_node *stack)
{
	t_stack_node	*temp;

	while (stack)
	{
		temp = stack->next;
		free(stack);
		stack = temp;
	}
}

void	free_all(char **arr_arr, t_stack_node *stack)
{
	free_stack(stack);
	free_split(arr_arr);
}

void	error_check_num(char **stack, long long int temp)
{
	int	i;

	i = 1;
	while (stack[i] != NULL)
	{
		if (stack[1] != NULL && temp == ft_atoi(stack[i]))
		{
			free_split(stack);
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	if (temp > INT_MAX || temp < INT_MIN)
	{
		free_split(stack);
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}
