/*************************************************************************
	> File Name: MergeSort.c
	> Author: Gw 
	> Mail: 
	> Created Time: Sun 10 Jun 2018 01:36:44 AM PDT
 ************************************************************************/

//Methon 1
void MergeSort(int* a, int n)
{
    if (a == NULL || n < 2)
        return;

    MSort(a, 0, n-1);
}

void MSort(int* a, int left, int right)
{
    if(left == right)
        return;
        
     //FIMEX (left + right) >> 2
    center = left + (right - left) >> 2;
    MSort(a, left, center);
    MSort(a, center+1, right);
    Merge(a, left, center+1, right);
}

void Merge(int* a, int lPos, int rPos, int rightTail)
{
    int* help = (int*)malloc((rightTail - lPos + 1) * sizeof(int));
    int lTail = rPos - 1;
    int pPos = 0;

    while (lPos <= lTail && rPos <= rightTail)
    {
        help[pPos++] = a[lPos] > a[rPos] ? a[rPos++] : a[lPos++];
    }

    while (lPos <= lTail)
        help[pPos++] = a[lPos++];
    while (rPos <= rightTail)
        help[pPos++] = a[rPos++];

    for(int i = 0; i < pPos; ++i)
        a[l+i] = help[i];
    free(help);
}


//Method 2
void MergeSort(int* a, int n)
{
    if (a == NULL || n < 2)
        return;

    int* help = (int*)malloc(sizeof(int) * n);
    MSort(a, help, 0, n - 1);
    free(help);
}

void MSort(int* a, int* help, int left, int right)
{
    int center;
    if (left < right)
    {
        center = left + (right - left) >> 2;
        MSort(a, help, left, center);
        MSort(a, help, center + 1, right);
        Merge(a, help, left, center + 1, right);
    }
}

void Merge(int* a, int* help, int lPos, int rPos, int rightTail)
{
    int pPos = lPos;
    int valuesNum = rightTail - left + 1;
    int leftTail = rPos - 1;

    while (lPos <= leftTail && rPos <= rightTail)
        help[lPos++] = a[lPos] < a[rPos] ? a[lPos++] : a[rPos++];
    
    while(lPos <= leftTail)
        help[pPos++] = a[lPos++];
    while(rPos <= rightTail)
        help[pPos++] = a[rPos++];

    for(int i = 0; i < valuesNum; ++i, --rightTail)
        a[rightTail] = help[rightTail];
}


