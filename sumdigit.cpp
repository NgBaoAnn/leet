#include <iostream>
#include <map>

using namespace std;
int sumDigits(int n)
{
    int sum = 0;
    while (n > 0)
    {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}
int countLargestGroup(int n)
{
    int count = 0;
    map<int, int> m;
    for (int i = 1; i <= n; i++)
    {
        m[sumDigits(i)]++;
    }
    auto max_it = std::max_element(
        m.begin(), m.end(),
        [](const auto &a, const auto &b)
        {
            return a.second < b.second;
        });
    int max_val = max_it->second;
    int count = std::count_if(
        m.begin(), m.end(),
        [max_val](const auto &p)
        {
            return p.second == max_val;
        });
    return count;
}
int main()
{
    return 0;
}