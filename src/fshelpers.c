/**
 * @file fshelpers.c
 * @author Logan Savage
 * @brief Implementation for fshelpers.h
 * @version 0.1
 * @date 2022-03-08
 *
 * @copyright Copyright (c) 2022 Logan Savage. Some Rights Reserved. See
 * LICENSE.
 *
 */
#define POSIX_SOURCE

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

int aipm_fs_alias(char* alias, char* execPath)
{
    char* hd = aipm_fs_homedir();
    char* aliases = malloc((strlen(ALIASFILE) + strlen(hd) + 1) * sizeof(char));
    strcpy(aliases, hd);
    strcat(aliases, ALIASFILE);

    // alias <alias>=<execPath>
    char* newAlias =
        malloc((10 + strlen(alias) + strlen(execPath)) * sizeof(char));
    strcpy(newAlias, "\nalias ");
    strcat(newAlias, alias);
    strcat(newAlias, "=");
    strcat(newAlias, execPath);
    strcat(newAlias, "\n");

    // Append the alias to the aliases file
    FILE* aliasf = fopen(aliases, "a");

    fprintf(aliasf, "%s", newAlias);
    free(newAlias);

    fclose(aliasf);
    free(aliases);

    return EXIT_SUCCESS;
}

int aipm_fs_unalias(char* alias)
{
    // Unalias
    char* command = malloc((strlen(alias) + 12) * sizeof(char));
    strcpy(command, "unalias -a ");
    strcat(command, alias);
    system(command);
    free(command);

    // Remove alias from .aipm_aliases.sh
    char* hd = aipm_fs_homedir();
    char* aliases = malloc((strlen(ALIASFILE) + strlen(hd) + 1) * sizeof(char));
    strcpy(aliases, hd);
    strcat(aliases, ALIASFILE);

    char* aliasLine = malloc((strlen(ALIASFILE) + 7) * sizeof(char));
    strcpy(aliasLine, "alias ");
    strcat(aliasLine, alias);
    int aliasLineC = strlen(aliasLine);

    /**
     * In this section, the alias line is removed from the aliases file by
     * writing every line except the alias line in question to a temp file,
     * removing the original aliases file, then renaming the temp file to
     * what the temp file initially was.
     */
    FILE* aliasf;
    FILE* tempf;
    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    aliasf = fopen(aliases, "r");
    tempf = fopen(".aipm.tmp", "w");
    if (aliasf == NULL || tempf == NULL)
    {
        printf(MSG_ERR_FAILMALLOC);
        free(aliasLine);
        free(aliases);
        free(aliasf);
        free(tempf);
        return EXIT_FAILURE;
    }

    // Write every line except for the line in question to the temp file
    while ((read = getline(&line, &len, aliasf)) != EOF)
    {
        if (strncmp(line, aliasLine, aliasLineC) != 0)
        {
            fprintf(tempf, "%s", line);
        }
    }

    // Close the initial file, free associated memory
    fclose(aliasf);

    // Delete the initial file, rename the temp to the initial file
    remove(aliases);
    rename(".aipm.tmp", aliases);

    free(aliasLine);
    free(aliases);

    return EXIT_SUCCESS;
}
