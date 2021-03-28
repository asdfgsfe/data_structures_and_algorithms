class Solution {
public:
    bool validUtf8(vector<int>& data) {
        if (data.empty())
        {
            return false;
        }
        if (data.size() == 1)
        {
            return (data[0] & 0x80) == 0;
        }
        for (int i = 0; i < data.size(); ++i) 
		{
            //表示占一个字节 第一位为0 必然是utf8的正确格式跳过
            if (data[i] < 0b10000000) 
			{
                continue;
            } 
			int n = 0;
			int base = 0x80;
			while (data[i] & base)
			{
				++n;
				base >>= 1; //fix 如果这里是负数data[i] & base 就永远是1了 但是自己指定了数字是正数
            }
            if (:qa == 1 || n > 4)
			{
				return false;
			}
            for (int j = i + 1; j < i + n && j < data.size(); ++j) 
			{
                //if (data[j] > 0b10111111 || data[j] < 0b10000000) return false;
				if ((data[j] & 0x80) != 0x80 || (data[j] & 0x40) != 0)
				{
					return false;
				}
            } 
            i += n - 1;
        }
        return true;
    }
};

