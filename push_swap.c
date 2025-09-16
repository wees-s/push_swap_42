/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wedos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 14:37:19 by wedos-sa          #+#    #+#             */
/*   Updated: 2025/09/16 17:45:30 by wedos-sa         ###   ########.fr       */
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
	char	*to_free;

	res = NULL;
	temp_res = ft_strdup("");
	i = 1;
	while (i < argc)
	{
		res = ft_strjoin(argv[i], " ");
		to_free = temp_res;
		temp_res = ft_strjoin(to_free, res);
		free(res);
		free(to_free);
		i++;
	}
	return (temp_res);
}

static char	**inicial_checker(int argc, char **argv)
{
	int		i;
	void	*temp;
	char	*to_free;

	temp = 0;
	i = 0;
	if (argc >= 3)
	{
		to_free = join_args(argc, argv);
		argv = ft_split(to_free, ' ');
		free(to_free);
	}
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
	return (NULL);
}

long long int	insert_elem_checker(char *string, char **arr_arr, size_t j)
{
	long long int		nb;

	nb = ft_atoi(string);
	while (arr_arr[j])
	{
		if (nb == ft_atoi(arr_arr[j]))
			return (LONG_MAX);
		j++;
	}
	return (nb);
}

int	main(int argc, char **argv)
{
	char			**stack;
	t_stack_node	*stack_a;
	int				j;
	t_stack_node	*head;

	j = 0;
	stack = inicial_checker(argc, argv);
	if (stack == NULL)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	else
		stack_a = start_stack_a(stack);
	head = stack_a;
	while (j != argc)
	{
		if (argv[j][0] == '\0')
		{
			write(2, "Error\n", 6);
			return (0);
		}
		j++;
	}
	index_list(&stack_a);
	stack_order(&head);
	free_stack(stack_a);
	free_split(stack);
	return (0);
}
