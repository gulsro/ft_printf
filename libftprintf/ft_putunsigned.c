/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putunsigned.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: gozturk <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/14 17:13:15 by gozturk       #+#    #+#                 */
/*   Updated: 2022/11/14 17:20:51 by gozturk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_putunsigned(unsigned int i)
{
	int	len;

	len = 0;
	if (i > 10)
		len += ft_putunsigned(i / 10);
	i = i % 10;
	i += '0';
	return (len + write(1, &i, 1));	
}
