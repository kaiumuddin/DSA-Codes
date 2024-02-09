#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long int;

map<int, ull> memo = {};

void pMemo()
{
    for (auto e : memo)
        cout << e.first << "\t" << e.second << endl;
}

void pVector(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
        cout << v.at(i) << " ";

    cout << endl;
}

void pVector(vector<int> *v)
{
    if (v == nullptr)
    {
        cout << "NULL" << endl;
        return;
    }

    for (int i = 0; i < v->size(); i++)
        cout << v->at(i) << " ";
    cout << endl;
}

// bool bestSum(int targetSum, vector<int> numbers)
// {
//     static vector<int> contain(100);
//     static vector<int> seq;

//     if (targetSum == 0)
//         return true;
//     if (targetSum < 0)
//         return false;

//     for (auto num : numbers)
//     {
//         seq.push_back(num);
//         int remain = targetSum - num;

//         if (bestSum(remain, numbers) == true)
//         {
//             if (seq.size() < contain.size())
//                 contain = seq;
//             seq.pop_back();
//         }
//         else
//             seq.pop_back();
//     }

//     if (seq.size() == 0)
//         pVector(contain), contain.resize(100);
// }

vector<int> *bestSum(int targetSum, vector<int> numbers)
{
    if (targetSum == 0)
        return new vector<int>();
    if (targetSum < 0)
        return nullptr;

    vector<int> *shortestCombination = nullptr;

    for (auto num : numbers)
    {
        int remain = targetSum - num;
        vector<int> *remainderCombination = bestSum(remain, numbers);

        if (remainderCombination != nullptr)
        {
            vector<int> *combination = new vector<int>();
            combination->assign(remainderCombination->begin(), remainderCombination->end());
            combination->push_back(num);

            if (shortestCombination == nullptr || combination->size() < shortestCombination->size())
            {
                shortestCombination = combination;
            }
        }
    }

    return shortestCombination;
}

vector<int> *make()
{
    return nullptr;
}

int main()
{
    system("cls");
    pVector(bestSum(7, {3, 1}));
    pVector(bestSum(7, {7, 7}));
    pVector(bestSum(7, {3, 2}));
    pVector(bestSum(7, {5, 4, 3, 7}));
    pVector(bestSum(6, {3, 2, 1}));
    pVector(bestSum(8, {3, 5, 2}));
    pVector(bestSum(6, {7, 6, 3}));
    pVector(bestSum(100, {10, 80, 90}));
    // pVector(contain);
    bestSum(7, {5, 3});
    bestSum(7, {4, 2});
}
