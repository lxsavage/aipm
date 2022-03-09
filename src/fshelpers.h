/**
 * @file fshelpers.h
 * @author Logan Savage
 * @brief Various helpers for filesystem actions, to be used within manager.
 * @version 0.1
 * @date 2022-03-08
 * 
 * @copyright Copyright (c) 2022 Logan Savage. Some Rights Reserved. See LICENSE.
 * 
 */
#ifndef FSHELPERS_H_INCLUDED
#define FSHELPERS_H_INCLUDED

/**
 * @brief Gets the current user's home directory
 * 
 * @return char* The full path to the home directory of the current user;
 * ends with a /
 */
char* aipm_fs_homedir();

int aipm_fs_cp(char* src, char* dest);

int aipm_fs_rm(char* alias);

int aipm_fs_alias(char* alias, char* execPath);

int aipm_fs_unalias(char* alias);

#endif
