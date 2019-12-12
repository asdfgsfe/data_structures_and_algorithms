class Foo {
public:
    Foo() {
        startTwo_ = false;
        startThree_ = false;
    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        startTwo_ = true;
    }

    void second(function<void()> printSecond) {
        while (!startTwo_)
        {
        }
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        startThree_ = true;
    }

    void third(function<void()> printThird) {
        while (!startThree_)
        {
        }
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
private:
    bool startTwo_;
    bool startThree_;
};