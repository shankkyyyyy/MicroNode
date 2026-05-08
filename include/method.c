#ifndef METHOD_H
#define METHOD_H
    // includes nesscery for this module
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
#endif

char *MethodGet(char *path, char *users[], size_t num_users)
{
    // data = /users/nihal/josh
    char *data = strtok(path, "/");
    if (strcmp(data,"users") == 0)
    {
        data = strtok(NULL,"/");
        if (data == NULL)
            {
                printf("UserName Not specified..\n");
                return NULL;
            }

        while (data != NULL)
        {
            for (int i = 0; i < 5; i++)
                {
                    if (strcmp(data,users[i]) == 0)
                    {
                        printf("[%d--]: %s\n", i, data);
                    }
                }
            data = strtok(NULL, "/");

            printf("[00]: %s\n",data);
        }
        return NULL;
    }
    else
    {
        return NULL;
    }
}

char *Method(char *request,char *users[],size_t num_users)
{
    char *method = strtok(request," ");
    char *path = strtok(NULL, " ");
    // must verify the http version.
    char *http_version = strtok(NULL, " ");

    // cleaning the code
    if (strcmp(method,"GET") == 0)
    {
        return MethodGet(path, users, num_users);
    }
    else if (strcmp(method,"POST") == 0)
    {
        printf("METHOD POST\nFOUND");
        return NULL;
    }
}

int main()
{
    // debug code only !!
   // User.UserNode_s = "users";
    //User.data = "node";
    // User.AllUsers = malloc(2 * (sizeof(char)));
   // User.left = NULL;
    //User.right = NULL;

    char *all_users[] = {"nihal", "josh","john","foo","nihal","hehe"};
    char request[] = "GET /users/nihal/hitty/josh";
    size_t len = strlen("GET /users/nihal ");
    printf("Len: %zu\n", len);
    Method(request,all_users);
    return 0;
}
