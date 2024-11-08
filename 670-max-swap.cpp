#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>

using namespace std;

int maximumSwap(int num) {
    string s = to_string(num);
    int i;
    int to_insert = -1;
    for (i = 1; i < s.size(); i++){
        if (s[i - 1] < s[i]q) break;
        else if (s[i - 1] == s[i] && i >=1 && s[i - 2] != s[i - 1]) to_insert = i - 1;
    }      
    if (i == s.size()) return num;

    
    else{
        string new_num = s.substr(0, to_insert - 1);
        int max_index = to_insert;
        char max = s[to_insert];
        for (int j = to_insert; j < s.size(); j++){
            if (max < s[j]){
                max = s[j];
                max_index = j;
            }
        }
        new_num.insert(new_num.end(), max);

        cout << s[to_insert - 1] << endl;
        for (int j = to_insert; j < s.size(); j++){
            if (j == max_index) new_num.insert(new_num.end(), s[to_insert - 1]);
            else new_num.insert(new_num.end(), s[j]);
        }

        return stoi(new_num);

    }

}

int main(){
    cout << maximumSwap(2736);
}
