#!/bin/sh

clang `pkg-config --cflags raylib` -o main main.c `pkg-config --libs raylib`
