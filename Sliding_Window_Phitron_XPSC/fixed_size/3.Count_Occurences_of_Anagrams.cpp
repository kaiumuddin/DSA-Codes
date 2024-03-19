#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int search(string pat, string txt) {
        int l = 0;
        int r = 0;
        int n = txt.size();
        int k = pat.size();
        unordered_map<char, int> mp;
        unordered_map<char, int> pmp;

        for (char c : pat) {
            pmp[c]++;
        }

        int ans = 0;

        while (r < n) {
            mp[txt[r]]++;

            if (r >= k - 1) {
                bool tmp = true;

                for (auto it = pmp.begin(); it != pmp.end(); it++) {
                    if (mp[it->first] != it->second) {
                        tmp = false;
                        break;
                    }
                }

                if (tmp) ans++;

                mp[txt[l]]--;
                if (mp[txt[l]] == 0) {
                    mp.erase(txt[l]);
                }

                l++;
            }

            r++;
        }

        return ans;
    }

    int search2(string pat, string txt) {
        int l = 0;
        int r = 0;
        
        int n = txt.size();
        int k = pat.size();

        int fr_pat[26] = { 0 };
        int fr_txt[26] = { 0 };

        for (char c : pat) {
            fr_pat[c - 'a']++;
        }

        int ans = 0;

        while (r < n) {
            fr_txt[txt[r] - 'a']++;

            if (r >= k - 1)
            {
                bool tmp = true;

                for (int i = 0; i < 26; i++)
                {
                    if (fr_pat[i] != fr_txt[i])
                    {
                        tmp = false;
                        break;
                    }
                }

                if (tmp) ans++;
                fr_txt[txt[l] - 'a']--;
                l++;
            }

            r++;
        }

        return ans;
    }
};

int main() {
    Solution sol;
    string pattern = "abc";
    string text = "abcdabcabc";
    cout << "Occurrences: " << sol.search(pattern, text) << endl;
    cout << "Occurrences: " << sol.search2(pattern, text) << endl;
    return 0;
}
