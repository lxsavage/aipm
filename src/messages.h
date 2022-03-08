/**
 * @file messages.h
 * @author Logan Savage
 * @brief A basic header storing all user-displayed messages, included for potential
 * localization in the future.
 * @version 0.1
 * @date 2022-03-08
 * 
 * @copyright Copyright (c) 2022 Logan Savage. Some Rights Reserved. See LICENSE.
 * 
 */
#ifndef MESSAGES_H_INCLUDED
#define MESSAGES_H_INCLUDED

#define MSG_SPLASH "AIPM: AppImage Package Manager\nCreated by Logan Savage\n"

#define MSG_UPDATEPROMPT "Enter the alias of the package you are trying to update\n"
#define MSG_INSTALLPROMPT "Enter the alias for the package you are trying to install\n"
#define MSG_REMOVEPROMPT "Enter the alias of the package you are trying to remove\n"

#define MSG_ERR_NEARGS "ERROR: Not enough arguments provided. See documentation for details.\n"
#define MSG_ERRD_NULLARG "ERROR[Dev]: NULL Arguments passed to install or remove. This is a bug, and should be reported.\n"

#endif
