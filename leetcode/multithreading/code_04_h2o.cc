class H2O {
private:
    int countOxygen;
    pthread_mutex_t lockHy;
    pthread_mutex_t lockOx;
public:
    H2O() {
        pthread_mutex_init(&lockHy, NULL);
        pthread_mutex_init(&lockOx, NULL);
        pthread_mutex_lock(&lockOx);
        this->countOxygen = 2;
    }

	//想象成主动调用这个函数
    void hydrogen(function<void()> releaseHydrogen) {
        pthread_mutex_lock(&lockHy);
        releaseHydrogen();
        this->countOxygen--;
        if(this->countOxygen > 0){
           pthread_mutex_unlock(&lockHy);
        }else{
           pthread_mutex_unlock(&lockOx); 
        }
    }
    void oxygen(function<void()> releaseOxygen) {
        pthread_mutex_lock(&lockOx);
        releaseOxygen();
        this->countOxygen = 2;
        pthread_mutex_unlock(&lockHy);
    }
};

//选择一个计算counter计算，counter每次初始化为2.
//当counter > 0时，则选择控制执行hydrogen函数，当counter = 0时，则选择控制执行oxygen函数。
//在hydrogen函数内部每次将counter进行减一操作；
//在oxygen函数内部每次将counter初始化为2；