#include <iostream>
#include <string>
#include <functional>

using namespace std;

bool allDigitsWithinLimit(const string& numberStr, int limit) {
    for (char c : numberStr) {
        if (c - '0' > limit)
            return false;
    }
    return true;
}

long long numberOfPowerfulInt(long long start, long long finish, int limit,
                              string s) {
    long long result = 0;
    int maxLength = to_string(finish).size();

    function<void(string)> dfs = [&](string prefix) {
        string current = prefix + s;

        if (current.size() > maxLength)
            return;

        if (!allDigitsWithinLimit(current, limit))
            return;

        long long num = stoll(current);
        if (num > finish)
            return;
        if (num >= start)
            result++;

        for (int d = 0; d <= limit; ++d) {
            if (prefix.empty() && d == 0) continue; // ❗ tránh prefix bắt đầu bằng '0'
            dfs(prefix + char('0' + d));
        }
    };

    dfs("");

    return result;
}

int main() {
    cout << numberOfPowerfulInt(1, 6000, 4, "124") << endl; // ✅ Output: 5
}
