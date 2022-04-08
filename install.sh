#!/bin/sh

# 
# install.sh
#
# To use this script, cd into the directory that this file is contained in,
# then run this file with `sh ./install.sh`.
#
# Author: Logan Savage
# Copyright (c) 2022 Logan Savage. Some Rights Reserved. See LICENSE.
#

if command -v aipm; then
    sh update.sh
    exit 1
fi

NEWPATH='export PATH="$PATH:$HOME/.local/aipm/bin"'
echo "Installing aipm to ~/.local/aipm/aipm; symlinking to /usr/bin/aipm"

if [ ! -d src ]; then
    echo "Make sure that you are cd'd into the aipm directory"
    exit 1
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

# Install manpage
if [ ! -d /usr/local/share/man/man1 ]; then
    sudo mkdir /usr/local/share/man/man1
fi

sudo cp doc/aipm.1 /usr/local/share/man/man1/aipm.1
sudo gzip /usr/local/share/man/man1/aipm.1
sudo mandb

# Add ~/.local/aipm/bin to PATH
echo $NEWPATH >> ~/.bashrc
echo $NEWPATH >> ~/.zshrc

echo "Done! Invoke with aipm."
