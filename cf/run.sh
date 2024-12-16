#!/bin/bash
rm $1.o 2> /dev/null
touch $1
file=$(find -type f -name $1)



if [ "$2" = "w" ]; then
  echo "#include <bits/stdc++.h>
  #include <vector>
  #include <string>
using ll=long long;
using vector<int>=vi;
using vector<string>=vs;
using namespace std;

int main(){
    int num_testcases;
    cin >> num_testcases;
    vector<string> results;
    for (int _ = 0; _ < num_testcases; _++)
    {
    }
    for (int i = 0; i < results.size(); i++){
        cout << results[i] << endl;
    }
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


