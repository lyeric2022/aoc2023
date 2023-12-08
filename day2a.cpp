#include <bits/stdc++.h>
using namespace std;

int total = 0;

map<string, int> my_map = {{"red", 12}, {"green", 13}, {"blue", 14}};

void solve(string &str)
{
    bool pass = true;

    map<string, int> my_colors = {{"red", 0}, {"green", 0}, {"blue", 0}};

    string line = str.substr(5);

    int sum = line[0] - '0';

    int i = 1;
    for (; i < line.size(); i++)
    {
        if (!isdigit(line[i]))
        {
            line = line.substr(i + 2);
            break;
        }

        sum *= 10;
        sum += line[i] - '0';
    }

    string str_temp = "";
    int num_val = line[0] - '0';
    cout << num_val << "\n";
    i = 1;

    while (i < line.size())
    {
        if (isdigit(line[i]))
        {
            num_val *= 10;
            num_val += line[i] - '0';
            cout << num_val << "\n";
        }

        if (isalpha(line[i]))
        {
            str_temp += line[i];
        }

        if (line[i] == ',')
        {
            my_colors[str_temp] += num_val;
            // cout << num_val << " " << str_temp << " " << my_colors[str_temp] << "\n";
            num_val = 0;
            str_temp = "";
        }

        if (line[i] == ';')
        {
            my_colors[str_temp] += num_val;

            for (const auto val : my_colors)
            {
                cout << val.first << " " << val.second << "\n";
                if (my_map[val.first] < val.second)
                {
                    pass = false;
                }
            }
            num_val = 0;
            str_temp = "";

            my_colors = {{"red", 0}, {"green", 0}, {"blue", 0}};
        }

        i++;
    }

    my_colors[str_temp] += num_val;
    // cout << num_val << " " << str_temp << " " << my_colors[str_temp] << "\n";

    for (auto val : my_colors)
    {
        cout << val.first << " " << val.second << "\n";
        if (my_map[val.first] < val.second)
        {
            pass = false;
        }
    }

    cout << str << "\n";
    if (pass)
    {
        cout << "true\n\n";
        total += sum;
    }
    else
    {
        cout << "false\n\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream my_file("day2a.txt");

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