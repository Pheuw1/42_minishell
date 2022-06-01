#include "libft.h"

int ft_strarrsize(char **strings)
{  
    int i;

<<<<<<< HEAD
    if (!strings)
        return (0);
    i = 0;
    while(strings && strings[i])
=======
    i = 0;
    while(strings[i])
>>>>>>> 505d58a9ab97bf70864f107bd619556ef73927c5
        i++;
    return (i);
}