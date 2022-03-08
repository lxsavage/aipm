/**
 * @file main.c
 * @author Logan Savage
 * @brief AIPM is a basic portable package manager for installing, updating,
 * and removing AppImages in a way that behaves like any other package manager.
 * @version 0.1
 * @date 2022-03-08
 * 
 * @copyright Copyright (c) 2022 Logan Savage. Some Rights Reserved. See LICENSE.
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "manager.h"
#include "messages.h"

struct aipm_flags flags;
char* path, *alias;

// TODO - Clean up
int modify()
{
    if (path == NULL || alias == NULL)
    {
        printf(MSG_ERRD_NULLARG);
        return EXIT_FAILURE;
    }

    if (flags.remove)
    {
        return aipm_remove(alias);
    }
    aipm_install(path, alias);
    system("sh ~/.aipm_aliases.sh");
    return EXIT_SUCCESS;
}

int main(int argc, char** argv)
{
    printf(MSG_SPLASH);

    if (argc < 3)
    {
        printf(MSG_ERR_NEARGS);
        return EXIT_FAILURE;
    }

    // Process arguments
    char* mode = argv[1];

    flags.update = strcmp(mode, "update") == 0;
    flags.remove = strcmp(mode, "remove") == 0;

    if (!flags.remove && argc < 4)
    {
        printf(MSG_ERR_NEARGS);
        return EXIT_FAILURE;
    }

    path = argv[2];
    alias = argv[3];

    return modify();
}
