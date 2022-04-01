/**
 * @file main.c
 * @author Logan Savage
 * @brief AIPM is a basic portable package manager for installing, updating,
 * and removing AppImages in a way that behaves like any other package manager.
 * @version 0.3.0
 * @date 2022-03-31
 *
 * @copyright Copyright (c) 2022 Logan Savage. Some Rights Reserved. See
 * LICENSE.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "constants.h"
#include "fshelpers.h"
#include "manager.h"
#include "messages.h"

struct aipm_flags flags;
char *path, *alias;

void printHelpMsg()
{
    printf(MSG_SPLASH);
    printf("\ninstall <1> <2>\tInstall AppImage at path <1>, set its alias to "
           "<2>\n");
    printf("remove <1>\tRemove AppImage installation with alias of <2>\n");
    printf("update <1> <2>\tUpdate alias <2> with a new AppImage file (for "
           "updating)\n");
    printf("\nhelp\t\tDisplay this help message\n");
}

int modify()
{
    unsigned result = EXIT_FAILURE;
    if (alias != NULL && (flags.remove || path != NULL))
    {
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
    }
    else
    {
        printf(MSG_ERRD_NULLARG);
    }
    return result;
}

int main(int argc, char** argv)
{
    unsigned result = EXIT_FAILURE;

    if (argc >= 2)
    {
        // Process arguments
        char* mode = argv[1];

        if (strcmp(mode, "list") == 0)
        {
            char* hd = aipm_fs_homedir();
            char* command =
                malloc((strlen(INSTALLPATH) + strlen(hd) + 4) * sizeof(char));
            strcpy(command, "ls ");
            strcat(command, hd);
            strcat(command, INSTALLPATH);
            system(command);
            free(command);
            result = EXIT_SUCCESS;
        }
        else if (argc >= 3)
        {
            flags.update = strcmp(mode, "upgrade") == 0;
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
        else
        {
            printHelpMsg();
        }
    }
    else
    {
        printHelpMsg();
    }

    return result;
}
