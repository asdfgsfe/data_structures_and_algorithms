class H2O {
public:
    H2O() {
        
    }
    mutex mtx;
    condition_variable cvh,cvo;
    int ch,co;
    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> lck(mtx);
        while(ch>=2)
        {
            cvh.wait(lck);
        }
        ch++;
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        if(ch==1)
        {
            cvh.notify_one();
        }
        if(co==0) cvo.notify_one();
        if(ch==2&&co==1)
        {
            ch = 0,co = 0;
            cvh.notify_all();
            cvo.notify_all();
        }
        
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> lck(mtx);
        while(co>=1)
        {
            cvo.wait(lck);
        }
        co++;
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        if(ch<2)
        {
            cvh.notify_all();
        }
        if(ch==2&&co==1)
        {
            ch = 0,co = 0;
            cvh.notify_all();
            cvo.notify_all();
        }
    }
};