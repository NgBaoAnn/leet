#include <iostream>
#include <string>

using namespace std;

// TODO
bool is_prime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
// END TODO

bool is_beautiful_number(int n)
{
    // TODO
    int sum = 0;
    int temp = n;
    int count = 1;

    while (temp > 0)
    {
        sum += temp % 10; // Sửa n thành temp
        temp /= 10;
    }

    temp = n;
    while (temp >= 10)
    {
        temp /= 10; // Lấy chữ số đầu tiên
    }
    count = temp;

        if (n % 10 == count && is_prime(sum) && (n % 10) % 2 == 1 && count % 2 == 1)
        return true;
    return false;
    // END TODO
}

string count_ways(int n)
{
    int ways = 0;
    int count_loops = 0;
    // TODO
    if (n % 100 != 0)
        return "0 0";

    for (int a = 0; 500 * a <= n; ++a)
    {
        int max_b = (n - 500 * a) / 200;
        ways += max_b + 1;
        count_loops++;
    }
    // END TODO
    return to_string(ways) + " " + to_string(count_loops);
}

int main()
{
    // Exercise 1
    int number = 131;
    bool beautiful_number = is_beautiful_number(number);
    cout << number << " is" << (beautiful_number ? " " : " not ") << "beautiful number!" << endl;

    // Exercise 2
    int money = 80000;
    string ways_count_loops = count_ways(money);
    cout << "There are " << ways_count_loops << " ways to aggregate " << money << endl;

    return 0;
}