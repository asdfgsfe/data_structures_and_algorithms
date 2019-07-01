void BubbleSort(int *a , int n)
{
    if (a == NULL || n < 2)
        return;

    for (int i = n-1; i > 0; --i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (a[j] > a[j+1])
                swap(a[j], a[j+1]);
        }
    }
}


void SelectorSort(int *a, int n)
{
    if (a == NULL || n < 2)
        return;

    for (int i = 0; i < n; ++i)
    {
        int minId = 0;
        for (int j = i + 1; j < n; ++j)
        {
            minId = a[minId] > a[j] ? j : minId;
        }
        swap(a[i], a[minId]);
    }

}

