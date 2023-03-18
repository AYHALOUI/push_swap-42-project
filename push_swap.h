/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahaloui <ahaloui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 12:53:23 by ahaloui           #+#    #+#             */
/*   Updated: 2023/03/11 17:40:42 by ahaloui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include "printf/ft_printf.h"
# include "libft/libft.h"
# include "getnextline/get_next_line.h"

void	print_list(t_list *head);

// parsing functions
int		check_is_empty_string(char *str);
int		check_is_contain_all_space(char *str);
int		check_is_digit(char *str);
void	check_is_valide_string(int ac, char *str);
int		check_if_plus_mins(char *str);

// utils functions
int		check_if_duplicate_nbr(t_list **head);
char	**check_and_join_string(int ac, char **av);
int		is_nbr_sorted(t_list **head);
void	add_element(t_list **head, int ac, char **av);
int		get_nbr_instriction(int size_b, int pos);

// swap functions
void	swap_a(t_list **head_a, int flag);
void	swap_b(t_list **head_b, int flag);
void	swap_a_swap_b(t_list **head_a, t_list **head_b, int flag);

// rotate functions
void	rotate_a(t_list **head_a, int flag);
void	rotate_b(t_list **head_b, int flag);
void	rotate_r(t_list **head_a, t_list **head_b, int flag);

// reverse rotate functions
void	r_rotate_a(t_list **head_a, int flag);
void	r_rotate_b(t_list **head_b, int flag);
void	r_rotate_r(t_list **head_a, t_list **head_b, int flag);

// push functions
void	push_a(t_list **head_a, t_list **head_b, int flag);
void	push_b(t_list **head_a, t_list **head_b, int flag);

// sort three elements
void	sort_3(t_list **head_a);
void	help_sort_three(t_list **head_a, int index_node);
void	help_sort_three_1(t_list **head_a);
int		get_index_max(t_list **head, int max);
int		find_max(t_list **head);

// sort five elements
void	sort_5(t_list **head_a, t_list **head_b);

// utils1 functions
int		get_position(t_list **head, int index);
void	index_list(t_list **head);
void	free_split(char **split);
void	free_list(t_list **head);
void	quit(void);

// sort functions
void	help1_sort_all_size(t_list **head_a, t_list **head_b, int size_b);
void	help2_sort_all_size(t_list **head_a, t_list **head_b, int size_b);
void	push_to_b(t_list **head_a, t_list **head_b, int chunk);
void	sort_all_size(t_list **head_a, t_list **head_b, int chunk_divide);

// bonus file
int		check_action(char *line, t_list **head_a, t_list **head_b);
void	add_element_bonus(t_list **head, int ac, char **av);
int		help1_check_action(char *line, t_list **head_a, t_list **head_b);
int		help2_check_action(char *line, t_list **head_a, t_list **head_b);

#endif