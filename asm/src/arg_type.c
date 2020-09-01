/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhilary <fhilary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 15:02:28 by fhilary           #+#    #+#             */
/*   Updated: 2020/09/01 15:05:32 by fhilary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		get_arg_type(t_list *ltoken)
{
	t_token	*token;

	token = FT_LSTCONT(t_token, ltoken);
	if (token->type == INDIRECT || token->type == INDIRECT_LABLE)
		return (T_IND);
	else if (token->type == REGISTER)
		return (T_REG);
	else if (token->type == DIRECT_LABEL || token->type == DIRECT)
		return (T_DIR);
	return (0);
}
