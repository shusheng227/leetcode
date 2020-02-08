/**
 * 输入一个数组和一个目标值，输出数组中和为目标值的两个数
 */ 
#include <iostream>
#include <vector>
using namespace std;

#if(__cplusplus == 201103L)
#include <unordered_map>
#include <unordered_set>
#else
#include <tr1/unordered_map>
#include <tr1/unordered_set>
namespace std
{
	using std::tr1::unordered_map;
	using std::tr1::unordered_set;
}
#endif
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> m;
    vector<int> res;
    for (int i = 0; i < nums.size(); ++i) {
        m[nums[i]] = i;
    }
    for (int i = 0; i < nums.size(); ++i) {
        int t = target - nums[i];
        if (m.count(t) && m[t] != nums[i]) {
            res.push_back(nums[i]);
            res.push_back(t);
        	break;
    	}
    }
    return res;
}

int main()
{
	int target=9;
	vector<int> nums,result;
	nums.push_back(2);
	nums.push_back(5);
	nums.push_back(7);
	result = twoSum(nums,target);
	cout << result[0] << " " << result[1] << endl;
	return 0;
}
