#!/bin/sh

# To use this script, cd into the directory this file is contained
# in, then run it through `./upgrade.sh`.

if ! command -v aipm; then
    sh install.sh
    exit 1
fi

if [ ! -d src ]; then
    echo "Make sure that you are cd'd into the aipm directory"
    exit
fi

echo "Updating..."
cp ./version $HOME/.local/aipm/version

make
mv -f ./bin/aipm $HOME/.local/aipm/aipm
echo "Done!"
