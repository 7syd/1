#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// Function to calculate the optimal cost of a binary search tree
float optimalBST(const vector<float>& keys, const vector<float>& probabilities) {
    int n = keys.size();

    // Create a 2D table to store the optimal cost
    vector<vector<float> > cost(n + 1, vector<float>(n + 1, 0));

    // Fill the diagonal values with the individual probabilities
    for (int i = 0; i < n; i++)
        cost[i][i] = probabilities[i];

    // Build the table in a bottom-up manner
    for (int L = 2; L <= n; L++) {
        for (int i = 0; i <= n - L + 1; i++) {
            int j = i + L - 1;
            cost[i][j] = numeric_limits<float>::max();

            // Calculate the sum of probabilities between keys[i] and keys[j]
            float sum = 0;
            for (int k = i; k <= j; k++)
                sum += probabilities[k];

            // Try all possible roots from keys[i] to keys[j]
            for (int r = i; r <= j; r++) {
                float c = ((r > i) ? cost[i][r - 1] : 0) + ((r < j) ? cost[r + 1][j] : 0) + sum;
                if (c < cost[i][j])
                    cost[i][j] = c;
            }
        }
    }

    // Return the optimal cost of the binary search tree
    return cost[0][n - 1];
}

int main() {
    int n;
    cout << "Enter the number of keys: ";
    cin >> n;

    vector<float> keys(n);
    vector<float> probabilities(n);

    cout << "Enter the keys in sorted order:\n";
    for (int i = 0; i < n; i++) {
        cin >> keys[i];
    }

    cout << "Enter the corresponding access probabilities:\n";
    for (int i = 0; i < n; i++) {
        cin >> probabilities[i];
    }

    float optimalCost = optimalBST(keys, probabilities);
    cout << "Optimal cost of the binary search tree: " << optimalCost << endl;

    return 0;
}

