class FooBar {
private:
    int n;
    int startFoo_;
    int startBar_;
    pthread_mutex_t mutex_;
    pthread_cond_t foo_;
    pthread_cond_t bar_;

public:
    FooBar(int n) {
        this->n = n;
        startFoo_ = 1;
        startBar_ = 0;
        mutex_ = PTHREAD_MUTEX_INITIALIZER;
        foo_ = PTHREAD_COND_INITIALIZER;
        bar_ = PTHREAD_COND_INITIALIZER;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            pthread_mutex_lock(&mutex_);
        	while (!startFoo_)
            {
                pthread_cond_wait(&foo_, &mutex_);
            }
            // printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            startFoo_ = 0;
            startBar_ = 1;
            pthread_cond_signal(&bar_);
            pthread_mutex_unlock(&mutex_);
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            pthread_mutex_lock(&mutex_);
            while (!startBar_)
            {
                pthread_cond_wait(&bar_, &mutex_);
            }
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            startBar_ = 0;
            startFoo_ = 1;
            pthread_cond_signal(&foo_);
            pthread_mutex_unlock(&mutex_);
        }
    }
};