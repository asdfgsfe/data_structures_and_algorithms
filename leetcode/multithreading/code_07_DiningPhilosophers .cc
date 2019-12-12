//ѧ������ϵͳ�γ̵�ͬѧ��֪�������Ŀ���ο���
//�ܹ������ְ취���Ա��������ķ�����
//�޶���ѧ�ҾͲ�����;


//1
class Semaphore {
public:
  Semaphore(int count = 0) : count_(count) {
  }
    
  void Set(int count){
      count_ = count;
  }
    
  void Signal() {
    std::unique_lock<std::mutex> lock(mutex_);
    ++count_;
    cv_.notify_one();
  }

  void Wait() {
    std::unique_lock<std::mutex> lock(mutex_);
    while(count_ <= 0){
        cv_.wait(lock);
    }
    --count_;
  }

private:
  std::mutex mutex_;
  std::condition_variable cv_;
  int count_;
};

class DiningPhilosophers {
public:
    DiningPhilosophers() {
        guid.Set(4);
    }
    
    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        int l = philosopher;
        int r = (philosopher+1)%5;
        guid.Wait();        
        
        lock[l].lock();
        lock[r].lock();
        pickLeftFork();
        pickRightFork();
        eat();
        putRightFork();
        putLeftFork();
        lock[r].unlock();
        lock[l].unlock();
        
        guid.Signal();
    }
private:
    std::mutex lock[5];
    Semaphore guid;
};


//2 ͬʱ̧�������ò��� 
class DiningPhilosophers {
public:
    DiningPhilosophers() {
    }
    
    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        int l = philosopher;
        int r = (philosopher+1)%5;
        guid.lock();        
        lock[l].lock();
        lock[r].lock();
        pickLeftFork();
        pickRightFork();
        guid.unlock();
        eat();
        putRightFork();
        putLeftFork();
        lock[l].unlock();
        lock[r].unlock();
    }
private:
    std::mutex lock[5];
    std::mutex guid;
};

//3 �Լ��Ӹ����� ������ѧ�Ҵ�������� ż����ѧ�����Һ���
//�޶��ͲͲ��ԣ�
class DiningPhilosophers {
public:
    DiningPhilosophers() {
    }
    
    void wantsToEat(int philosopher,
                    function<void()> pickLeftFork,
                    function<void()> pickRightFork,
                    function<void()> eat,
                    function<void()> putLeftFork,
                    function<void()> putRightFork) {
        int l = philosopher;
        int r = (philosopher+1)%5;
        if(philosopher%2 == 0){
            lock[r].lock();
            lock[l].lock();
            pickLeftFork();
            pickRightFork();
        }else{
            lock[l].lock();
            lock[r].lock();
            pickLeftFork();
            pickRightFork();
        }
        
        eat();
        putRightFork();
        putLeftFork();
        lock[l].unlock();
        lock[r].unlock();
    }
private:
    std::mutex lock[5];
};