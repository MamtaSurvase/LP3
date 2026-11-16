
#include <iostream>
using namespace std;

int main() {
    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    int weight[100], profit[100];

    for (int i = 1; i <= n; i++) {
        cout << "Enter weight and profit of item " << i << ": ";
        cin >> weight[i] >> profit[i];
    }

    cout << "Enter knapsack capacity: ";
    cin >> capacity;

    int dp[101][101] = {0};

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {

            if (weight[i] <= w) {
                int take = profit[i] + dp[i - 1][w - weight[i]];
                int skip = dp[i - 1][w];

                dp[i][w] = max(take, skip);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << "Maximum Profit = " << dp[n][capacity] << endl;

    return 0;
}
