#!/bin/bash

export LD_LIBRARY_PATH="./build/install/lib:$LD_LIBRARY_PATH"

./build/install/bin/main "./cfg/config.json"
