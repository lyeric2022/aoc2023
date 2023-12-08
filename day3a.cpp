#include <bits/stdc++.h>
using namespace std;

int total = 0;

vector<vector<char>> v_2d;
set<pair<int, int>> my_set;

void add(string &str)
{
    vector<char> v_row;
    for (int i = 0; i < str.size(); i++)
    {
        v_row.push_back(str[i]);
    }

    v_2d.push_back(v_row);
}

bool checkAdjacentSumbols(int row, int col_begin, int col_end)
{
    // cout << row << " " << col_begin << " " << col_end << "\n";

    int top_row = row - 1;
    int bot_row = row + 1;
    int left_col = std::max(0, col_begin - 1);
    int right_col = std::min((int)v_2d[row].size() - 1, (int)col_end + 1);

    // cout << left_col << " " << right_col << "\n";

    if (my_set.find({row, left_col}) != my_set.end())
    {
        return true;
    }

    if (my_set.find({row, right_col}) != my_set.end())
    {
        return true;
    }

    if (top_row >= 0)
    {
        for (int i = left_col; i <= right_col; i++)
        {
            std::pair<int, int> my_pair = {top_row, i};

            if (my_set.find(my_pair) != my_set.end())
            {
                return true;
            }
        }
    }

    if (bot_row <= v_2d.size() - 1)
    {
        for (int i = left_col; i <= right_col; i++)
        {
            std::pair<int, int> my_pair = {bot_row, i};

            if (my_set.find(my_pair) != my_set.end())
            {
                return true;
            }
        }
    }

    return false;
}

void solve()
{
    for (int i = 0; i < v_2d.size(); i++)
    {
        for (int j = 0; j < v_2d[i].size(); j++)
        {
            if (!isalnum(v_2d[i][j]) && v_2d[i][j] != '.')
            {
                my_set.insert({i, j});
                // cout << i << " " << j << "\n";
            }
        }
    }
    // cout << "\n";

    for (int i = 0; i < v_2d.size(); i++)
    {
        int j = 0;
        int start, end;

        for (; j < v_2d[i].size(); j++)
        {
            int num_val = 0;

            if (isdigit(v_2d[i][j]))
            {
                start = j;
                while (j < v_2d.size() && isdigit(v_2d[i][j]))
                {
                    num_val *= 10;
                    num_val += v_2d[i][j] - '0';
                    end = j;
                    j++;
                }

                if (checkAdjacentSumbols(i, start, end))
                {
                    // cout << num_val << "\n";
                    total += num_val;
                }
                // cout << "\n";
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream my_file("day3a.txt");

    string line;
    if (my_file.is_open())
    {
        while (my_file)
        {
            getline(my_file, line);
            add(line);
        }
    }

    solve();

    cout << total;

    return 0;
}