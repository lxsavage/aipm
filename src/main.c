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
#include "constants.h"
#include "messages.h"
#include "fshelpers.h"

struct aipm_flags flags;
char* path, *alias;

// TODO - Clean up
int modify()
{
    unsigned result = EXIT_FAILURE;
    if (alias == NULL || (!flags.remove && path == NULL))
    {
        printf(MSG_ERRD_NULLARG);
        return EXIT_FAILURE;
    }

    if (flags.remove)
    {
        // Remove
        printf(MSG_REMOVE);
        result = aipm_remove(alias);
        printf(MSG_SUCCESS);
    }
    else if (flags.update)
    {
        // Update
        printf(MSG_UPDATE);
        result = aipm_update(path, alias);
        printf(MSG_SUCCESS);
    }
    else
    {
        // Install
        printf(MSG_INSTALL);
        result = aipm_install(path, alias);
        printf(MSG_SUCCESS);
        printf(MSG_INSTALL_INSTR);
    }
    system("sh ~/.aipm_aliases.sh");
    
    return result;
}

int main(int argc, char** argv)
{
    unsigned result = EXIT_FAILURE;
    printf(MSG_SPLASH);

    if (argc < 3)
    {
        printf(MSG_ERR_NEARGS);
    }
    else
    {
        // Process arguments
        char* mode = argv[1];

        if (strcmp(mode, "list") == 0)
        {
            char* hd = aipm_fs_homedir();
            char* command = malloc((strlen(ALIASFILE) + strlen(hd) + 1) * sizeof(char));
            strcpy(command, "ls ");
            strcat(command, hd);
            strcat(command, ALIASFILE);
            system(command);
            free(command);
            result = EXIT_SUCCESS;
        }
        else
        {
            flags.update = strcmp(mode, "update") == 0;
            flags.remove = strcmp(mode, "remove") == 0;

            if (flags.update || flags.remove || strcmp(mode, "install") == 0)
            {
                if (!flags.remove && argc < 4)
                {
                    printf(MSG_ERR_NEARGS);
                }

                if (flags.remove)
                {
                    alias = argv[2];
                }
                else
                {
                    path = argv[2];
                    alias = argv[3];
                }
                
                result = modify();
            }
            else
            {
                printf(MSG_ERR_INVALIDCALL);
            }
        }
    }

    return result;
}
