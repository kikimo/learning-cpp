#!/bin/bash

# export LD_LIBRARY_PATH=/opt/vesoft/toolset/gcc/7.5.0/lib64/:/opt/vesoft/toolset/gcc/7.5.0/lib:./nebula/build/third-party/install/lib64
/opt/vesoft/toolset/gcc/7.5.0/bin/g++ eg.cc \
    -static-libstdc++ \
    -L./nebula/build/third-party/install/lib64 \
    -L/opt/vesoft/toolset/gcc/7.5.0/lib64/ \
    -L./nebula/build/third-party/install/lib \
    -I./nebula/build/third-party/install/include  \
    -lfolly \
    -lfmt \
    -ldouble-conversion \
    -lssl \
    -lcrypto \
    -lboost_regex \
    -ldl \
    -lboost_context \
    -lboost_thread \
    -lboost_system \
    -lgflags \
    -lglog \
    -lunwind \
    -lpthread \
    -levent -levent_core \
    -g
# /opt/vesoft/toolset/gcc/7.5.0/lib64/libstdc++.a \
#    ./nebula/build/third-party/install/lib/*.a \
#    ./nebula/build/third-party/install/lib64/*.a  \
