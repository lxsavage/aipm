/**
 * @file manager.c
 * @author Logan Savage
 * @brief Implementation for manager.h
 * @version 0.1
 * @date 2022-03-08
 * 
 * @copyright Copyright (c) 2022 Logan Savage. Some Rights Reserved. See LICENSE.
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

#include "manager.h"
#include "constants.h"
#include "messages.h"

/* Helpers */
char* _homedir()
{
    struct passwd* pw = getpwuid(getuid());
    char* homedir = pw->pw_dir;

    return homedir;
}

int _cp(char* src, char* dest)
{
    char* command = malloc((strlen(src) + 10) * sizeof(char));
    strcpy(command, "chmod +x ");
    strcat(command, src);
    system(command);

    command = realloc(command, (6 + strlen(src) + strlen(dest)) * sizeof(char));
    strcpy(command, "cp ");
    strcat(command, src);
    strcat(command, " ");
    strcat(command, dest);
    
    // TODO - Change to use dirent
    system(command);
    
    // CHMOD
    

    free(command);

    return EXIT_SUCCESS;
}

int _rm(char* path)
{
    char* command = malloc((strlen(path) + 8) * sizeof(char));
    strcpy(command, "rm -rf ");
    strcat(command, path);

    // TODO - Change to use dirent
    printf("%s", command);
    //system(command)
    free(command);
    
    return EXIT_SUCCESS;
}

int _alias(char* alias, char* execPath)
{
    char* hd = _homedir();
    char* aliases = malloc((strlen(ALIASFILE) + strlen(hd) + 1) * sizeof(char));
    strcpy(aliases, hd);
    strcat(aliases, ALIASFILE);

    // Command construction
    char* command = malloc((strlen(aliases) + strlen(execPath) +
        strlen(alias) + 17) * sizeof(char));

    strcpy(command, "echo \"alias ");
    strcat(command, alias);
    strcat(command, "=");
    strcat(command, execPath);
    strcat(command, "\">>");
    strcat(command, aliases);
    free(aliases);

    // TODO - Change to use dirent
    //printf("%s\n", command);
    system(command);
    free(command);

    return EXIT_SUCCESS;
}

int _unalias(char* alias)
{
    printf("unalias %s\n", alias);
    printf("Remove %s alias from bash file\n", alias);
    return EXIT_SUCCESS;
}

/* Implementations */
int aipm_install(char* path, char* alias)
{
    char* hd = _homedir();

    char* destination = malloc((strlen(hd) + strlen(INSTALLPATH) +
        strlen(alias) + 1) * sizeof(char));
    strcpy(destination, hd);
    strcat(destination, INSTALLPATH);
    strcat(destination, alias);

    _cp(path, destination);
    _alias(alias, destination);

    free(destination);
    return EXIT_SUCCESS;
}

int aipm_remove(char* alias)
{
    char* hd = _homedir();

    char* path = malloc((strlen(hd) + strlen(INSTALLPATH) +
        strlen(alias) + 1) * sizeof(char));
    strcpy(path, hd);
    strcpy(path, INSTALLPATH);
    strcpy(path, alias);

    _rm(path);
    _unalias(path);

    free(path);
    return EXIT_SUCCESS;
}
