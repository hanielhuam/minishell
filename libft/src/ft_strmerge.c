
#include "libft.h"

char    *ft_strmerge(char *s1, char *s2)
{
    char    *result;
    result = ft_strjoin(s1, s2);
    free(s1);
    free(s2);
    if (!result)
        return (NULL);
    return (result);
}