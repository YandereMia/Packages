#!/bin/bash
# install.sh for fastfetch

PACKAGE_NAME="fastfetch"
HOME_DIR="$HOME"
PACKAGE_DIR="$HOME_DIR/.myshellos/packages/$PACKAGE_NAME"

# Create the target package directory
mkdir -p "$PACKAGE_DIR"

# Copy the package contents
cp -r bin "$PACKAGE_DIR/"
cp -r src "$PACKAGE_DIR/"
cp pkginfo.json "$PACKAGE_DIR/"

# Make sure the binary is executable
chmod +x "$PACKAGE_DIR/bin/main"

echo "Package '$PACKAGE_NAME' installed successfully!"
echo "You can now run it with: $PACKAGE_NAME"
