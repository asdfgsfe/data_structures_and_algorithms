vector<vector<int> > updateMatrix(vector<vector<int> >& matrix)
{
    int rows = matrix.size();
    if (rows == 0)
        return matrix;
    int cols = matrix[0].size();
    vector<vector<int> > dist(rows, vector<int>(cols, INT_MAX));
    queue<pair<int, int> > q;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (matrix[i][j] == 0) {
                dist[i][j] = 0;
                q.push({ i, j }); //Put all 0s in the queue.
            }

    int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int new_r = curr.first + dir[i][0], new_c = curr.second + dir[i][1];
            if (new_r >= 0 && new_c >= 0 && new_r < rows && new_c < cols) {
                if (dist[new_r][new_c] > dist[curr.first][curr.second] + 1) {
                    dist[new_r][new_c] = dist[curr.first][curr.second] + 1;
                    q.push({ new_r, new_c });
                }
            }
        }
    }
    return dist;
}

//���� 2�������������
//�뷨
//һ�ָ��õı�����
//��Ѱ��������̫�����˷ѣ��������ʹ�ù����������ȥ���������ռ䡣
//ֻҪ 0 �����ڹ����������ʱ�����Ǿ�֪����� 0 ������ġ���ˣ�ֻ��Ҫ������һ�� 1��
//�ٴο��ǣ�
//�������ַ����У�����ֻ�ܹ�����һ�� 1 �ľ��룬�������ĳ�̶ֳ��ϣ�����̶���߷��� 1 �ĸ��Ӷȡ�
//���ǣ�������Ǵ� 0 ��ʼ��������������Ҹ���·�������е� 1������Ż����ǵ��㷨��
//�㷨
//���ڹ����������������һ������ q ά����һ����Ҫ���ĵ㡣
//���ǽ����е� 0 ���� q �С�
//��ʼ�أ�����ÿ��Ϊ 0 �Ľڵ���붼�� 1���������е� 1 ���� INT_MAX������ݹ��ѵĽ�����¡�
//���������е�Ԫ�أ���������ھӡ�
//��������ھ� {i,j} �¼���ľ����С���� {i,j} ������� q ��ͬʱ���¾��� dist[i][j]��