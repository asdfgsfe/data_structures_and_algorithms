static auto _____ = []()
{
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	return 0;
}();
class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> res;
        int indexSum = 2001;
        unordered_map<string, int> map;
        for(int i = 0; i < list1.size(); i++){
            map[list1[i]] = i;
        }
        for(int i = 0; i < list2.size(); i++){
            if(map.find(list2[i]) != map.end()){
                if(i + map[list2[i]] <= indexSum){
                    if(i + map[list2[i]] < indexSum){
                        res.clear();
                    }
                    indexSum = i + map[list2[i]];
                    res.push_back(list2[i]);
                } 
            }
        }
        return res;
    }
};