#include <bits/stdc++.h>
using namespace std;

int result = 0;

int checkMatchesAndCalculatePoints(set<int>& win_nums, set<int>& have_nums) {
    int num_matches = 0;

    for (const auto& num : have_nums) {
        if (win_nums.find(num) != win_nums.end()) {
            num_matches++;
        }
    }

    if (num_matches == 0) return 0;

    return pow(2, num_matches - 1);
}

void addLine(string &str, int game_num)
{
    set<int> win_nums;
    set<int> have_nums;

    bool is_win_nums = true;

    string line = str.substr(str.find(':') + 2, str.length());

    for (int i = 0; i < line.size(); i++)
    {
        int num_val = 0;

        if (line[i] == '|')
        {
            is_win_nums = !is_win_nums;
            continue;
        }

        while (isdigit(line[i]))
        {
            num_val *= 10;
            num_val += line[i] - '0';
            i++;
        }

        if (num_val != 0)
        {
            cout << num_val << " ";

            if (!is_win_nums)
            {
                have_nums.insert(num_val);
            }
            else
            {
                win_nums.insert(num_val);
            }
        }
    }
    cout << "\n";

    result += checkMatchesAndCalculatePoints(win_nums, have_nums);
    cout << checkMatchesAndCalculatePoints(win_nums, have_nums) << "\n";
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream my_file("day4.txt");

    string line;
    if (my_file.is_open())
    {
        int game_num = 1;
        while (my_file)
        {
            getline(my_file, line);
            addLine(line, game_num);
            game_num++;
        }
    }

    // solve();

    cout << result;

    return 0;
}