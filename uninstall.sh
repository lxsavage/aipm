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

mv ~/.local/aipm/bin ~/Documents/AIPM_Images
rm -rf ~/.local/aipm
rm ~/.aipm_aliases.sh

echo "Uninstallation complete!"
echo "One last step: make sure to remove the 'alias aipm' and 'source ~/.aipm_aliases.sh' lines in your .zshrc and .bashrc files."
echo "All of the installed AppImages were placed in the folder ~/Documents/AIPM_Images."
