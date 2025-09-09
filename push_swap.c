/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wedos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:37:19 by wedos-sa          #+#    #+#             */
/*   Updated: 2025/09/09 10:17:59 by wedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	*stack_checker(char **argv)
{
	int			i;
	int			j;
	char		*string;

	string = NULL;
	i = 0;
	j = 0;
	while (argv[j])
	{
		string = argv[j];
		if (string[i] == '-' || string[i] == '+')
		{
			if ((string[i++] < '0' && string[i] > '9') || !string[i])
				return (NULL);
		}
		while (string[i])
		{
			if (ft_isdigit(string[i]) == 0)
				return (NULL);
			i++;
		}
		j++;
		i = 0;
	}
	return ((void *)1);
}

static char	*join_args(int argc, char **argv)
{
	int		i;
	char	*res;
	char	*temp_res;

	res = NULL;
	temp_res = " ";
	i = 1;
	while (i < argc)
	{
		res = ft_strjoin(argv[i], " ");
		temp_res = ft_strjoin(temp_res, res);
		i++;
	}
	return (temp_res);
}

static char	**inicial_checker(int argc, char **argv)
{
	int		i;
	void	*temp;

	temp = 0;
	i = 0;
	if (argc >= 3)
		argv = ft_split(join_args(argc, argv), ' ');
	if (argc < 2 || (argc == 2 && !argv[1][i]))
		;
	else if (argc >= 2)
	{
		if (argc == 2)
			argv = ft_split(argv[1], ' ');
		temp = stack_checker(argv);
		if (temp == (void *)1)
			return (argv);
	}
	free(temp);
	free_split(argv);
	ft_printf("Error\n");
	return (NULL);
}

long int	insert_elem_checker(char *string, char **arr_arr, size_t j)
{
	//size_t			i;
	long int		nb;

	//i = 0;
	nb = ft_atoi(string);
	while (arr_arr[j])
	{
		if (nb == (long int)ft_atoi(arr_arr[j]))
			return (LONG_MAX);
		j++;
	}
	return (nb);
}

int	main(int argc, char **argv)
{
	char			**stack;
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;
	//t_stack_node	*head;

	stack_b = NULL;
	stack = inicial_checker(argc, argv);
	if (stack == NULL)
		return (0);
	else
	{
		stack_a = start_stack_a(stack);
		ft_printf("\n================================\n");
		ft_printf("\nMOVIMENTOS:\n");
		pb(&stack_a, &stack_b);
		pb(&stack_a, &stack_b);
		pb(&stack_a, &stack_b);
		pb(&stack_a, &stack_b);
		pa(&stack_b, &stack_a);
		sa(&stack_a);
		pa(&stack_b, &stack_a);
		ss(&stack_a, &stack_b);
		ft_printf("\n================================\n");
		ft_printf("\nSTACK_A\n");
		while (stack_a != NULL)
		{
			ft_printf("\nPOINTER = %p STACK_A NUM: %d\nSTACK_A PREV POINTER: %p\nSTACK_A NEXT POINTER: %p\n", stack_a, (int)stack_a -> num, stack_a -> prev, stack_a -> next);
			stack_a = stack_a -> next;
		}
		ft_printf("\n================================\n");
		ft_printf("\nSTACK_B\n");
		while (stack_b != NULL)
		{
			ft_printf("\nPOINTER = %p STACK_B NUM: %d\nSTACK_B PREV POINTER: %p\nSTACK_B NEXT POINTER: %p\n", stack_b, (int)stack_b -> num, stack_b -> prev, stack_b -> next);
			stack_b = stack_b -> next;
		}
	}
	free_stack(stack_a);
	free_stack(stack_b);
	free_split(stack);
	return (0);
}
