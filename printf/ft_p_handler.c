/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zabdulza <zabdulza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:50:18 by zabdulza          #+#    #+#             */
/*   Updated: 2023/05/22 15:50:22 by zabdulza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	handle_pointer(va_list args)
{
	void	*ptr;

	ptr = va_arg(args, void *);
	if (ptr == NULL)
		return (ft_putstr("(nil)"));
	else
		return (ft_itoa_base((unsigned long long)ptr, 16,
				"0123456789abcdef", 2));
}
