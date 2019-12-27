public class Solution {
    public int leastInterval(char[] tasks, int n) {
        int[] map = new int[26];
        for (char c: tasks)
            map[c - 'A']++;
        PriorityQueue < Integer > queue = new PriorityQueue < > (26, Collections.reverseOrder());
        for (int f: map) {
            if (f > 0)
                queue.add(f);
        }
        int time = 0;
        while (!queue.isEmpty()) {
            int i = 0;
            List < Integer > temp = new ArrayList < > ();
            while (i <= n) {
                if (!queue.isEmpty()) {
                    if (queue.peek() > 1)
                        temp.add(queue.poll() - 1);
                    else
                        queue.poll();
                }
                time++;
                if (queue.isEmpty() && temp.size() == 0)
                    break;
                i++;
            }
            for (int l: temp)
                queue.add(l);
        }
        return time;
    }
}

//���ߣ�LeetCode
//���ӣ�https://leetcode-cn.com/problems/task-scheduler/solution/ren-wu-diao-du-qi-by-leetcode/
//��ѡ��ÿһ���е�����ʱ������Ҳ���������ȶ��У��ѣ�����������
//��һ��ʼ�����ǰ����е�������뵽���ȶ����С�
//��ÿһ�֣����Ǵ����ȶ�����ѡ����� n + 1 �����񣬰����ǵ�������ȥ 1��
//�ٷŻض��У����������Ϊ 0����ֱ����Ϊ�ա�
