/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhilary <fhilary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 19:53:09 by blinnea           #+#    #+#             */
/*   Updated: 2020/08/16 20:28:23 by fhilary          ###   ########.fr       */
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

# define ERR_STR_INIT			"ERROR: Can\'t initialize string"
# define ERR_PARSER_INIT		"ERROR: Can\'t initialize parser"
# define ERR_TOKEN_INIT			"ERROR: Can\'t initialize token"
# define ERR_LABEL_INIT			"ERROR: Can\'t initialize label"
# define ERR_MENTION_INIT		"ERROR: Can\'t initialize mention"
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

typedef enum	e_type
{
	LABEL,
	INSTRUCTION,
	COMMAND_NAME,
	COMMAND_COMMENT,
	INDIRECT,
	REGISTER,
	SEPARATOR,
	DIRECT_LABEL,
	DIRECT,
	STRING,
	COMMAND,
	END_LINE,
	END_FILE
}				t_type;

static char	*g_typearr[] = {
	"LABEL",
	"INSTRUCTION",
	"COMMAND_NAME",
	"COMMAND_COMMENT",
	"INDIRECT",
	"REGISTER",
	"SEPARATOR",
	"DIRECT_LABEL",
	"DIRECT",
	"STRING",
	"COMMAND",
	"END_LINE",
	"END_FILE"
};

# define TSTR(T) (g_typearr[T])

typedef struct	s_token
{
	char			content[COMMENT_LENGTH];
	t_type			type;
	int				row;
	int				column;
}				t_token;

typedef struct	s_parse
{
	char		name[PROG_NAME_LENGTH];
	char		comment[COMMENT_LENGTH];
	int			fd;
	int			row;
	int			column;
	t_queue		*tokens;
}				t_parse;

# define GET_TF(ts, f, HT) (HT(t_token, ts)->f)
# define GET_PTOKENS(p, f, HT) (GET_TF(p->tokens, f, HT))

int				isrighttype(char *name);
char			*new_filename(char *file, char *type);

void			add_token(t_parse *parser, t_type type);

int				parse(t_parse *parser);
void			pr_skip_space(t_parse *parser, char *line);
void			pr_skip_comment(t_parse *parser, char *line);
void			pr_gettoken(t_parse *parser, char *line);
void			string_parse(t_parse *parser, char *line);
void			lable_parse(t_parse *parser, char *line);
void			number_parse(t_parse *parser, char *line);
void			register_parse(t_parse *parser, char *line);
int				register_len(t_parse *parser, char *line);
void			other_parse(t_parse *parser, char *line);

void			error(int row, int column, char *err);
#endif
