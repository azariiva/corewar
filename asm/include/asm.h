/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhilary <fhilary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 19:53:09 by blinnea           #+#    #+#             */
/*   Updated: 2020/08/13 20:09:48 by fhilary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACM_H

# define ACM_H

# include "libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include "libft_printf.h"

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

typedef enum	e_type
{
	LABEL,
	INSTRUCTION,
	COMMAND_NAME,
	COMMAND_COMMENT,
	REGISTER,
	SEPARATOR,
	DIRECT_LABEL,
	DIRECT,
	STRING,
	COMMAND,
	LABEL,
	NEW_LINE,
	END
}				t_type;

typedef struct	s_token
{
	t_type			type;
	int				row;
	int				colomn;
}				t_token;

typedef struct	s_parse
{
	char		*name;
	char		*comment;
	int			fd;
	t_token		*tokens;
}				t_parse;

int		isrighttype(char *name);
char	*new_filename(char *file, char *type);

void	as_parse(t_parse *parser);

#endif
