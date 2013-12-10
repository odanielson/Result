
#include "Result.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Return a result with handle set to string if a_value is 5
Result findPattern(const char *a_buffer, const char *a_pattern) {
    Result res;

    char *pos = strstr(a_buffer, a_pattern);
    if (pos)
    {
        res.status = OK;
        res.handle = malloc(sizeof(int));
        *(int *)res.handle = (int)(pos-a_buffer);
    }
    else
    {
        res.status = ERROR;
        res.handle = NULL;
    }
    return res;
}

int main(int argc, char **argv) {
    Result res;
    if (argc > 2)
    {
        if ((res = findPattern(argv[1], argv[2])).status == OK)
        {
            printf("Found \"%s\" in \"%s\" at pos %d\n", argv[1], argv[2],
                   *(int *)res.handle);
            free(res.handle);
        }
        else
        {
            printf("Couldn't find \"%s\" in \"%s\"\n", argv[2], argv[1]);
        }
    }
    else
    {
        printf("Usage: %s buffer pattern\n\n"
               "Search for pattern in buffer and print position if found.\n",
               argv[0]);
    }
}
