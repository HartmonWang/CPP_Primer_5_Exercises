#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

using namespace std;

void elimDups(vector<string>& words)
{
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

void print_vector(string banner, vector<string>& v)
{
    cout << banner << endl;
    for (auto elem : v)
        cout << elem << " ";
    cout << endl;
}

int main()
{
    vector<string> v{"the",  "quick", "red",  "fox", "jumps",
                     "over", "the",   "slow", "red", "turtle"};
    print_vector("Before sort, v is: ", v);
    elimDups(v);
    print_vector("After sort, v is: ", v);

    return 0;
}