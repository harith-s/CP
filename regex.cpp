#include <iostream>
#include <string>
using namespace std;

bool isMatch(string s, string p)
{
    string star = "*";
    string dot = ".";
    size_t pos_star = p.find(star);
    size_t pos_dot = p.find(dot);
    if (pos_star == string::npos && pos_dot == string::npos)
    {
        if (p.compare(s) == 0 ) return true;
        return false;
    //     size_t found_pos;
    //     size_t found;
    //     // for (int i = 0; i < p.size(); i++){
    //     while (s.compare("") != 0)
    //     {

    //         found = s.find(p[0]);
    //         string old_s = s;

    //         if (found == string::npos)
    //             return false;
    //         else
    //         {

    //             for (int i = 1; i < p.size(); i++)
    //             {
    //                 if (s[found + i] != p[i])
    //                 {
    //                     s = s.substr(found + 1);
    //                     break;
    //                 }
    //             }
    //             if ((old_s == s) && ()) return true;
    //         }
    //     }
    //     if (s.compare("") == 0) return false;
    //     else return true;

    // //     else s = s.substr(found + 1);
    // //     if (i == 0)
    // //         found_pos = found;
    // //     else if (found != found_pos + 1)
    // //         return false;
    }
    return false;

}

int main()
{
    string s1 = "applelepe";
    string s2 = "lee";
    cout << isMatch(s1, s2);
}