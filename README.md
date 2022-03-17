# aipm
A basic package manager written to install/remove AppImages to be launched from the command line.

## Installation

###### NOTE: This tool is incomplete, and may face stability issues

1. Clone repo, extract zip
2. `cd` into the root of the repo.
3. Run `sh ./install.sh`
   - Note that if aipm is installed already, running this will add duplicate source entries to your `.bashrc` and `.zshrc` files, and attempt to reinitialize your `.aipm_aliases.sh` file.

## Updating

1. Clone new version repo
2. cd into the root of the new repo.
3. Run `sh ./update.sh`
   - Note that this script will mess up if aipm isn't already installed

## Uninstallation

1. Repeat similar steps to installation, except run `sh ./uninstall.sh`
2. Remove `source ~/.aipm_aliases.sh` from both your .zshrc and bashrc files
3. Find the AppImages that were installed in `~/Documents/AIPM_Images`

## How it works

The manager works based primarily upon aliases (which means it requires these to be existent on the shell that it is installed on), where it will install by moving AppImages into its own bin folder (`~/.local/aipm/bin`), then creating an alias in a shell file (`~/.aipm_aliases.sh`). The installation process currently sources this file in both the current user's `.zshrc` and `.bashrc` files, but won't be removed with the uninstallation script, so these lines must be removed manually in this case.
