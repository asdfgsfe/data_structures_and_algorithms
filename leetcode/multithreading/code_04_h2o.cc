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

	//��������������������
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

//ѡ��һ������counter���㣬counterÿ�γ�ʼ��Ϊ2.
//��counter > 0ʱ����ѡ�����ִ��hydrogen��������counter = 0ʱ����ѡ�����ִ��oxygen������
//��hydrogen�����ڲ�ÿ�ν�counter���м�һ������
//��oxygen�����ڲ�ÿ�ν�counter��ʼ��Ϊ2��