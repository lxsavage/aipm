/**
 * @file fshelpers.h
 * @author Logan Savage
 * @brief Various helpers for filesystem actions, to be used within manager.
 * @version 0.1
 * @date 2022-03-08
 *
 * @copyright Copyright (c) 2022 Logan Savage. Some Rights Reserved. See
 * LICENSE.
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

/**
 * @brief Copy the file from src to dest
 *
 * @param src The source file
 * @param dest The destination, with the new name of the file
 * @return int The success result
 */
int aipm_fs_cp(char* src, char* dest);

/**
 * @brief Remove the AppImage with the specified alias
 *
 * @param alias The alias of the AppImage to remove
 * @return int The success result
 */
int aipm_fs_rm(char* alias);

/**
 * @brief Create an alias to a newly-installed AppImage
 *
 * @param alias The alias to assign
 * @param execPath The path to the installed AppImage
 * @return int The success result
 */
int aipm_fs_alias(char* alias, char* execPath);

/**
 * @brief Remove the specified alias from a recently-deleted AppImage
 *
 * @param alias The alias to remove
 * @return int The success result
 */
int aipm_fs_unalias(char* alias);

#endif
