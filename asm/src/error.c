/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhilary <fhilary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 15:31:36 by fhilary           #+#    #+#             */
/*   Updated: 2020/09/01 15:31:37 by fhilary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft_printf.h"
#include "libft_string.h"
#include <unistd.h>

void	lex_error(int row, int column)
{
	ft_printf_fd(STDERR_FILENO, "%Lexical error at [%d %d]\n", row, column);
	exit(1);
}

void	error(char *err)
{
	ft_printf_fd(STDERR_FILENO, "%s\n", err);
	exit(1);
}

void	collection_error(char *type, t_token *token)
{
	if (!ft_strcmp(type, ERR_INVALID_INSTRUCT))
	{
		ft_printf_fd(STDERR_FILENO,
		"Invalid instruction at token [TOKEN][%d:%d] %s\n",
		token->row, token->column,
		token->content);
	}
	else if (!ft_strcmp(type, ERR_INVALID_PARAM))
	{
		ft_printf_fd(STDERR_FILENO,
		"Invalid parameter type direct for instruction %s\n",
		token->content);
	}
	else if (!ft_strcmp(type, ERR_SYNTAX))
	{
		ft_printf_fd(STDERR_FILENO,
		"Syntax error at token [TOKEN][%d:%d] %s\n",
		token->row, token->column,
		token->content);
	}
	else if (!ft_strcmp(type, ERR_INVALID_LABLE))
	{
		ft_printf_fd(STDERR_FILENO,
		"No such label [TOKEN][%d:%d] %s\n",
		token->row, token->column,
		token->content);
	}
	exit(1);
}
