#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int SIZE = 26;

// Có thể thay đổi mảng nums theo nhu cầu của bạn
vector<int> nums = {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2
};

using Matrix = vector<vector<long long>>;

// Nhân hai ma trận 26x26
Matrix multiply(const Matrix& A, const Matrix& B) {
    Matrix res(SIZE, vector<long long>(SIZE, 0));
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            for (int k = 0; k < SIZE; ++k)
                res[i][j] = (res[i][j] + A[i][k] * B[k][j]) % MOD;
    return res;
}

// Lũy thừa ma trận
Matrix matrixPower(Matrix base, long long exp) {
    Matrix res(SIZE, vector<long long>(SIZE, 0));
    for (int i = 0; i < SIZE; ++i)
        res[i][i] = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            res = multiply(res, base);
        base = multiply(base, base);
        exp /= 2;
    }
    return res;
}

// Hàm chính theo yêu cầu của bạn
int lengthAfterTransformations(string s, int t) {
    vector<long long> freq(SIZE, 0);
    for (char c : s) {
        freq[c - 'a']++;
    }

    // Tạo ma trận chuyển đổi
    Matrix T(SIZE, vector<long long>(SIZE, 0));
    for (int i = 0; i < SIZE; ++i) {
        for (int k = 1; k <= nums[i]; ++k) {
            T[i][(i + k) % SIZE] = (T[i][(i + k) % SIZE] + 1) % MOD;
        }
    }

    // Tính T^t
    Matrix T_pow = matrixPower(T, t);

    // Nhân vector tần suất ban đầu với T^t
    vector<long long> result(SIZE, 0);
    for (int i = 0; i < SIZE; ++i)
        for (int j = 0; j < SIZE; ++j)
            result[j] = (result[j] + freq[i] * T_pow[i][j]) % MOD;

    // Tổng độ dài chuỗi sau t lần biến đổi
    long long total = 0;
    for (int i = 0; i < SIZE; ++i)
        total = (total + result[i]) % MOD;

    return static_cast<int>(total);
}
int main() {
    string s = "abcyy";
    int t = 2;
    cout << lengthAfterTransformations(s, t) << endl;  // Output: 7
}
