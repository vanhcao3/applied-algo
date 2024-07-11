#include <bits/stdc++.h>
using namespace std;

typedef struct person
{
    string code;
    string date_of_birth;
    string father_code;
    string mother_code;
    char is_alive;
    string region_code;

    person(string code, string date_of_birth, string father_code, string mother_code, char is_alive)
        : code(code), date_of_birth(date_of_birth), father_code(father_code), mother_code(mother_code), is_alive(is_alive) {}
} person;

pair<int, string> mostAliveAncestor(person *currentPerson, int currentGeneration, unordered_map<string, person *> &people)
{
    if (!currentPerson)
    {
        return {currentGeneration, ""};
    }

    pair<int, string> fatherResult = mostAliveAncestor(people[currentPerson->father_code], currentGeneration + 1, people);
    pair<int, string> motherResult = mostAliveAncestor(people[currentPerson->mother_code], currentGeneration + 1, people);

    if (currentPerson->is_alive == 'Y')
    {
        if (fatherResult.first >= motherResult.first)
        {
            return {fatherResult.first, fatherResult.second};
        }
        else
        {
            return {motherResult.first, motherResult.second};
        }
    }
    else
    {
        if (fatherResult.first >= motherResult.first)
        {
            return fatherResult;
        }
        else
        {
            return motherResult;
        }
    }
}

int dfs(string currentCode, unordered_map<string, person *> &people, unordered_set<string> &visited)
{
    if (visited.find(currentCode) != visited.end())
    {
        return 0;
    }

    visited.insert(currentCode);
    person *currentPerson = people[currentCode];

    int count = 1;

    if (currentPerson->father_code != "0000000")
    {
        count += dfs(currentPerson->father_code, people, visited);
    }

    if (currentPerson->mother_code != "0000000")
    {
        count += dfs(currentPerson->mother_code, people, visited);
    }

    return count;
}

int maxUnrelatedPeople(unordered_map<string, person *> &people)
{
    unordered_set<string> unrelatedPeople;
    unordered_set<string> potentialParents;

    for (auto &entry : people)
    {
        person *currentPerson = entry.second;
        unrelatedPeople.insert(currentPerson->code);
        potentialParents.insert(currentPerson->father_code);
        potentialParents.insert(currentPerson->mother_code);
    }

    for (const string &parent : potentialParents)
    {
        unrelatedPeople.erase(parent);
    }

    int maxSubsetSize = 0;

    for (const string &code : unrelatedPeople)
    {
        unordered_set<string> visited;
        int currentSubsetSize = dfs(code, people, visited);
        maxSubsetSize = max(maxSubsetSize, currentSubsetSize);
    }

    return maxSubsetSize * 2;
}

int main()
{
    string input, command, date, from_date, to_date;
    // In
    string person_code, dob, father, mother, region;
    char alive;
    // Out
    int count = 0;
    vector<string> dob_count;
    unordered_map<string, int> dob_count_direct;
    unordered_map<string, person *> people;

    while (getline(cin, input))
    {
        if (input == "*")
            break;

        stringstream stream(input);
        stream >> person_code >> dob >> father >> mother >> alive >> region;
        count++;
        dob_count.emplace_back(dob);
        dob_count_direct[dob]++;
        person *individual = new person(person_code, dob, father, mother, alive);
        people[person_code] = individual;
    }

    sort(dob_count.begin(), dob_count.end());

    while (getline(cin, input))
    {
        if (input == "***")
            break;

        stringstream stream(input);
        if (input == "NUMBER_PEOPLE")
        {
            cout << count << endl;
        }
        else if (input == "MAX_UNRELATED_PEOPLE")
        {
            int maxUnrelated = maxUnrelatedPeople(people);
            cout << maxUnrelated << endl;
        }
        else
        {
            stream >> command;
            if (command == "NUMBER_PEOPLE_BORN_AT")
            {
                stream >> date;
                if (dob_count_direct.find(date) == dob_count_direct.end())
                    cout << 0 << endl;
                else
                    cout << dob_count_direct[date] << endl;
            }
            else if (command == "MOST_ALIVE_ANCESTOR")
            {
                stream >> person_code;
                if (people.find(person_code) != people.end())
                {
                    person *targetPerson = people[person_code];
                    pair<int, string> result = mostAliveAncestor(targetPerson, -1, people);
                    cout << result.first << endl;
                }
                else
                {
                    cout << 0 << endl;
                }
            }
            else if (command == "NUMBER_PEOPLE_BORN_BETWEEN")
            {
                stream >> from_date >> to_date;
                count = 0;

                auto start_itr = lower_bound(dob_count.begin(), dob_count.end(), from_date);
                auto end_itr = upper_bound(dob_count.begin(), dob_count.end(), to_date);

                count = distance(start_itr, end_itr);
                cout << count << endl;
            }
        }
    }

    return 0;
}
