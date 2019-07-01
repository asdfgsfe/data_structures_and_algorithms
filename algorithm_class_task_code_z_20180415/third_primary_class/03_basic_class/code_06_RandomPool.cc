#include <cassert>

#include <iostream>
#include <map>
#include <random>
#include <functional>
#include <algorithm>
#include <string>
#include <iterator>

using namespace std;
//template <typename T>
class RandomPool
{
public:
    RandomPool()
        : size_(0)
    {

    }

    void Insert(const std::string& key)
    {
        //keyIndexMap_.insert(std::make_pair<std::string, int>(key, size_));;
        //indexKeyMap_.insert(std::make_pair<int, std::string>(size_, key));;
        ++size_;
    }

    bool Delete(const std::string& key)
    {
        std::map<std::string, int>::iterator it1;
        std::map<int, std::string>::iterator it2;
        it1 = keyIndexMap_.find(key);
        if (it1 != keyIndexMap_.end())
        {
            std::map<std::string, int>::reverse_iterator rIt1 = keyIndexMap_.rbegin();
            std::map<int, std::string>::reverse_iterator rIt2 = indexKeyMap_.rbegin();

            it2 = indexKeyMap_.find(it1->second);
            assert(it2 != indexKeyMap_.end());
            it2->first = rIt2->first;
            it2->second = rIt2->second;
            //indexKeyMap_.erase(rIt2);

            //std::swap(it1->first, rIt1->first);
            //std::swap(it1->second, rIt1->second);
            //keyIndexMap_.erase(rIt1);
            --size_;

            return true;
        }

        return false;
    }

    bool GetRandom(std::string& key)
    {
        if (size_ == 0)
            return false;

        //std::default_random_engine generator;
        //std::uniform_int_distribution<int> dis(0, size_); 
        //auto dice = std::bind(dis,generator);

        //key = indexKeyMap_[dice];
        return true;
    }

private:
    int size_;
    std::map<std::string, int> keyIndexMap_;
    std::map<int, std::string> indexKeyMap_;
};


int main(void)
{
    RandomPool pool;
    pool.Insert("main");
    pool.Insert("ramdom");
    pool.Insert("pool");

    std::string key;
    pool.GetRandom(key);
    std::cout << key << std::endl;

    pool.GetRandom(key);
    std::cout << key << std::endl;

    pool.GetRandom(key);
    std::cout << key << std::endl;

    pool.Delete("random");

    pool.GetRandom(key);
    std::cout << key << std::endl;

    return 0;
}
