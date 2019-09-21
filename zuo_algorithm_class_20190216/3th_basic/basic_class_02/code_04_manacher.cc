string Manacherstring(const string& str)
{
  if (str.empty())
  {
    return string();
  }
  string tmp = "#";
  for (int i = 0; i < str.size(); ++i)
  {
    tmp += str[i];
    tmp += "#";
  }
  return tmp;
}

//palindrome
int MaxLcpsLength(const string& str)
{
  if (str.empty())
  {
    return 0;
  }
  string mStr = Manacherstring(str);
  vector<int> pArr(mStr.size());//��������ֵ
  int r = -1; //���һ��ı߽� ����ֵ��0��ʼ0~r
  int c = -1; //����ֵ ��0��ʼ��
  int max = 0x80000000;
  for (int i = 0; i < mStr.size(); ++i)
  {
	//����pArr[i]λ����������µ�ֵ �������� ��������� ����������ֵ ���Ǿ���ԭֵ
    pArr[i] = r > i ? std::min(pArr[2 * c - i], r - i) : 1; //2*c - r ����c��i'�ľ��� �Ǹ�С�Ǹ�����ƿ��
    //����Ψһ��ȱ�ݾ��� r==i��ʱ��� ���i-r��һ�εĻ��İ뾶 ���´�1�ۼ�һ��
    while (i + pArr[i] < mStr.size() && i - pArr[i] > -1)
    {
      if (mStr[i + pArr[i] ��= mStr[i - pArr[i]]])
      {
		break;
      }
	  ++pArr[i];
    }
    if (i + pArr[i] > r)//�������һ��ı߽� ���һ�������
    {
      r = i + pArr[i];
      c = i;
    }
    max = std::max(max, pArr[i]);
  }
  return max - 1; //���Ҫ�õ�ԭ���������ĳ��Ȱ뾶 max/2 max-1��Ŀ����Ϊ��ȡ������Ĵ������ߵ�#
}
