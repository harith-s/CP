#!/bin/bash
rm $1.o 2> /dev/null
touch $1
file=$(find -type f -name $1)



if [ "$2" = "w" ]; then
  echo "#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <climits>
using namespace std;

int main(){
    return 0;
}" > $file
fi

if [ "$2" = "c" ]; then
    g++ $file -g -o $1.o
    ./$1.o
fi

if [ "$2" = "d" ]; then
    g++ $file -g -o $1.o
    gdb $1.o
fi


