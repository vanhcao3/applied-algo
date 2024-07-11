#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>

// Function to convert time string to seconds for easier comparison
int timeToSeconds(const std::string &time)
{
    int hours, minutes, seconds;
    char colon;
    std::istringstream timeStream(time);
    timeStream >> hours >> colon >> minutes >> colon >> seconds;
    return hours * 3600 + minutes * 60 + seconds;
}

// Main function to process orders and queries
int main()
{
    std::string line;
    std::unordered_map<std::string, int> ordersAtTime; // Map to store orders count at each time point
    std::vector<std::string> orderTimes;               // Vector to store all order times for range queries

    // Reading orders
    while (std::getline(std::cin, line) && line != "#")
    {
        std::istringstream lineStream(line);
        std::string orderId, timePoint;
        lineStream >> orderId >> timePoint;
        ordersAtTime[timePoint]++;
        orderTimes.push_back(timePoint);
    }

    // Processing queries
    while (std::getline(std::cin, line) && line != "###")
    {
        std::istringstream queryStream(line);
        std::string queryType;
        queryStream >> queryType;

        if (queryType == "?number_orders")
        {
            std::cout << orderTimes.size() << std::endl;
        }
        else if (queryType == "?number_orders_in_period")
        {
            std::string fromTime, toTime;
            queryStream >> fromTime >> toTime;
            int fromSeconds = timeToSeconds(fromTime);
            int toSeconds = timeToSeconds(toTime);
            int count = 0;
            for (const auto &time : orderTimes)
            {
                int orderTimeSeconds = timeToSeconds(time);
                if (orderTimeSeconds >= fromSeconds && orderTimeSeconds <= toSeconds)
                {
                    count++;
                }
            }
            std::cout << count << std::endl;
        }
        else if (queryType == "?number_orders_at_time")
        {
            std::string timePoint;
            queryStream >> timePoint;
            std::cout << ordersAtTime[timePoint] << std::endl;
        }
    }

    return 0;
}