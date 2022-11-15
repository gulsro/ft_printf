/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_puthexlow.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: gozturk <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/14 17:12:04 by gozturk       #+#    #+#                 */
/*   Updated: 2022/11/14 17:12:16 by gozturk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexlow(unsigned long i)
{
	int	len;
	int	arr[16];
	int	remainder;

	remainder = 0;
	arr[16] = {0, 1, 2, 3, 4, 5, 6, 7,
		8, 9, a, b, c, d, e, f};
	len = 0;
	if (i > 15)
	len +=  ft_puthexlow(i / 16);
	remainder = i % 16;
	i = arr[remainder - 1];;
	return (len + write(1, &i, 1));
}
