// 最长不重复子串
// 一遍for循环，用map<char, int> 标注s[i]出现的位置，本质思想是动态规划。

// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		map<char, int> cmap;
		int res = 0;
		int start = -1;
		int len = s.size();
		for (int i = 0; i<len; i++)
		{
			if (cmap.find(s[i]) != cmap.end())
			{
				start = max(start, cmap[s[i]]);
			}
			res = max(res, i - start);
			cmap[s[i]] = i;
		}

		return res;
	}
};