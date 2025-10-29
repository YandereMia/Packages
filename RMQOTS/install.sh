#!/bin/bash

echo "This Script will add RMQOTS to ~/.bashrc"
dir="$PWD"
echo $PWD/main >> ~/.bashrc
source ~/.bashrc
echo "script installed"