#!/bin/bash
FILE=$1
start=$SECONDS
g++ -std=c++11 $FILE -o main
duration=$(( SECONDS - start ))
echo "finished in "$duration".0 seconds"
./main
