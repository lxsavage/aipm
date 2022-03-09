#!/bin/sh
echo "Updating..."
cd $(dirname "${BASH_SOURCE[0]}")

make
rm ~/local/aipm/aipm
cp ./bin/aipm ~/.local/aipm/aipm

echo "Done!"
