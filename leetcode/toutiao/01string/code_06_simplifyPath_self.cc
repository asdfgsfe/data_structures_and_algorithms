class Solution {
public:
    string simplifyPath(string path) {
        if (path.empty()) {
            return "";
        }
        deque<string> dirs;
        int n = 0;
        int p = 0;
        while (n < path.size()) {
            while (n < path.size() && path[n] != '/') {
                ++n;
            }
            if (n == p) {
                while (n < path.size() && path[n] == '/') {
                    ++n;
                }
                p = n;
                continue;
            }
            string dir = path.substr(p, n - p);
            if (dir == "..") {
                if (!dirs.empty()) {
                    dirs.pop_back();
                }
            } else if (dir != ".") {
                dirs.push_back(dir);
            }
            p = n;
        }
        string perfPath("/");
        while (!dirs.empty()) {
            perfPath += dirs.front();
            dirs.pop_front();
            if (!dirs.empty()) {
                perfPath.push_back('/');
            }
        }
        return perfPath;
    }
};
//71. 简化路径
//双指针大法
