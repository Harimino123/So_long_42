/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolof <hrasolof@student.42antanana      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 11:04:36 by hrasolof          #+#    #+#             */
/*   Updated: 2024/03/14 11:20:39 by hrasolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*n_content;

	n_content = malloc(sizeof(t_list));
	if (!n_content)
		return (NULL);
	n_content -> content = content;
	n_content -> next = NULL;
	return (n_content);
}
