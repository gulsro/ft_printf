/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: gozturk <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/14 17:11:21 by gozturk       #+#    #+#                 */
/*   Updated: 2022/11/14 17:11:28 by gozturk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int ft_putstr(char *s)
{
	size_t	len;

	len = ft_strlen(s);
	return(write(1, s, len));
}
