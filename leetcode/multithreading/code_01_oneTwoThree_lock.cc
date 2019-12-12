class Foo {
public:
    Foo() 
		: startTwo_(0),
		  startThree_(0),
		  mutex_(PTHREAD_MUTEX_INITIALIZER),
		  two_(PTHREAD_COND_INITIALIZER),
		  three_(PTHREAD_COND_INITIALIZER)
	{
        
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
		pthread_mutex_lock(&mutex_);
		startTwo_ = 1;
		pthread_cond_signal(&two_);
		pthread_mutex_unlock(&mutex_);
    }

    void second(function<void()> printSecond) {
        pthread_mutex_lock(&mutex_);
		while (startTwo_ == 0)
		{
			pthread_cond_wait(&two_, &mutex_);
		}
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
		startThree_ = 1;
		pthread_cond_signal(&three_);
		pthread_mutex_unlock(&mutex_);
    }

    void third(function<void()> printThird) {
        pthread_mutex_lock(&mutex_);
		while (startThree_ == 0)
        {
			pthread_cond_wait(&three_, &mutex_);
        }
		pthread_mutex_unlock(&mutex_);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }

private:
	int startTwo_;
	int startThree_;
	pthread_mutex_t mutex_;
	pthread_cond_t two_;
	pthread_cond_t three_;
};