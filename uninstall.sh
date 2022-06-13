#!/bin/sh

# To use this script, cd into the directory that this file is contained in,
# then run this file with `sh ./uninstall.sh`.

if [ ! -d src ]; then
    echo "Make sure that you are cd'd into the aipm directory"
    exit
fi

# Remove symlink
sudo rm -rf /usr/bin/aipm

# Remove image directory, store recovered images in Documents
mv $HOME/.local/aipm/bin $HOME/Documents/AIPM_Images

# Remove manpage
sudo rm -rf /usr/local/share/man/man1/aipm.*
sudo mandb

# Remove installation
rm -rf $HOME/.local/aipm

# Success message
echo "Uninstallation complete!"
echo "Final step: Remove export PATH lines for ~/.local/aipm/bin from your .zshrc and .bashrc files."
echo "All of the installed AppImages were placed in the folder ~/Documents/AIPM_Images."
