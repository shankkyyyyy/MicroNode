#ifndef METHOD_H
#define METHOD_H
    // includes nesscery for this module
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

#endif

typedef struct {
    char **users;

} DB;

char *MethodGet(char *request)
{
    char *method = strtok(request," ");
    char *path = strtok(NULL, " ");
    char *http_version = strtok(NULL, " ");

    if (strcmp(method,"GET") == 0)
    {
        printf("METHOD GET\nFOUND\n\n");
        char *data = strtok(path,"/");
        while (data != NULL)
        {
            printf("%s\n", data);
            data = strtok(NULL, "/");
        }
        return NULL;
    }
    else if (strcmp(method,"POST") == 0)
    {
        printf("METHOD POST\nFOUND");
        return NULL;
    }
}

int main()
{
    char request[] = "GET /users/nihal";
    size_t len = strlen("GET /users/nihal ");
    printf("Len: %zu\n", len);
    MethodGet(request);
    return 0;
}
