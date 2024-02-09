#include <bits/stdc++.h>
using namespace std;
map<string, bool> memo = {};
int i = 0;

bool canConstruct(string target, vector<string> wordBank)
{
    // cout << target << endl;
    if (memo.find(target) != memo.end())
        return memo[target];
    if (target == "")
    {
        return true;
    }

    for (auto word : wordBank)
    {
        if (target.find(word) == 0)
        {
            string suffix = target;
            suffix.erase(0, word.size());
            if (canConstruct(suffix, wordBank) == true)
            {
                memo[target] = true;
                return memo[target];
            }
        }
    }
    memo[target] = false;
    return memo[target];
}

// bool canConstruct(string target, vector<string> wordBank)
// {
//     // cout << target << endl;
//     if (target == "")
//         return true;

//     for (auto word : wordBank)
//     {
//         if (target.find(word) == 0)
//         {
//             string target = target;
//             suffix.erase(0, word.size());
//             if (canConstruct(target, wordBank) == true)
//             {
//                 return true;
//             }
//         }
//     }
//     return false;
// }

int main()
{
    // cout << canConstruct("abcdef", {"ab", "abc", "cd", "def", "abcd"}) << endl;
    // memo.clear();
    // cout << canConstruct("skateborad", {"bo", "rd", "ate", "t", "ska", "sk", "boar"}) << endl;
    // memo.clear();
    // cout << canConstruct("enterapotentpot", {"a", "p", "ent", "enter", "ot", "o", "t"}) << endl;
    // memo.clear();
    // cout << canConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef",
    //                      {"e", "ee", "eee", "eeee", "eeeee", "eeeeee"})
    //      << endl;
    //memo.clear();

    cout << i << endl;

    for (auto e : memo)
        cout << e.first << "\t" << e.second << endl;
}