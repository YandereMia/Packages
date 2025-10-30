#!/bin/bash

PACKAGE_NAME="RMQOTS"
HOME_DIR="$HOME"
PACKAGE_DIR="$HOME_DIR/.myshellos/packages/$PACKAGE_NAME"


mkdir -p "$PACKAGE_DIR"
cp -r bin "$PACKAGE_DIR/"
cp -r src "$PACKAGE_DIR/"
cp pkginfo.json "$PACKAGE_DIR/"

chmod +x "$PACKAGE_DIR/bin/main"

echo "Package '$PACKAGE_NAME' installed successfully!"
echo "You can now run it with: $PACKAGE_NAME"

