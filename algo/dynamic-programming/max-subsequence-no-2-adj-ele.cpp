#include <iostream>
#include <vector>
using namespace std;

int maxSubsetSumNoAdjacent(vector<int> nums)
{
    if (nums.empty())
        return 0;
    if (nums.size() == 1)
        return nums[0];
    nums[1] = max(nums[0], nums[1]);
    for (int i = 2; i < (int)nums.size(); i++)
    {
        nums[i] = max(nums[i - 1], nums[i] + nums[i - 2]);
    }
    return nums.back();
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << maxSubsetSumNoAdjacent(nums) << endl;
    return 0;
}