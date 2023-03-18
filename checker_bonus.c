/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:56:09 by ahaloui           #+#    #+#             */
/*   Updated: 2023/03/11 17:40:42 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_element_bonus(t_list **head, int ac, char **av)
{
	char	**split;
	int		i;

	i = 0;
	split = check_and_join_string(ac, av);
	*head = ft_lstnew(ft_atoi(split[i]));
	i = 1;
	while (split[i])
	{
		ft_lstadd_back(head, ft_lstnew(ft_atoi(split[i])));
		i++;
	}
	free_split(split);
	if (check_if_duplicate_nbr(head))
	{
		free_list(head);
		quit();
	}
	index_list(head);
}

int	help1_check_action(char *line, t_list **head_a, t_list **head_b)
{
	if (!(ft_strncmp(line, "sa\n", 3)))
	{
		swap_a(head_a, 0);
		return (0);
	}
	if (!(ft_strncmp(line, "sb\n", 3)))
	{
		swap_b(head_b, 0);
		return (0);
	}
	if (!(ft_strncmp(line, "ss\n", 3)))
	{
		swap_a_swap_b(head_a, head_b, 0);
		return (0);
	}
	if (!(ft_strncmp(line, "pa\n", 3)))
	{
		push_a(head_a, head_b, 0);
		return (0);
	}
	return (1);
}

int	help2_check_action(char *line, t_list **head_a, t_list **head_b)
{
	if (!(ft_strncmp(line, "pb\n", 3)))
	{
		push_b(head_a, head_b, 0);
		return (0);
	}
	if (!(ft_strncmp(line, "ra\n", 3)))
	{
		rotate_a(head_a, 0);
		return (0);
	}
	if (!(ft_strncmp(line, "rb\n", 3)))
	{
		rotate_b(head_b, 0);
		return (0);
	}
	if (!(ft_strncmp(line, "rr\n", 3)))
	{
		rotate_r(head_a, head_b, 0);
		return (0);
	}
	return (1);
}

int	check_action(char *line, t_list **head_a, t_list **head_b)
{
	if (!help1_check_action(line, head_a, head_b))
		return (0);
	if (!help2_check_action(line, head_a, head_b))
		return (0);
	if (!(ft_strncmp(line, "rra\n", 4)))
	{
		r_rotate_a(head_a, 0);
		return (0);
	}
	if (!(ft_strncmp(line, "rrb\n", 4)))
	{
		r_rotate_b(head_b, 0);
		return (0);
	}
	if (!(ft_strncmp(line, "rrr\n", 4)))
	{
		r_rotate_r(head_a, head_b, 0);
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	char	*line;
	t_list	*head_a;
	t_list	*head_b;

	if (ac == 1)
		return (0);
	add_element_bonus(&head_a, ac, av);
	line = get_next_line(0);
	while (line)
	{
		if (check_action(line, &head_a, &head_b))
		{
			free_list(&head_a);
			free_list(&head_b);
			quit();
		}
		free(line);
		line = get_next_line(0);
	}
	if (is_nbr_sorted(&head_a) && !head_b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (free_list(&head_a), free_list(&head_b), 0);
}
