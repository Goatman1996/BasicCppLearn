#!/bin/bash

if [ ! -d "build" ]; then
  mkdir build
fi

cd ./build
cmake ..
make 

echo ========================
echo "Build Done!"
echo ========================

cd ..
cd ./bin
./$1