//354 ����˹�����ŷ�����
����һЩ����˿�Ⱥ͸߶ȵ��ŷ⣬��Ⱥ͸߶�����������ʽ (w, h) ���֡�
����һ���ŷ�Ŀ�Ⱥ͸߶ȶ�������ŷ���ʱ������ŷ�Ϳ��ԷŽ���һ���ŷ����ͬ����˹����һ����

�����������ж��ٸ��ŷ������һ�顰����˹���ޡ��ŷ⣨�����԰�һ���ŷ�ŵ���һ���ŷ����棩��

˵��:
��������ת�ŷ⡣

ʾ��:

����: envelopes = [[5,4],[6,4],[6,7],[2,3]]
���: 3 
����: ����ŷ�ĸ���Ϊ 3, ���Ϊ: [2,3] => [5,4] => [6,7]��

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.empty())
        {
            return 0;
        }  
        std::sort(envelopes.begin(), envelopes.end(), 
                  [](const auto& lhs, const auto& rhs) ->bool
                  {
                      if (lhs.front() != rhs.front())
                      {
                          return lhs.front() < rhs.front();
                      }
                      return lhs.back() > rhs.back();
                  });
        int maxEnv = 1;
        vector<int> dp(envelopes.size(), 0);
        dp[0] = 1;
        for (int i = 1; i < envelopes.size(); ++i)
        {
            dp[i] = 1;
            for(int j = i - 1; j >= 0; --j)
            {
                if (envelopes[i][1] > envelopes[j][1]) //����ط�Ҫע�� ����w�Ѿ���С�������� ֻ��Ҫѡ��h�����ľ���
                {
                    dp[i]  = std::max(dp[i], dp[j] + 1); 
                }
            }
            maxEnv = std::max(maxEnv, dp[i]);
        }
        return maxEnv;
    }
};

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.empty())
        {
            return 0;
        }  
        std::sort(envelopes.begin(), envelopes.end(), 
                  [](const auto& lhs, const auto& rhs) ->bool
                  {
                      if (lhs.front() != rhs.front())
                      {
                          return lhs.front() < rhs.front();
                      }
                      return lhs.back() > rhs.back();
                  });
        vector<int> ends(envelopes.size(), 0);
        ends[0] = envelopes[0][1]; //ends[i]��ʾ �����������Ϊi + 1ʱ��Ӧԭ�������Сֵ
        int right = 0;
        for (int i = 1; i < envelopes.size(); ++i)
        {
            int l = 0;
            int r = right;
            while (l <= r)
            {
                int m = (l + r) / 2;
                if (envelopes[i][1] > ends[m]) //�ҵ����һ��С�ڵ���envelopes[i][1]������
                {
                    //����ط�ʹ��m+1��������ĵط����� ����Ҫ��Ŀ��ֵ����һ��λ�� ����һ��λ�ò���
                    l = m + 1;
                }
                else
                {
                    r = m - 1;
                }
            }
            right = std::max(right, l);
            ends[l] = envelopes[i][1];
        }
        return right + 1; //ends[right]��ʾ����Ϊright + 1ʱ����������������� ����right + 1
    }
};
