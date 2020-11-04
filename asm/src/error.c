/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhilary <fhilary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 15:31:36 by fhilary           #+#    #+#             */
/*   Updated: 2020/11/04 20:08:37 by fhilary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft_printf.h"
#include "libft_string.h"
#include <unistd.h>

// TODO: rewrite errors to clear parser before exit

void	lex_error(t_parse *parser, int column)
{
	ft_printf_fd(STDERR_FILENO, "Lexical error at [%d %d]\n", parser->row,
	column);
	clear_parser(parser);
	exit(1);
}

void	error(char *err, t_parse *parser)
{
	ft_printf_fd(STDERR_FILENO, "%s\n", err);
	clear_parser(parser);
	exit(1);
}

void	collection_error(char *type, t_token *token, t_parse *parser)
{
	if (type == ERR_INV_INST)
	{
		ft_printf_fd(STDERR_FILENO,
		"Invalid instruction at token [TOKEN][%d:%d] %s\n",
		token->row, token->column,
		token->content);
	}
	else if (type == ERR_INV_PRM)
	{
		ft_printf_fd(STDERR_FILENO,
		"Invalid parameter type direct for instruction %s\n",
		token->content);
	}
	else if (type == ERR_SYNTAX)
	{
		ft_printf_fd(STDERR_FILENO,
		"Syntax error at token [TOKEN][%d:%d] %s\n",
		token->row, token->column,
		token->content);
	}
	else if (type == ERR_INV_LABLE)
	{
		ft_printf_fd(STDERR_FILENO,
		"No such label [TOKEN][%d:%d] %s\n",
		token->row, token->column,
		token->content);
	}
	clear_parser(parser);
	exit(1);
}
