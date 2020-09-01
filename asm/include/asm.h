/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhilary <fhilary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 19:53:09 by blinnea           #+#    #+#             */
/*   Updated: 2020/08/28 18:13:20 by fhilary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACM_H

# define ACM_H

# include "libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include "libft_printf.h"
#include "libft_get_next_line.h"
# include "op.h"

# define ERR_PARSER_INIT		"ERROR: Can\'t initialize parser"
# define ERR_TOKEN_INIT			"ERROR: Can\'t initialize token"
# define ERR_STATEMENT_INIT		"ERROR: Can\'t initialize statement"
# define ERR_OPEN_FILE			"ERROR: Can\'t open file with champion"
# define ERR_READ_FILE			"ERROR: Can\'t read file with champion"
# define ERR_CREATE_FILE		"ERROR: Can\'t create file"
# define ERR_INVALID_FILE		"ERROR: Invalid file with champion"
# define ERR_INVALID_MAGIC		"ERROR: Invalid magic header"
# define ERR_NO_NULL			"ERROR: No null control bytes"
# define ERR_CODE_INIT			"ERROR: Can\'t initialize string of code"
# define ERR_INVALID_CODE_SIZE	"ERROR: Invalid code size"

# define LEXICAL_ERROR			"Lexical error at"
# define ERR_LEN_STRING			"String too long (Max length 2048)"
# define ERR_NAME_LEN			"Champion name too long (Max length 128)"
# define ERR_COMMENT_LEN		"Champion comment too long (Max length 2048)"
# define ERR_NO_NAME_OR_COMMENT	"Champion has no name or comment"
# define ERR_INVALID_INSTRUCT	"Invalid instruction"
# define ERR_INVALID_PARAMETP	"Invalid parameter"
# define ERR_SYNTAX				"Syntax error"
# define ERR_INVALID_LABLE		"Invalid lable"

typedef enum	e_type
{
	LABEL,
	INSTRUCTION,
	COMMAND_NAME,
	COMMAND_COMMENT,
	INDIRECT,
	INDIRECT_LABLE,
	REGISTER,
	SEPARATOR,
	DIRECT_LABEL,
	DIRECT,
	STRING,
	COMMAND,
	NEW_LINE,
	END_LINE,
	END_FILE
}				t_type;

static char	*g_typearr[] = {
	"LABEL",
	"INSTRUCTION",
	"COMMAND_NAME",
	"COMMAND_COMMENT",
	"INDIRECT",
	"INDIRECT_LABEL"
	"REGISTER",
	"SEPARATOR",
	"DIRECT_LABEL",
	"DIRECT",
	"STRING",
	"COMMAND",
	"NEW_LINE",
	"END_LINE",
	"END_FILE"
};

# define TSTR(T) (g_typearr[T])

# define REV_4(n) (((n) >> 24) & 0x000000FF) | (((n) >> 8) & 0x0000FF00) | \
(((n) << 8) & 0x00FF0000) | (((n) << 24) & 0xFF000000)

# define REV_2(n) ((((n) >> 8) & 0x00FF) | (((n) << 8) & 0xFF00))

typedef struct	s_token
{
	char	content[COMMENT_LENGTH];
	t_type	type;
	int		row;
	int		column;
	int		position;
}				t_token;

typedef struct	s_lable
{
	char	name[CHAMP_MAX_SIZE];
	int32_t	lab_pos;
	int		mentions[CHAMP_MAX_SIZE];
	int		size;
	int		m_position;
}				t_lable;

typedef struct	s_parse
{
	char		name[PROG_NAME_LENGTH];
	char		comment[COMMENT_LENGTH];
	int			fdin;
	int			fdout;
	int			row;
	int			column;
	t_queue		*tokens;
	int32_t		position;
	int			label_count;
	t_htable	*op_htable;
	t_htable	*lables;
}				t_parse;

# define GET_TF(ts, f, HT) (HT(t_token, ts)->f)
# define GET_PTOKENS(p, f, HT) (GET_TF(p->tokens, f, HT))

int				isrighttype(char *name);
char			*new_filename(char *file, char *type);

void			add_token(t_parse *parser, t_type type);

void			parse(t_parse *parser);
void			pr_skip_space(t_parse *parser, char *line);
void			pr_skip_comment(t_parse *parser, char *line);
void			pr_gettoken(t_parse *parser, char *line);
void			string_parse(t_parse *parser, char *line);
void			lable_parse(t_parse *parser, char *line);
void			number_parse(t_parse *parser, char *line);
void			register_parse(t_parse *parser, char *line);
int				register_len(t_parse *parser, char *line);
void			other_parse(t_parse *parser, char *line);

void			instruction_collect(t_parse *parser, t_list **tokens);
void			collection(t_parse *parser);

void			collection_error(char *type, t_token *token);
void			lex_error(int row, int column);
void			error(char *err);

void			shaping(t_parse *parser);

void			show_tokens(t_parse *parser);

int				get_arg_type(t_token *token);
void			get_label_htable(t_parse *parser);
void			get_op_htable(t_parse *parser);
#endif
