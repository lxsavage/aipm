#!/bin/sh

#
# uninstall.sh
#
# To use this script, cd into the directory that this file is contained in,
# then run this file with `sh ./uninstall.sh`.
#
# Author: Logan Savage
# Version 0.2.2
# Date: 2022-03-08
# Copyright (c) 2022 Logan Savage. Some Rights Reserved. See LICENSE.
#

if [ ! -d src ]; then
    echo "Make sure that you are cd'd into the aipm directory"
    exit
fi

# Remove symlink
sudo rm -rf /usr/bin/aipm

# Remove image directory, store recovered images in Documents
cp ~/.local/aipm/bin ~/Documents/AIPM_Images

# Remove manpage
sudo rm -rf /usr/local/share/man/man1/aipm.*
sudo mandb

# Remove installation
rm -rf ~/.local/aipm

# Success message
echo "Uninstallation complete!"
echo "Final step: Remove export PATH lines for ~/.local/aipm/bin from your .zshrc and .bashrc files."
echo "All of the installed AppImages were placed in the folder ~/Documents/AIPM_Images."
