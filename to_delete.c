#include "push_swap.h"

int position(a_list *a, int size, int min, int max)
{
    int i;
    int pos;

    i = 1;
    pos = -1;
    while (a)
    {
        if (a->index >= min && a->index <= max)
        {
            pos = i;
            if (pos <= (size / 2))
                return (pos);
        }
        i++;
        a = a->next;
    }
    return (pos);
}