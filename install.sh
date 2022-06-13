#!/bin/sh

# To use this script, cd into the directory that this file is contained in,
# then run this file with `./install.sh`.

if command -v aipm; then
    sh upgrade.sh
    exit 1
fi

NEWPATH='export PATH="$PATH:$HOME/.local/aipm/bin"'
echo "Installing aipm to $HOME/.local/aipm/aipm; symlinking to /usr/bin/aipm"

if [ ! -d src ]; then
    echo "Make sure that you are cd'd into the aipm directory"
    exit 1
fi

# Create required directories
if [ ! -d $HOME/.local ]; then mkdir $HOME/.local; fi
if [ ! -d $HOME/.local/aipm ]; then mkdir $HOME/.local/aipm; fi
if [ ! -d $HOME/.local/aipm/bin ]; then mkdir $HOME/.local/aipm/bin; fi

# Install updater
cp ./updater.sh $HOME/.local/aipm/updater.sh
cp ./version $HOME/.local/aipm/version

# Compile executable
make
cp ./bin/aipm $HOME/.local/aipm/aipm

# Symlink
sudo ln -s $HOME/.local/aipm/aipm /usr/bin/aipm

# Install manpage
if [ ! -d /usr/local/share/man/man1 ]; then
    sudo mkdir /usr/local/share/man/man1
fi

sudo cp doc/aipm.manpage /usr/local/share/man/man1/aipm.1
sudo gzip /usr/local/share/man/man1/aipm.1
sudo mandb

# Add $HOME/.local/aipm/bin to PATH
echo $NEWPATH >> $HOME/.bashrc
echo $NEWPATH >> $HOME/.zshrc

echo "Done! Invoke with aipm."
