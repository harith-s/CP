#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <bits/stdc++.h>

bool areSentencesSimilar(string sentence1, string sentence2)
{

    if (sentence1.size() > sentence2.size())
    {
        string temp = sentence1;
        sentence1 = sentence2;
        sentence2 = temp;
    }


    stringstream stream1(sentence1);
    stringstream stream2(sentence2);

    string word;
    vector<string> words_sentence1;
    vector<string> words_sentence2;

    while (stream1 >> word)
    {
        words_sentence1.push_back(word);
    }

    while (stream2 >> word)
    {
        words_sentence2.push_back(word);
    }

    int sz1 = words_sentence1.size();
    int sz2 = words_sentence2.size();

    if (sz1 == 1 || sz2 == 1)
    {
        return words_sentence2[0] == words_sentence1[0] || words_sentence1[sz1 - 1] == words_sentence2[sz2 - 1];
    }

    int index_1 = 0;
    int index_2 = 0;
    bool found_mismatch = false;

    while (index_1 < sz1 && index_2 < sz2)
    {
        if (words_sentence1[index_1] != words_sentence2[index_2])
        {
            if (found_mismatch)
            {
                return false;
            }
            else
            {
                found_mismatch = true;
                int t_index_2 = sz2 - 1;
                while (index_2 < t_index_2 && words_sentence1[index_1] != words_sentence2[t_index_2])
                {
                    t_index_2--;
                }
                if (index_2 == t_index_2) return false;
                index_2 = t_index_2;
            }
        }
        index_1++;
        index_2++;
    }

    return index_1 == sz1 && (index_2 == sz2 || found_mismatch == false);
}