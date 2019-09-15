template<typename T>
class Singleton :: boost::noncopyable
{
public:
    static T& Instacne()
    {
        ::pthread_once(&ponce_, Singleton::Init);
        assert(instane_);
        return *instane_;
    }

private:
    Singleton() = default;
    ~Singleton() = default;

    static void Init()
    {
        instane_ = new T;
        ::atexit(Singleton::Destory);
    }

    static void Destory()
    {
        typedef char T_must_be_compelete_type[sizeof(T) == 0 ? -1 : 1];
        delete instane_;
        instane_ = nullptr;
    }

    static T* instane_;
    static pthread_once_t ponce_;
};

template<T>
T* Singleton<T>::instane_ = nullptr;

template<T>
pthread_once_t Singleton<T>::ponce_ = PTHEAD_ONCE_INIT
