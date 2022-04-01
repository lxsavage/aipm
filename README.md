# aipm
A basic package manager written to install/remove AppImages to be launched from the command line.

## Installation

###### NOTE: This tool is incomplete, and may face stability issues

In order to build this program, the following is required to be installed:

- make
- gcc
- sudo (for you Arch users)

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
2. Find the AppImages that were installed in `~/Documents/AIPM_Images`

## How it works

The manager creates a folder that is added to the path as ~/.local/aipm/bin, where each app image will be moved to. From here (due to it being a part of PATH) these AppImages can be executed as any other executable. 
