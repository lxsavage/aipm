/**
 * @file fshelpers.c
 * @author Logan Savage
 * @brief Implementation for fshelpers.h
 *
 * @copyright Copyright (c) 2022 Logan Savage. Some Rights Reserved. See
 * LICENSE.
 *
 */
#define _POSIX_C_SOURCE 200809L

#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

#include "constants.h"
#include "fshelpers.h"
#include "messages.h"

char* aipm_fs_homedir()
{
    struct passwd* pw = getpwuid(getuid());
    char* homedir = pw->pw_dir;

    return homedir;
}

int aipm_fs_cp(char* src, char* dest)
{
    FILE* srcf = fopen(src, "rb");
    if (srcf == NULL)
    {
        printf(MSG_ERR_PERMNOREAD);
        return EXIT_FAILURE;
    }
    FILE* destf = fopen(dest, "wb");

    int curr = fgetc(srcf);
    while (curr != EOF)
    {
        fputc(curr, destf);
        curr = fgetc(srcf);
    }

    fclose(srcf);
    fclose(destf);
    chmod(dest, S_IRUSR | S_IXUSR);
    return EXIT_SUCCESS;
}

int aipm_fs_rm(char* alias)
{
    char* hd = aipm_fs_homedir();
    char* path = malloc((strlen(alias) + strlen(hd) + strlen(INSTALLPATH) + 1) *
                        sizeof(char));
    strcpy(path, hd);
    strcat(path, INSTALLPATH);
    strcat(path, alias);

    remove(path);
    free(path);

    return EXIT_SUCCESS;
}
