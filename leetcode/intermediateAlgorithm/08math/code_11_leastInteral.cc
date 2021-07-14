 class Solution {
 public:
     int leastInterval(vector<char>& tasks, int n) {
         if (tasks.empty())
         {
		    return 0;
		 }
		 if (n < 1)
		 {
			 return tasks.size();
		 }
		 vector<int> times(26, 0);
		 for (int i = 0; i < tasks.size(); ++i)
		 {
			 ++times[tasks[i] - 'A'];
		 }
         //很明显出现次数最多的字符决定了等待的次数
         std::sort(times.begin(), times.end());
         //执行完我最长的时间为 我的个数+我之间的间隔 
         //对于个数小于我的 完全可以穿插到我的间隔中去执行，执行的耗时就是我间隔需要等待的时间
         //所以这个公式全部算完了个数小于的执行完所花费的时间
		 int time = (times.back() - 1) * (n + 1) + 1;
		 for (int i = times.size() - 2; i >= 0 && times[i] > 0; --i)
		 {
             //如果个数和我相等 而我只能在我的间隔中去执行他，我的间隔比我小1个，所以最后还要执行一次他 这里+1
		    if (times[i] == times.back())
            {
                ++time;
            }
		 }
		 return time > tasks.size() ? time : tasks.size();
	 }
 };
