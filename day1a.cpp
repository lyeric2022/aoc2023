#include <bits/stdc++.h>
using namespace std;

int total = 0;

void solve(string str)
{
    int digit = 0;

    for (int i = 0; i < str.size(); i++) {

        if (isdigit(str[i])) {
            digit += (str[i] - '0');
            digit *= 10;
            break;
        }
    }

    for (int i = str.size() - 1; i >= 0; i--) {
        if (isdigit(str[i])) {
            digit += (str[i] - '0');
            break;
        }
    }

    total += digit;
    cout << digit << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream my_file("day1a.txt");

    string line;
    if (my_file.is_open())
    {
        while (my_file)
        {
            getline(my_file, line);
            // cout << line << "\n"; // Output each line from the file
            solve(line);
        }
    }

    cout << total;

    return 0;
}