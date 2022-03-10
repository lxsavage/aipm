/**
 * @file manager.c
 * @author Logan Savage
 * @brief Implementation for manager.h
 * @version 0.1
 * @date 2022-03-08
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

int aipm_install(char* path, char* alias)
{
    char* hd = aipm_fs_homedir();

    char* destination = malloc(
        (strlen(hd) + strlen(INSTALLPATH) + strlen(alias) + 1) * sizeof(char));
    strcpy(destination, hd);
    strcat(destination, INSTALLPATH);
    strcat(destination, alias);

    aipm_fs_cp(path, destination);
    aipm_fs_alias(alias, destination);

    free(destination);
    return EXIT_SUCCESS;
}

int aipm_update(char* path, char* alias)
{
    char* hd = aipm_fs_homedir();

    char* destination = malloc(
        (strlen(hd) + strlen(INSTALLPATH) + strlen(alias) + 1) * sizeof(char));
    strcpy(destination, hd);
    strcat(destination, INSTALLPATH);
    strcat(destination, alias);

    aipm_fs_rm(alias);
    aipm_fs_cp(path, destination);

    free(destination);
    return EXIT_SUCCESS;
}

int aipm_remove(char* alias)
{
    aipm_fs_unalias(alias);
    aipm_fs_rm(alias);

    return EXIT_SUCCESS;
}
