/*************************************************************************
	> File Name: insertionSort.c
	> Author: Gw
	> Mail: 
	> Created Time: Sun 10 Jun 2018 12:42:04 AM PDT
 ************************************************************************/


//Method 1
void InsertionSort(int* a, int n)
{
    if (a == NULL || n < 2)
        return ;

    for (int p = 1; p < n; ++p)
    {
        int tmp = a[p];
        for (int i = p; i > 0 && a[i-1] > tmp; --j)
            a[i] = a[i-1];
        a[i] = tmp;
    }
}

//Methon 2
void insertionSort(int* a, int n)
{
    if (a == NULL || n < 0)
        return ;

    for(int p = 1; p < n; ++p)
    {
        for(int j = p-1; j >= 0 && a[j] > a[j+1]; --j)
            swap(a[j], a[j+1]);
    }
}















