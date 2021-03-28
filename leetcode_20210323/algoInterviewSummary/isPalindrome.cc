#include <iostream>
#include <string>

using std::string;

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty()) {
            return true;
        }
        int l = 0;
        int r = s.size() - 1;
        while (l <= r) {
            if (!IsBestChar(s[l])) {
                ++l;
                continue;
            }
            if (!IsBestChar(s[r])) {
                --r;
                continue;
            }
        	if (std::toupper(s[l]) != std::toupper(s[r])) {
            	return false;
			}
			++l;
            --r;
        }
        return true;
    }

    bool IsBestChar(char c) {
        if (c >= '0' && c <= '9') {
            return true;
        }
        if (c >= 'a' && c <= 'z') {
            return true;
        }
        return c >= 'A' && c <= 'Z';
    }
};

int main(void) {
	string s = "0P";
	Solution s1;
	std::cout << s1.isPalindrome(s) << std::endl;
	return 0;
}
