#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream my_file("day4.txt");

    string line;
    if (my_file.is_open())
    {
        while (my_file)
        {
            getline(my_file, line);

            addLine(line, game_num);

            game_num++;
        }
    }

    return 0;
}