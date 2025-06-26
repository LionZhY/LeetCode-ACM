#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target)
{
	unordered_map<int, int> umap;
	for (int i = 0; i < nums.size(); i++)
	{
		if (umap.find(target - nums[i]) != umap.end())
		{
			return { umap[target - nums[i]], i };
		}
		umap.insert(pair<int, int>(nums[i], i));
	}
	
	return {};
}

int main() {
	int n, target; // 数组长度n，目标值target
	cin >> n >> target;
	vector<int> nums(n);

	for (int i = 0; i < n; i++) {
		cin >> nums[i]; // 输入数组元素
	}

	vector<int> result = twoSum(nums, target);

	if (!result.empty()) {
		cout << result[0] << " " << result[1] << endl;
	}
	else {
		cout << "No result" << endl;
	}

	return 0;

}