#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> time_distance;

void getNumPossibles()
{
    int result = 1;
    // vector<int> nums_possible;

    for (int i = 0; i < time_distance.size(); i++)
    {
        cout << time_distance[i].first << " " << time_distance[i].second << "\n";
        int possible = 0;

        for (int hold = 0; hold < time_distance[i].first; hold++)
        {
            // cout << hold * (time_distance[i].first - hold) << " " << time_distance[i].second << "\n";
            if (hold * (time_distance[i].first - hold) > time_distance[i].second)
            {
                possible++;
            }
        }
        // cout << "\n\n";
        // nums_possible.push_back(possible);

        // cout << result << " " << possible << "\n";
        result *= possible;
    }
    cout << "result: " << result;
}

vector<int> getNumbers(string &str)
{
    vector<int> values;
    int num = 0;

    for (int i = 0; i < str.size(); i++)
    {
        if (isdigit(str[i]))
        {
            if (str[max(0, i - 1)] == ' ' && num != 0)
            {
                values.push_back(num);
                num = 0;
            }

            num *= 10;
            num += str[i] - '0';
        }
    }

    values.push_back(num);

    return values;
}

void parseValues(string &time_text, string &dist_text)
{
    string time_str;
    string dist_str;

    for (int i = 0; i < time_text.size(); i++)
    {
        if (isdigit(time_text[i]))
        {
            time_str = time_text.substr(i);
            break;
        }
    }

    for (int i = 0; i < dist_text.size(); i++)
    {
        if (isdigit(dist_text[i]))
        {
            dist_str = dist_text.substr(i);
            break;
        }
    }

    vector<int> time_values = getNumbers(time_text);
    vector<int> dist_values = getNumbers(dist_text);

    for (int i = 0; i < time_values.size(); i++)
    {
        time_distance.push_back({time_values[i], dist_values[i]});
        // cout << time_distance[i].first << " " << time_distance[i].second << "\n";
    }

    getNumPossibles();
    // vector<int> num_ways = getNumPossibles();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream my_file("day6.txt");

    string line;
    if (my_file.is_open())
    {
        while (my_file)
        {
            // cout << "hello";
            string time_text = "";
            string dist_text = "";

            getline(my_file, time_text);
            getline(my_file, dist_text);

            parseValues(time_text, dist_text);
            break;
        }
    }

    return 0;
}