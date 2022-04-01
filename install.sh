#!/bin/sh

#
# install.sh
#
# To use this script, ensure that no instance of aipm is installed, and if
# there was one installed in the past, make sure all traces of it have been
# removed. After this, cd into the directory that this file is contained in,
# then run this file with `sh ./install.sh`.
#
# Author: Logan Savage
# Version 0.2.2
# Date: 2022-03-08
# Copyright (c) 2022 Logan Savage. Some Rights Reserved. See LICENSE.
#
NEWPATH='export PATH="$PATH:$HOME/.local/aipm/bin"'
echo "Installing aipm to ~/.local/aipm/aipm; symlinking to /usr/bin/aipm"

if [ ! -d src ]; then
    echo "Make sure that you are cd'd into the aipm directory"
    exit
fi

# Create required directories
if [ ! -d ~/.local ]; then mkdir ~/.local; fi
if [ ! -d ~/.local/aipm ]; then mkdir ~/.local/aipm; fi
if [ ! -d ~/.local/aipm/bin ]; then mkdir ~/.local/aipm/bin; fi

# Compile executable
make
cp ./bin/aipm ~/.local/aipm/aipm

# Symlink
sudo ln -s ~/.local/aipm/aipm /usr/bin/aipm

# Add ~/.local/aipm/bin to PATH
echo $NEWPATH >> ~/.bashrc
echo $NEWPATH >> ~/.zshrc

echo "Done! Invoke with aipm"
