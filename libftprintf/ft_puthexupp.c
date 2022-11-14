/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_puthexupp.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: gozturk <marvin@codam.nl>                    +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/14 17:11:43 by gozturk       #+#    #+#                 */
/*   Updated: 2022/11/14 17:11:55 by gozturk       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int ft_puthexupp(unsigned long i)
{
    int len;

    if (i > 15)
        len +=  ft_puthexupp(i / 16);
    i = i % 16;
    if (i < 10)
        i += 48;
    else
        i += 'A' - 10;
    return (len + write(1, &i, 1));
}
