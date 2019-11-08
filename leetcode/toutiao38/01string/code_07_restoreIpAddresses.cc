//��ԭIP��ַ
//����һ��ֻ�������ֵ��ַ�������ԭ�����������п��ܵ� IP ��ַ��ʽ��

//ʾ��:

//����: "25525511135"
//���: ["255.255.11.135", "255.255.111.35"]


class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
      if (s.size() < 4 || s.size() > 4 * 3)
      {
        return vector<string>();
      }
	  vector<string> ips;
	  string ip;
	  RestoreProcess(s, 0, 4, ip, ips);
      return ips;
    }

    void RestoreProcess(const string& str, int i, int aim, string ip, vector<string>& ips)
    {
		if (aim == 0 && i == str.size())
		{
			ips.emplace_back(ip.substr(0, ip.size() - 1));
			return;
		}
		if (aim == 0 || i == str.size())
		{
			return;
		}
		for (int s = 1; s <= 3; ++s)
		{
			if (IsLegalIp(str, i, i + s))
			{
				const string& curIp = str.substr(i, s) + ".";
				RestoreProcess(str, i + s, aim - 1, ip + curIp, ips);
			}
		}
    }

	bool IsLegalIp(const string& str, int l, int r)
	{
		if (l < 0 || l > r || r < 0 || r > str.size())
		{
			return false;
		}
        int len = r - l;
        if (len > 1 && str[l] == '0')
        {
            return false;
        }
		int num = ::atoi(str.substr(l, len).c_str());
		return num >= 0 && num <= 255;
	}
};