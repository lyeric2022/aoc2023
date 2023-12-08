#include <bits/stdc++.h>
using namespace std;

int total = 0;

void solve(string &str)
{
    cout << str << "\n";
    map<string, int> my_colors = {{"red", 0}, {"green", 0}, {"blue", 0}};
    map<string, int> max_colors = {{"red", 0}, {"green", 0}, {"blue", 0}};

    string line = str.substr(5);

    int i = 1;
    for (; i < line.size(); i++)
    {
        if (!isdigit(line[i]))
        {
            line = line.substr(i + 2);
            break;
        }
    }

    string str_temp = "";
    int num_val = line[0] - '0';
    i = 1;

    while (i < line.size())
    {
        if (isdigit(line[i]))
        {
            num_val *= 10;
            num_val += line[i] - '0';
        }

        if (isalpha(line[i]))
        {
            str_temp += line[i];
        }

        if (line[i] == ',')
        {
            my_colors[str_temp] += num_val;
            num_val = 0;
            str_temp = "";
        }

        if (line[i] == ';')
        {
            my_colors[str_temp] += num_val;

            for (const auto val : my_colors)
            {
                max_colors[val.first] = max(max_colors[val.first], val.second);
            }

            num_val = 0;
            str_temp = "";

            my_colors = {{"red", 0}, {"green", 0}, {"blue", 0}};
        }

        i++;
    }

    my_colors[str_temp] += num_val;

    int colors_cubed = 1;
    for (auto val : max_colors)
    {
        max_colors[val.first] = max(max_colors[val.first], my_colors[val.first]);
        colors_cubed *= max_colors[val.first];
    }

    cout << colors_cubed << "\n";

    max_colors = {{"red", 0}, {"green", 0}, {"blue", 0}};

    total += colors_cubed;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream my_file("day2b.txt");

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