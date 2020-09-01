/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhilary <fhilary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 15:31:52 by fhilary           #+#    #+#             */
/*   Updated: 2020/09/01 15:33:08 by fhilary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	pr_skip_space(t_parse *parser, char *line)
{
	while (ft_isspace(line[parser->column]))
		parser->column++;
	if (line[parser->column] == COMMENT_CHAR ||
	line[parser->column] == ALT_COMMENT_CHAR)
	{
		while (line[parser->column])
			parser->column++;
	}
}

void	coll_skip_tokens(t_parse *parser)
{
	while (GET_PTOKENS(parser, type, FT_QUEHEAD) == NEW_LINE ||
	GET_PTOKENS(parser, type, FT_QUEHEAD) == END_LINE)
		ft_quepop(parser->tokens);
}
