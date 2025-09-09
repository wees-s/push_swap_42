/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wedos-sa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 13:44:24 by wedos-sa          #+#    #+#             */
/*   Updated: 2025/09/09 17:59:13 by wedos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <limits.h>

/*struct space*/
typedef struct s_stack_node
{
	int					num;
	int					pos;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

/*number type*/
long long int		insert_elem_checker(char *string, char **arr_arr, size_t j);
int					ft_list_size_int(t_stack_node *begin_list);

/*void type*/
void				ft_list_push_back_int(t_stack_node **begin_list, int data);
void				free_split(char **arr_arr);
void				free_stack(t_stack_node *stack);

/*struct type*/
t_stack_node		*start_stack_a(char **stack);
t_stack_node		*ft_list_last_int(t_stack_node *begin_list);
t_stack_node		*ft_create_elem_int(int nb);

/*swap functions*/
void				sa(t_stack_node	**stack_a);
void				sb(t_stack_node	**stack_b);
void				ss(t_stack_node	**stack_a, t_stack_node **stack_b);
void				pb(t_stack_node **begin_list_a,
						t_stack_node **begin_list_b);
void				pa(t_stack_node **begin_list_b,
						t_stack_node **begin_list_a);
void				push(t_stack_node **from, t_stack_node **to);
void				rotate(t_stack_node **begin_list);
void				ra(t_stack_node **stack_a);
void				rb(t_stack_node **stack_b);
void				rr(t_stack_node **stack_a, t_stack_node **stack_b);
void				reverse_rotate(t_stack_node **begin_list);
void				rra(t_stack_node **stack_a);
void				rrb(t_stack_node **stack_b);
void				rrr(t_stack_node **stack_a, t_stack_node **stack_b);

#endif
