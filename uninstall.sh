#!/bin/sh
mv ~/.local/aipm/bin ~/Documents/AIPM_Images
rm -rf ~/.local/aipm
rm ~/.aipm_aliases.sh

echo "Uninstallation complete!"
echo "One last step: make sure to remove the 'alias aipm' and 'source ~/.aipm_aliases.sh' lines in your .zshrc and .bashrc files."
echo "All of the installed AppImages were placed in the folder ~/Documents/AIPM_Images."
