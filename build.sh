#!/bin/sh
cd $(dirname $0);pwd -P
gcc main.c -o main -Wall
sudo ./main
