//https://www.cnblogs.com/latup/p/10205316.html
#include <iostream>                                                   
#include <vector>

using std::vector;
int CompleteProcess(const vector<int>& time, int i, int artist, int&);

int MinTimeCompletePicture(const vector<int>& time, int artist)
{
    if (time.empty() || artist < 1)
    {
      return 0;
    }
    int minTime = 0x7fffffff;
    CompleteProcess(time, 0, artist, minTime);
    return minTime;
}
int CompleteProcess(const vector<int>& time, int i, int artist, int& minTime)
{
    if (i == time.size() -  1)
    {
      //minTime = std::min(minTime, time[0]);
      return time[0];
    }
    if (artist == 1)
    {
      int tailTime = 0;
      for (int k = i; k < time.size(); ++k)
      {
        tailTime += time[k];
      }
      //minTime = std::min(minTime, tailTime);
      return tailTime;
    }
    int endTime = 0x80000000;
    for (int s = 0; s < time.size(); ++s)
    {
      int nextTime = CompleteProcess(time, i + s, artist - 1, minTime);
      int curTime = 0;
      for (int j = i; j < i + s; ++j)
      {
        curTime += time[j];
      }
      endTime = std::max(nextTime, curTime);
      minTime = std::min(endTime, minTime);

      std::cout << "nextTime=" << nextTime << " i=" << i << " curTime=" << curTime   
               << " minTime=" << minTime << " artist=" << artist <<std::endl;
    }
    return endTime;
}

//´íÎóµÄ·½·¨ 
int main(void)
{
  vector<int> time = {3, 1, 4};
  std::cout << MinTimeCompletePicture(time, 4) << std::endl;


  time = {1, 1, 1, 4, 3};
  //std::cout << MinTimeCompletePicture(time, 3) << std::endl;


  time = {1, 1, 1, 4, 3};
  //std::cout << MinTimeCompletePicture(time, 4) << std::endl;
  
  time = {1, 1, 1, 4, 3};
  //std::cout << MinTimeCompletePicture(time, 6) << std::endl;
  
  time = {1, 1, 1, 4, 3};
  //std::cout << MinTimeCompletePicture(time, 6) << std::endl;
}                                                             