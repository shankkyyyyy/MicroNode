#ifndef INITIAL_H
    #define INITIAL_H

#include "networking.h"

int main()
{
    ServerConfig Config;
    Config.port = 8080;
    int init_result = init_networking((ServerConfig *)&Config);
    if (init_result == EXIT_FAILURE)
        {
            return EXIT_FAILURE;
        }

    while(1)
        {
            int result = handle_client((ServerConfig *)&Config);
            if (result != 0) {return EXIT_FAILURE;}
        }
}
#endif
