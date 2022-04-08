# aipm
A basic package manager written to install/remove AppImages. These images are installed with a name which can be accessed from the command line.

## Installation

In order to build this program, the following is required to be installed:

- make
- gcc

1. Clone repo, extract zip
2. `cd` into the root of the repo.
3. Run `sh ./install.sh`

## Updating

1. Clone new version repo
2. cd into the root of the new repo.
3. Run `sh ./update.sh`

## Uninstallation

1. Repeat similar steps to installation, except run `sh ./uninstall.sh`
2. Remove the `~/.local/aipm/bin` folder from `PATH` (should be explicit lines in `.zshrc` and `.bashrc` that can be removed for this that are added with the installer)
3. Find the AppImages that were installed in `~/Documents/AIPM_Images`

## How it works

The manager creates a folder that is added to the path as ~/.local/aipm/bin, where each app image will be moved to. From here (due to it being a part of PATH) these AppImages can be executed as any other executable.
