/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvalerii <kvalerii@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:46:43 by kvalerii          #+#    #+#             */
/*   Updated: 2024/11/28 17:07:29 by kvalerii         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

#include "push_swap.h"

int	is_elem_in_array(int elem, int **array, int index);
int	ft_is_valid_sign(char c, int j);
int	is_argv_i_valid(char *argv);

#endif