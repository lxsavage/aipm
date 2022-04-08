/**
 * @file manager.h
 * @author Logan Savage
 * @brief The main manager portion of the program.
 *
 * @copyright Copyright (c) 2022 Logan Savage. Some Rights Reserved. See
 * LICENSE.
 *
 */
#ifndef MANAGER_H_INCLUDED
#define MANAGER_H_INCLUDED

/**
 * @brief A set of flags for the program, stored as a bitfield.
 *
 * If remove is set to 1, uninstall.
 *
 * If remove is set to 0, install set to 1, install.
 *
 * If remove is set to 0, update set to 1, update.
 *
 */
struct aipm_flags
{
    unsigned update  : 1;
    unsigned install : 1;
    unsigned remove  : 1;
    unsigned list    : 1;
    unsigned version : 1;
};

/**
 * @brief Install an AppImage.
 *
 * @param path The path to the AppImage to install
 * @param alias The alias to set to the AppImage when installed
 * @return int The success result
 */
int aipm_install(char* path, char* alias);

/**
 * @brief Update an AppImage.
 *
 * @param path The path to the AppImage of the update
 * @param alias The alias to update
 * @return int The success result
 */
int aipm_update(char* path, char* alias);

/**
 * @brief Remove and unalias an AppImage.
 *
 * @param alias The alias of the installed AppImage to remove
 * @return int The success result
 */
int aipm_remove(char* alias);

#endif
