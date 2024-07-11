#include <bits/stdc++.h>
using namespace std;

typedef struct Transaction
{
    unordered_map<string, vector<string>> adj;
    unordered_set<string> visited;

    bool dfs(const string &currentAccount, const string &startAccount, int length)
    {
        if (length == 0)
        {
            return currentAccount == startAccount;
        }

        visited.insert(currentAccount);

        for (auto it = adj[currentAccount].begin(); it != adj[currentAccount].end(); ++it)
        {
            const string &nextAccount = *it;
            if (visited.find(nextAccount) == visited.end())
            {
                if (dfs(nextAccount, startAccount, length - 1))
                {
                    return true;
                }
            }
            else if (nextAccount == startAccount && length == 1)
            {
                return true;
            }
        }

        visited.erase(currentAccount);
        return false;
    }

    inline void addTransaction(const string &fromAccount, const string &toAccount)
    {
        adj[fromAccount].push_back(toAccount);
    }

    bool inspect_cycle(const string &startAccount, int length)
    {
        visited.clear();
        return dfs(startAccount, startAccount, length);
    }
} Transaction;

int main()
{
    string input;
    string from, to, time, atm;
    int count = 0, amount, total_money = 0;
    map<string, int> accounts;
    vector<pair<string, string>> transactions;
    Transaction list;

    while (getline(cin, input))
    {
        if (input == "#")
            break;

        stringstream stream(input);
        count++;
        stream >> from >> to >> amount >> time >> atm;
        total_money += amount;
        accounts[from] += amount;
        accounts[to];
        transactions.push_back({from, to});
    }

    while (getline(cin, input))
    {
        if (input == "#")
            break;
        stringstream stream(input);
        if (input == "?number_transactions")
        {
            cout << count << endl;
        }
        else if (input == "?total_money_transaction")
        {
            cout << total_money << endl;
        }
        else if (input == "?list_sorted_accounts")
        {
            for (const auto &account : accounts)
            {
                cout << account.first << " ";
            }
            cout << endl;
        }
        else
        {
            string command, account;
            stream >> command >> account;
            if (command == "?total_money_transaction_from")
            {
                cout << accounts[account] << endl;
            }
            else
            {
                for (auto &itr : transactions)
                {
                    list.addTransaction(itr.first, itr.second);
                }
                int k;
                stream >> k;
                cout << list.inspect_cycle(account, k) << endl;
            }
        }
    }

    return 0;
}
