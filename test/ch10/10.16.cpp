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

string make_plural(size_t ctr, const string& word, const string& ending)
{
    return (ctr > 1) ? word + ending : ending;
}

void biggies(vector<string>& words, vector<string>::size_type sz)
{
    elimDups(words);
    stable_sort(
        words.begin(), words.end(),
        [](const string& a, const string& b) { return a.size() < b.size(); });
    auto wc    = find_if(words.begin(), words.end(),
                      [sz](const string& a) { return a.size() >= sz; });
    auto count = words.end() - wc;
    cout << count << " " << make_plural(count, "word", "s") << " of length "
         << sz << " or longer" << endl;

    for_each(wc, words.end(), [](const string& s) { cout << s << " "; });
    cout << endl;
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
    biggies(v, 5);

    return 0;
}