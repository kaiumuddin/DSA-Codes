#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define yes cout << "Yes" << endl
#define no cout << "No" << endl
#define p(x) cout << x << endl
#define pp(x, y) cout << x << " " << y << endl
#define sp " "
#define nl printf("\n");

void init_code()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
    // freopen("in.txt", "w", stdout);
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
}


void pb(unsigned int n)
{
    // print integer in binary
    for (int i = 31; i >= 0; i--)
    {
        if (n & (1 << i))
            cout << 1;
        else cout << 0;
    }
    cout << " : "; cout << n << endl;
}

void all_subsets()
{
    //subset using bit
    int n; cin >> n;
    int ar[n];

    for (int i = 0; i < n; i++) cin >> ar[i];
    int total = 1 << n;
    pb(total);

    // for (int num = 1; num < total; num++) {
    //     if (__builtin_popcount(num) == 1) {
    //         for (int i = 0; i < n; i++) {
    //             if (num & (1 << i)) {
    //                 cout << ar[i] << " ";
    //             }
    //         }
    //         cout << endl;
    //     }
    // }

    for (int num = 1; num < total; num++) {
        for (int i = 0; i < n; i++) {
            if (num & (1 << i)) {
                cout << ar[i] << " ";
            }
        }
        cout << endl;
    }
}


void pos_to_neg(int n)
{
    // positive to negetive using 2's complement
    pb(n);
    pb(~n);
    pb(~n + 1);
    pb(-5);
}

void is_kth_bit_set(unsigned int n, unsigned int k = 0)
{
    pb(n);
    pb(1 << k - 1);
    pb(n & (1 << k - 1));
}

void set_kth_bit(unsigned int n, unsigned int k = 0)
{
    pb(n);
    pb(1 << k - 1);
    pb(n | (1 << k - 1));
}

void clear_kth_bit(unsigned int n, unsigned int k = 0)
{
    pb(n);
    pb(1 << k - 1);
    pb(~(1 << k - 1));
    pb(n & ~(1 << k - 1));
}

void remove_last_set_bit(unsigned int n, unsigned int k = 0)
{
    pb(n);
    pb(n - 1);
    pb(n & (n - 1));
}

void position_of_last_set_bit(unsigned int n, unsigned int k = 0)
{
    pb(n);
    pb(n - 1);
    pb(~(n - 1));
    pb(n & ~(n - 1));
}

void is_odd_with_and(unsigned int n, unsigned int k = 0)
{
    pb(n);
    pb(1);
    pb(n & 1);
}

void is_even_with_shift(unsigned int n, unsigned int k = 0)
{
    pb(n);
    pb(n >> 1);
    pb((n >> 1) << 1);
    pb(n == (n >> 1) << 1);
}

void is_power_of_2(unsigned int n, unsigned int k = 0)
{
    pb(n);
    pb(n - 1);
    pb((n & (n - 1)));
    pb(!(n & (n - 1)));
}

bool is_power_of_4(unsigned int n, unsigned int k = 0)
{
    // pb(n);
    int i = 1;
    while (i < n) {
        i = i << 2;
    }
    // pb(i);
    // pb(i & n);
    return i & n;
}

void toggle_kth_bit(unsigned int n, unsigned int k = 0)
{
    // Q 10
    pb(n);
    pb(1 << k - 1);
    pb(n ^ (1 << k - 1));
}

void count_set_bits(unsigned int n, unsigned int k = 0)
{
    // Q 11
    int count = 0;
    pb(n);
    while (n != 0) {
        if (n & 1 == 1) count++;
        n = n >> 1;
    }
    pb(count);
    // TODO : Brian Karnigham algorithm
}

void to_lower_case(char ch)
{
    // Q 13
    pb(ch);
    pb(' ');
    pb(ch | ' ');
    cout << (char)(ch | 32) << endl;
}

void to_upper_case(char ch)
{
    // Q 14
    pb(ch);
    pb('_');
    pb(ch & '_');
    cout << (char)(ch & 95) << endl;
}

void invert_case_xor(char ch)
{
    // Q 14
    pb(ch);
    pb(' ');
    pb(ch ^ ' ');
    cout << (char)(ch ^ 32) << endl;
}

void find_letter_position_in_alphabet(char ch)
{
    // Q 14
    // Works for both lowercase and uppercase
    pb(ch);
    pb(31);
    pb(ch & 31);
}

void find_odd_occuring_number(vector<int> arr)
{
    arr = { 1,3,1,3,4,5,5 };
    int res = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        res = res ^ arr[i];
    }

    cout << res << endl;
}


void swap_nums(int a, int b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    pb(a);
    pb(b);

}
// Q 19
void xor_1_to_n(int n)
{
    int res = 0;
    for (int i = 1; i <= n;i++)
    {
        res = res ^ i;
        cout << i << " "; pb(res);
    }
}


int main()
{
    init_code();
    // int t; cin >> t; while (t--) { solve(); }
    clear_kth_bit(13, 4);



}



// and 
// 0 & 0 = 0
// 0 & 1 = 0 // clear
// 1 & 0 = 0 // clear
// 1 & 1 = 1 // check

// or 
// 0 | 0 = 0
// 0 | 1 = 1 // set
// 1 | 0 = 1 
// 1 | 1 = 1 // set

// xor 
// 0 ^ 0 = 0
// 0 ^ 1 = 1 // flip
// 1 ^ 0 = 1
// 1 ^ 1 = 0 // flip

