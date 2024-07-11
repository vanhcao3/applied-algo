#include <bits/stdc++.h>
using namespace std;

int main()
{
    string input;
    int count = 0, countERR = 0, point, count_period;
    string user, problem, time, status;

    unordered_map<string, int> user_error;

    unordered_map<string, unordered_map<string, int>> max_user_problem_point;

    vector<string> submission_time;

    while (getline(cin, input))
    {
        if (input == "#")
            break;

        stringstream stream(input);
        stream >> user >> problem >> time >> status >> point;
        count++;
        if (status == "ERR")
        {
            countERR++;
            user_error[user]++;
        }

        max_user_problem_point[user][problem] = max(max_user_problem_point[user][problem], point);

        submission_time.emplace_back(time);
    }

    string command, from_time, to_time;
    sort(submission_time.begin(), submission_time.end());

    while (getline(cin, input))
    {
        if (input == "#")
            break;

        stringstream stream(input);
        if (input == "?total_number_submissions")
        {
            cout << count << endl;
        }
        else if (input == "?number_error_submision")
        {
            cout << countERR << endl;
        }
        else
        {
            stream >> command;
            if (command == "?number_error_submision_of_user")
            {
                stream >> user;
                cout << user_error[user] << endl;
            }
            else if (command == "?total_point_of_user")
            {
                stream >> user;

                int total_point = 0;

                for (const auto &entry : max_user_problem_point[user])
                {
                    total_point += entry.second;
                }
                cout << total_point << endl;
            }
            else if (command == "?number_submission_period")
            {
                stream >> from_time >> to_time;

                auto start_itr = lower_bound(submission_time.begin(), submission_time.end(), from_time);
                auto end_itr = upper_bound(submission_time.begin(), submission_time.end(), to_time);
                count_period = distance(start_itr, end_itr);
                cout << count_period << endl;
            }
        }
    }

    return 0;
}
