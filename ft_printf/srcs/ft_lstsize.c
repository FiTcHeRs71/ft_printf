/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yourlogin <youremail@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 20:55:38 by yourlogin         #+#    #+#             */
/*   Updated: 2025/10/10 20:55:38 by yourlogin        ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

/*
FT_LSTSIZE (simplified)

NAME
	ft_lstsize -- returns the number of element in the list
SYNOPSIS
	int *ft_lstsize(t_list *lst);
DESCRIPTION
	Count the number of elements of the list
PARAMETERS
	lst: start of the list
RETURN VALUES
	The size of the list
AUTHORIZED EXTERNAL FUNCTIONS
	None
	*/