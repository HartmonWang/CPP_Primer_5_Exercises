#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

using namespace std;

bool predicate(const string& s)
{
    return s.size() >= 5;
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
    auto pivot = partition(v.begin(), v.end(), predicate);

    cout << "After partition: " << endl;
    for (auto it = v.cbegin(); it != pivot; ++it)
        cout << *it << " ";
    cout << endl;
    return 0;
}