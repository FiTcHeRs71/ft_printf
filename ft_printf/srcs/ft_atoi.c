/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yourlogin <youremail@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 20:53:30 by yourlogin         #+#    #+#             */
/*   Updated: 2025/10/10 20:53:30 by yourlogin        ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"
#include "../include/libft.h"

int	ft_atoi(const char *str)
{
	int	ngps;
	int	result;

	ngps = 1;
	result = 0;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
	{
		str++;
	}
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
		{
			ngps *= -1;
		}
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = ((result * 10) + (*str - 48));
		str++;
	}
	return (result * ngps);
}

/*
ISPRINT(3) (simplified)

NAME
    isprint -- printing character test (space character inclusive)
SYNOPSIS
    int isprint(int c)
DESCRIPTION
    The isprint() function tests for any printing character, 
	including space. 
	The value of the argument must representable as an unsigned char 
	or the value of EOF.
RETURN VALUES
    The isprint() function returns zero if the character tests 
	false and returns non-zero if the character tests true.*/