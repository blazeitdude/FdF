/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldione <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 19:14:15 by ldione            #+#    #+#             */
/*   Updated: 2021/10/12 16:29:04 by ldione           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int l)
{
	if (l >= 48 && l <= 57)
		return (1);
	return (0);
}
