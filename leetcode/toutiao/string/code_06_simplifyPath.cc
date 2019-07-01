��·��
�� Unix ������һ���ļ��ľ���·��������Ҫ���������߻��仰˵������ת��Ϊ�淶·����

�� Unix �����ļ�ϵͳ�У�һ���㣨.����ʾ��ǰĿ¼�������⣬������ ��..�� ��ʾ��Ŀ¼�л�����һ����ָ��Ŀ¼����
���߶������Ǹ������·������ɲ��֡�������Ϣ����ģ�Linux / Unix�еľ���·�� vs ���·��

��ע�⣬���صĹ淶·������ʼ����б�� / ��ͷ����������Ŀ¼��֮�����ֻ��һ��б�� /�����һ��Ŀ¼����������ڣ������� / ��β��
���⣬�淶·�������Ǳ�ʾ����·��������ַ�����

 

ʾ�� 1��

���룺"/home/"
�����"/home"
���ͣ�ע�⣬���һ��Ŀ¼������û��б�ܡ�
ʾ�� 2��

���룺"/../"
�����"/"
���ͣ��Ӹ�Ŀ¼����һ���ǲ����еģ���Ϊ��������Ե������߼���
ʾ�� 3��

���룺"/home//foo/"
�����"/home/foo"
���ͣ��ڹ淶·���У��������б����Ҫ��һ��б���滻��
ʾ�� 4��

���룺"/a/./b/../../c/"
�����"/c"
ʾ�� 5��

���룺"/a/../../b/../c//.//"
�����"/c"
ʾ�� 6��

���룺"/a//b////c/d//././/.."
�����"/a/b/c"

//���и��Ž� �ռ临�Ӷ�Ϊ1
//ע�� ... ...xxxxx ���ǺϷ���unix·�� ֻ��. .. ��������·��
class Solution {
public:
    string simplifyPath(string path) {
		if (path.empty())
		{
			return string();
		}
		deque<string> paths;
		int i = 0;
		while (i < path.size())
		{
			while (i < path.size() && path[i] == '/')
			{
				++i;
			}
			string subPath;
			while (i < path.size() && path[i] != '/')
			{
				subPath.append(1, path[i++]);
			}
			if (subPath == ".." && !paths.empty())
			{
				paths.pop_back();
			}
			if (!subPath.empty() && subPath != "." && subPath != "..")
			{
				paths.push_back(subPath);
			}
        }
        if (paths.empty())
        {
            return "/";
        }
        string res("/");
		while (!paths.empty())
		{
			res.append(paths.front()).append("/");
			paths.pop_front();
		}
		return res.substr(0, res.size() - 1);
    }
};