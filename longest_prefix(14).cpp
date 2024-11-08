#include <iostream>
#include <string>
#include <vector>

using namespace std;
// namespace std;

#define SIZE 26
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

struct TreiNode
{
    TreiNode *chars[SIZE];
    bool wordend;
    TreiNode()
    {

        for (int i = 0; i < SIZE; i++)
        {
            chars[i] = nullptr;
        }
        wordend = false;
    }
};

struct Trei
{
    TreiNode *root;
    int num_words;
    Trei()
    {
        root = new TreiNode;
        num_words = 0;
    }
    void insert(string s)
    {
        bool present = true;
        TreiNode *temp = root;

        for (int i = 0; i < s.size(); i++)
        {
            if (present && temp->chars[CHAR_TO_INDEX(s[i])] == nullptr)
            {
                present = false;
            }
            if (not(present))
            {
                TreiNode *node = new TreiNode;
                temp->chars[CHAR_TO_INDEX(s[i])] = node;
                temp = node;
            }
            else
            {
                temp = temp = temp->chars[CHAR_TO_INDEX(s[i])];
            }
        }
        temp->wordend = true;
    };
    bool search(string s)
    {
        TreiNode *node = root;
        for (int i = 0; i < s.size(); i++)
        {
            if (node->chars[CHAR_TO_INDEX(s[i])] == nullptr)
                return false;
        }
        return true;
    };
};

string longestCommonPrefix_withtrei(vector<string> &strs)
{
    Trei t;
    string s;
    char c = 0;
    for (int i = 0; i < strs.size(); i++)
    {
        t.insert(strs[i]);
        t.num_words++;
    }

    bool found = false;
    TreiNode *node = t.root;
    while (not(found))
    {
        int num_found = 0;
        TreiNode *child;
        for (int i = 0; i < SIZE; i++)
        {

            if (node->chars[i] != nullptr)
            {
                child = node->chars[i];
                num_found++;
                if (num_found > 1)
                {
                    found = true;
                    break;
                }
                c = char(i + 97);
            }
        }
        if (num_found == 1)
            s += c;
        node = child;
    }
    return s;
}
string longestCommonPrefix(vector<string> &strs)
{
    string s;
    int min = strs[0].size();
    unsigned int i;
    bool found = false;

    for (unsigned int i = 0; i < strs.size(); i++)
    {
        if (min > strs[i].size())
            min = strs[i].size();
    }

    for (int j = 0; j < min; j++)
    {
        char c = strs[0][j];
        for (i = 0; i < strs.size(); i++)
        {
            if (c != strs[i][j])
            {
                found = true;
                break;
            }
        }
        if (not(found)) s += c;
        else return s;
        
    }
    return s;
}


int main()
{
    vector<string> s;
    s.push_back("flower");
    s.push_back("flow");
    s.push_back("flight");
    cout << longestCommonPrefix(s);
}