#include <bits/stdc++.h>
using namespace std;

int main()
{
    string input;
    int count = 0, total_revenue = 0, amount;
    string customer, product, shop, time;

    unordered_map<string, int> shop_revenue;
    unordered_map<string, int> shop_customer;

    vector<pair<string, int>> time_amount;

    while (getline(cin, input))
    {
        if (input == "#")
            break;

        stringstream stream(input);
        stream >> customer >> product >> amount >> shop >> time;
        count++;
        total_revenue += amount;
        shop_revenue[shop] += amount;
        shop_customer[shop + customer] += amount;
        time_amount.push_back({time, amount});
    }

    while (getline(cin, input))
    {
        if (input == "#")
            break;

        if (input == "?total_number_orders")
        {
            cout << count << endl;
        }
        else if (input == "?total_revenue")
        {
            cout << total_revenue << endl;
        }
        else
        {
            stringstream stream(input);
            string command;
            stream >> command;
            if (command == "?revenue_of_shop")
            {
                string shop;
                stream >> shop;
                cout << shop_revenue[shop] << endl;
            }
            else if (command == "?total_consume_of_customer_shop")
            {
                string shop, customer;
                stream >> customer >> shop;
                cout << shop_customer[shop + customer] << endl;
            }
            else if (command == "?total_revenue_in_period")
            {
                string from_time, to_time;
                stream >> from_time >> to_time;

                amount = 0;
                for (auto &itr : time_amount)
                {
                    if (itr.first >= from_time && itr.first <= to_time)
                    {
                        amount += itr.second;
                    }
                }
                cout << amount << endl;
            }
        }
    }

    return 0;
}
