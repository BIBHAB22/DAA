#include <iostream>
#define INT_MAX 2147483647
using namespace std;
int arr[10] = {0};    // arbitrary array declaration
int n = 0;            // global variable
int dp[10][10] = {0}; // dp table
void readInput()
{
    cout << "Enter the number of matrices: ";
    cin >> n;
    cout << "Now enter the order of matrices: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void matrixChainMultiplication()
{
    // we are starting from matrix length 2 that's why len = 2
    for (int len = 2; len < n; len++)
    {
        // every time row starts from 0 and goes to last index
        // and column starts from the length index by default
        for (int row = 0, col = len; row < n - len; row++, col++)
        {
            dp[row][col] = INT_MAX;
            for (int k = row + 1; k < col; k++)
            {
                // main logic to implement matrix chain multiplication
                dp[row][col] = min(dp[row][col], dp[row][k] + dp[k][col] + arr[row] * arr[k] * arr[col]);
            }
        }
    }
    cout << "Minimum operations required is: " << dp[0][n - 1] << endl;
}

int main()
{
    readInput();
    matrixChainMultiplication();
    return 0;
}