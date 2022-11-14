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

int	ft_puthexlow(unsigned long i)
{
	int len;

	if (i > 15)
	len +=  ft_puthexlow(i / 16);
	i = i % 16;
	if (i < 10)
		i += 48;
	else
		i += 'a' - 10;
	return (len + write(1, &i, 1));
}
