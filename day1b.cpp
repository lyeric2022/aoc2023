#include <bits/stdc++.h>
using namespace std;

int total = 0;

unordered_map<string, int> my_map = {
    {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4}, {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9}};

int getNumIfContainsNum(const string &str_val)
{
    for (const auto &entry : my_map)
    {
        if (str_val.find(entry.first) != string::npos)
        {
            return entry.second;
        }
    }
    return -1;
}

void solve(string str)
{
    int digit = 0;
    string str_temp;

    for (int i = 0; i < str.size(); i++)
    {
        str_temp += str[i];

        int num_val = getNumIfContainsNum(str_temp);
        
        if (num_val != -1)
        {
            digit += num_val;
            break;
        }

        if (isdigit(str[i]))
        {
            digit += (str[i] - '0');
            break;
        }
    }

    digit *= 10;
    str_temp = "";

    for (int i = str.size() - 1; i >= 0; i--)
    {
        str_temp = str[i] + str_temp;

        int num_val = getNumIfContainsNum(str_temp);
        if (num_val != -1)
        {
            digit += num_val;
            break;
        }

        if (isdigit(str[i]))
        {
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

    ifstream my_file("day1b.txt");

    string line;
    if (my_file.is_open())
    {
        while (my_file)
        {
            getline(my_file, line);
            solve(line);
        }
    }

    cout << total;

    return 0;
}