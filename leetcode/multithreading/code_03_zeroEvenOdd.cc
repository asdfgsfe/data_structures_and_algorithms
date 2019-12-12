class ZeroEvenOdd {
private:
    int n;
    int cur_;
    int startZero_;
    int startEven_;
    int startOdd_;
    pthread_mutex_t mutex_;
    pthread_cond_t zero_;
    pthread_cond_t even_;
    pthread_cond_t odd_;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        cur_ = 0;
        startZero_ = 1;
        startEven_= 0;
        startOdd_ = 0;
        mutex_ = PTHREAD_MUTEX_INITIALIZER;
        zero_ = PTHREAD_COND_INITIALIZER;
        even_ = PTHREAD_COND_INITIALIZER;
        odd_ = PTHREAD_COND_INITIALIZER;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        for (int i = 0; i < n; ++i)
        {
            pthread_mutex_lock(&mutex_);
            while (!startZero_)
            {
                pthread_cond_wait(&zero_, &mutex_);
            }
            startZero_ = 0;
            printNumber(0);
            if (++cur_ % 2 == 0)
            {
                startEven_ = 1;
                pthread_cond_signal(&even_);
            }
            else
            {
                startOdd_ = 1;
                pthread_cond_signal(&odd_);
            }
            pthread_mutex_unlock(&mutex_);
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 0; i < n / 2; ++i)
        {
            pthread_mutex_lock(&mutex_);
            while (!startEven_)
            {
                pthread_cond_wait(&even_, &mutex_);
            }
            startEven_ = 0;
            printNumber(cur_);
            startZero_ = 1;
            pthread_cond_signal(&zero_);
            pthread_mutex_unlock(&mutex_);
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 0; i < n; i += 2)
        {
            pthread_mutex_lock(&mutex_);
            while (!startOdd_)
            {
                pthread_cond_wait(&odd_, &mutex_);
            }
            startOdd_ = 0;
            printNumber(cur_);
            startZero_ = 1;
            pthread_cond_signal(&zero_);
            pthread_mutex_unlock(&mutex_);
        }
    }
};