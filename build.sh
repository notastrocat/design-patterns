#!/bin/bash

if [[ $1 == "rebuild" ]]; then
    rm -rf "./build/"
fi

mkdir -p "./build" || exit 1
cd "./build" || exit 1
time cmake .. -DINSTALL_PREFIX="./install" && time cmake --build . && time cmake --install .
