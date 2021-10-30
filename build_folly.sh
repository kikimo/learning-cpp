#!/bin/bash

LIB=/root/src/nebula/build/third-party/install/lib
INCLUDE=/root/src/nebula/build/third-party/install/include
g++ folly.cpp -std=c++14  -L$LIB -I$INCLUDE  -lfolly -lpthread -levent -levent_core -lglog -ldouble-conversion -lfmt -lssl -lcrypto -ldl -lgflags -lboost_context -lunwind -lz -o hello
