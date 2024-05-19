#ifndef FT_PRINTF_HELPERS_H
# define FT_PRINTF_HELPERS_H

# include "../libft/libft.h"
# include <ctype.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

// typedef struct s_list
// {
//     void *content;
//     struct s_list *next;
// } t_list;

void	ft_putstr(const char *str);
void	ft_free_str(char *str);
char	*ft_strnjoin(char **strs);

#endif
