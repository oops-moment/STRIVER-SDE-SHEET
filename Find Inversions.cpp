#include <bits/stdc++.h> 

int inversionCount = 0;

void merge(long long *arr, int low, int mid, int high)
{
    std::vector<long long> temp;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            inversionCount += (mid - left + 1);
            temp.push_back(arr[right]);
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void mergeSort(int low, int high, long long *arr)
{
    if (low >= high)
    {
        return;
    }

    int mid = low + (high - low) / 2;
    mergeSort(low, mid, arr);
    mergeSort(mid + 1, high, arr);
    merge(arr, low, mid, high);
}

long long getInversions(long long *arr, int n)
{
    mergeSort(0, n - 1, arr);
    return inversionCount;
}
