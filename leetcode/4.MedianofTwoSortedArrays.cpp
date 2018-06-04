// 求两个已排序数列的中位数
// 先求中位数的index（判定奇偶），先归并，再查找（或者同时进行）

// https://leetcode.com/problems/median-of-two-sorted-arrays/description/
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int size1 = nums1.size();
		int size2 = nums2.size();
		int size = size1 + size2;
		bool it1end = false;
		bool it2end = false;
		bool odd;
		int step;

		int i = 0;

		vector<int>::iterator it1 = nums1.begin();
		vector<int>::iterator it2 = nums2.begin();
		vector<int> merge;

		//judge step
		if (size % 2 == 0)//even
		{
			odd = false;
			step = size / 2;  //index = step and step + 1
		}
		else//odd
		{
			odd = true;
			step = (size + 1) / 2;
		}

		while (it1 != nums1.end() && it2 != nums2.end())
		{
			if (*it1 <= *it2)
			{
				merge.push_back(*it1);
				it1++;
			}
			else
			{
				merge.push_back(*it2);
				it2++;
			}
			i++;
		}

		if (it1 == nums1.end())
		{
			it1end = true;
		}

		if (it2 == nums2.end())
		{
			it2end = true;
		}

		if (step < i)
		{
			if (odd) return merge[step - 1];
			else return (merge[step - 1] + merge[step]) / 2.0;
		}
		else if (step == i)
		{
			if (odd) return merge[step - 1];
			else
			{
				if (it1end) return (merge[step - 1] + *it2) / 2.0;
				else return(merge[step - 1] + *it1) / 2.0;
			}
		}
		else
		{
			step = step - i;
			if (odd)
			{
				if (it1end) return *(it2 + step - 1);
				else return *(it1 + step - 1);
			}
			else
			{
				if (it1end) return (*(it2 + step - 1) + *(it2 + step)) / 2.0;
				else return (*(it1 + step - 1) + *(it1 + step)) / 2.0;
			}
		}
	}
};