#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class SolutionNSum {

public:
	vector<vector<int> > permuteUnique(vector<int> &num,int target,int searchdpth) {
		vector<vector<int> > res;
		vector<int> out;
		vector<int> visited(num.size(), 0);
		sort(num.begin(), num.end());
		permuteUniqueDFS(num, 0, target, searchdpth,visited, out, res);
		return res;
	}

	void permuteUniqueDFS(vector<int> &num, int level, int target,int searchdpth,vector<int> &visited, vector<int> &out, vector<vector<int> > &res) {
		if ((level >= num.size()|| target==0)&& searchdpth==0) res.push_back(out);
		else if (target < 0) return;
		else {
			for (int i = level; i < num.size(); ++i) {
				if (visited[i] == 0) {
					if (i > 0 && num[i] == num[i - 1] && visited[i - 1] == 0) continue;
					visited[i] = 1;
					out.push_back(num[i]);
					target = target- num[i];
					if (target >= 0) {
						permuteUniqueDFS(num, level + 1, target, searchdpth-1, visited, out, res);
					}
					target = target + num[i];
					out.pop_back();
					visited[i] = 0;
				}
			}
		}
	}
};

int main()

{
	int target;
	cin >> target;	//输入目标值
	string  str;
	vector<int> nums;
	int data=0,i=0;
	cin >> str;		//输入数组，数之间使用','隔开
	while (i < str.size())
	{
		if (str[i] != ',')
		{
			data = data * 10 + str[i] - '0';
		}
		else
		{
			nums.push_back(data);
			data = 0;
		}
		i++;
	}
	nums.push_back(data);
	int n=nums.size();
	SolutionNSum s3;

	for (int searchdpth= 1; searchdpth < nums.size(); searchdpth++) {
		vector<vector<int> > res = s3.permuteUnique(nums, target, searchdpth);
		for (int i = 0; i < res.size(); i++)
		{
			if (res[i].size() == 1)
			{
				cout << target << "=" << res[i][0] << endl;
			}
			else
			{
				cout << target << "=" << res[i][0];
				for (int j = 1; j < res[i].size(); j++)
					cout << "+" << res[i][j];
				cout << endl;
			}
		}
	}
	return 0;

}


//在leetcode中 twoSum解决思路主要是排序的数组后，以升序为例，先从右端固定一个值Fx，然后从固定值的左邻居Ni开始遍历，如果固定值Fx+Ni=target,则break结束，
//否则，Fx向左移动一个值，同样思路左邻居顺序移动遍历，如果要求出所有的这种组合，那么Fx+Ni=target后，不执行break，直到Fx为倒数第二数为止。
//当然这里也可以优化，基本上固定一个值后左邻居Ni的值已经固定了大小，可以用二分法在数组中查询是否存在Ni这个值。

//同样treeSum可以在twoSum基础上修改，即先固定一个值Fx将排序后固定值得左边子数组作为Twosum中数组，此时twoSum要求的目标值为target=target-Fx。
//fourSum的实现原理可以基于treeSum。

//总结下来其实就是一个深度搜索的问题，twoSum的搜索深度为2，treeSum的搜索深度为3，fourSum的搜索深度为4。如果求NSum问题，即搜索深度为4，

//add：
// Twosum可以使用哈希表实现，算法复杂度O(n)，但空间复杂度较大