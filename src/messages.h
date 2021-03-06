/**
 * @file messages.h
 * @author Logan Savage
 * @brief A basic header storing all user-displayed messages, included for
 * potential localization in the future.
 *
 */
#ifndef MESSAGES_H_INCLUDED
#define MESSAGES_H_INCLUDED

#define MSG_SPLASH                                                             \
    "AIPM: AppImage Package Manager v0.4.1\nCreated by Logan Savage\n"

#define MSG_INSTALL "Installing AppImage..."
#define MSG_UPDATE "Updating AppImage..."
#define MSG_REMOVE "Removing AppImage..."

#define MSG_ERR_PERMNOREAD                                                     \
    "ERROR: Read permissions required to install AppImage.\n"

#define MSG_SUCCESS "Success!\n"

#define MSG_ERR_NEARGS                                                         \
    "ERROR: Not enough arguments provided. See documentation for details.\n"
#define MSG_ERRD_NULLARG                                                       \
    "ERROR[Dev]: NULL Arguments passed to install or remove. This is a bug, "  \
    "and should be reported.\n"
#define MSG_ERR_FAILMALLOC                                                     \
    "ERROR: Failed to allocate memory. Try closing some programs and running " \
    "again.\n"

#define MSG_ERR_INVALIDCALL                                                    \
    "ERROR: Invalid call. See documentation for available calls.\n"

#endif
