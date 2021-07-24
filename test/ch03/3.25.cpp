#include <iostream>
#include <vector>

using namespace std;
int main()
{
    vector<unsigned> scores(11, 0);
    unsigned         grade;
    while (cin >> grade) {
        if (grade <= 100)
            ++*(scores.begin() + grade / 10);
        else
            break;
    }

    for (decltype(scores.size()) idx = 0; idx != scores.size(); ++idx) {
        cout << "Grade[" << idx << "]: " << scores[idx] << endl;
    }
}
