// ��ת����
// ��string�����ͼ���
// ֱ�Ӳ���ȡ�����10�����ۼ�
// ע��try catch��ʹ��

// https://leetcode.com/problems/reverse-integer/description/
class Solution {
public:
	int reverse(int x) {
		if (x == 0) return x;

		bool neg = x<0 ? true : false;
		string a = to_string(abs(x));
		string b = "";
		for (int i = 0; i<a.size(); i++)
		{
			b += a[a.size() - 1 - i];
		}

		int i = 0;
		while (b[i] == '0')
		{
			i++;
		}

		int r = 0;
		try {
			r = stoi(b.substr(i));
		}
		catch (std::out_of_range)
		{
			r = 0;
		}

		//int r = stoi(b.substr(i));
		return (neg ? -r : r);
	}
};