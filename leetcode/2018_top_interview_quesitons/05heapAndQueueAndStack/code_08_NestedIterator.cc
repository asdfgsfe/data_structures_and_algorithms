class NestedIterator {
private:
    stack<NestedInteger> stk;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (auto iter = nestedList.rbegin(); iter != nestedList.rend(); iter++) {
            stk.push(*iter);
        }
    }

    int next() {
        NestedInteger nestedInteger = stk.top();
        stk.pop();
        return nestedInteger.getInteger();
    }

    bool hasNext() {
        while (!stk.empty()) {
            NestedInteger current = stk.top();
            if (current.isInteger()) return true;
            stk.pop();
            vector<NestedInteger> nestedList = current.getList();
            for (auto iter = nestedList.rbegin(); iter != nestedList.rend(); iter++) {
                stk.push(*iter);
            }
        }
        return false;
    }
};


//递归 但是这种方法不好
class NestedIterator {
private:
    deque<int> dq;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        flatten(nestedList);
    }
    
    void flatten(const vector<NestedInteger> &nestedList) {
        for (const NestedInteger &e : nestedList) {
            if (e.isInteger()) {
                dq.push_back(e.getInteger());
            } else {
                flatten(e.getList());
            }
        }
    }
    
    int next() {
        int data = dq.front();
        dq.pop_front();
        return data;
    }
    
    bool hasNext() {
        return !dq.empty();
    }
};