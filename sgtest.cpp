#include <iostream>
#include <string.h>
#include "fraction.h"

using namespace std;


void solve(const string &row)
{
    // Int Buffer Size 26 for each letter in alphabet
    int counts[26] = {0};
    int unique = 0;
    int total = 0;

    // Read through every char in input, add to count, unique, total
    for (uint64_t cur = 0; cur < row.length(); cur++)
    {
        // Uppercase ASCII Chars
        if (row[cur] > 64 && row[cur] < 91)
        {
            // Count unique chars excluding wildcards
            if (!counts[row[cur] - 'A'] && row[cur] - 'A' != 22)
                unique++;
            counts[row[cur] - 'A']++;
            total++;
        }
    }

    //Output Answer to stdout
    cout << "Output:\n";
    // (prob. of letter) * (prob of wildcard)
    Fraction wildcard_prob = Fraction(1, unique) * Fraction(1, total) * counts[22];
    for (int i = 0; i < 26; i++)
    {
        // Don't print W, and only if
        if (i != 22 && counts[i])
        {
            Fraction letter_prob = Fraction(counts[i], total);
            // If wildcard, remove it
            if (counts[22])
                letter_prob = letter_prob + wildcard_prob;
            cout << "  " << char('A' + i) << ": " << letter_prob << "\n";
        }
    }
}

int main(void)
{
    string cur_row;
    int row_num = 1;
    ios_base::sync_with_stdio(false);
    // File Input
    std::ifstream infile("input.txt", std::ios_base::in);
    while (getline(infile, cur_row))
    {
        cout << "-Row " << row_num++ << "-\n";
        cout << "Input:\n  " << cur_row << "\n";
        solve(cur_row);
        cout << "\n";
    }
}