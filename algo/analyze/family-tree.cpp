#include <bits/stdc++.h>
using namespace std;

typedef struct person
{
    string name;
    person *father;
    vector<person *> child;
    int generation;

} person;

int countDescendant(person *ancestor)
{
    int count = 0;
    for (person *child : ancestor->child)
    {
        count += countDescendant(child) + 1;
    }
    return count;
}

void updateGeneration(person *individual)
{
    int lastGen = -1;
    for (person *child : individual->child)
    {
        updateGeneration(child);
        lastGen = max(lastGen, child->generation);
    }
    individual->generation = lastGen + 1;
}

int main()
{
    string father, child;
    string command, name;
    string input;
    multimap<string, string> family_tree;
    map<string, person *> individuals;

    while (getline(cin, input))
    {
        if (input == "***")
            break;
        stringstream stream(input);
        stream >> child >> father;

        family_tree.insert({child, father});
    }

    for (auto itr : family_tree)
    {
        person *child = new person{itr.first, nullptr, {}, 1};
        person *father = new person{itr.second, nullptr, {}, 1};

        if (individuals.find(itr.first) == individuals.end())
        {
            individuals.insert({itr.first, child});
        }
        else
        {
            child = individuals[itr.first];
        }

        if (individuals.find(itr.second) == individuals.end())
        {
            individuals.insert({itr.second, father});
        }
        else
        {
            father = individuals[itr.second];
        }

        child->father = father;
        father->child.push_back(child);
    }

    for (auto &itr : individuals)
    {
        if (!itr.second->father)
        {
            updateGeneration(itr.second);
        }
    }

    while (getline(cin, input))
    {
        if (input == "***")
            break;
        stringstream stream(input);
        stream >> command >> name;

        if (command == "descendants")
        {
            cout << countDescendant(individuals[name]) << endl;
        }
        else if (command == "generation")
        {
            cout << individuals[name]->generation << endl;
        }
    }

    return 0;
}
