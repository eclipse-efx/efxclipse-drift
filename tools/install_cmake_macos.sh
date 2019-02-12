#!/bin/bash

CMAKE=cmake-3.13.0-Darwin-x86_64
CMAKE_DIR=${TRAVIS_BUILD_DIR}/cmake.portable
CMAKE_PATH=${CMAKE_DIR}/CMake.app/Contents/bin

mkdir .setup && cd .setup
wget --no-check-certificate -nv -t10 https://cmake.org/files/v3.13/${CMAKE}.tar.gz
tar -xvf ${CMAKE}.tar.gz > /dev/null 2> /dev/null
mv ${CMAKE} ${CMAKE_DIR}
cd ..
rm -rf .setup

export PATH=${CMAKE_PATH}:${PATH}

echo "Installed CMake in ${CMAKE_DIR}"
cmake -version

cd ${TRAVIS_BUILD_DIR}
