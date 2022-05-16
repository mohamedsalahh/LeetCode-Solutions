class Solution
{
public:
    void shuffle(vector<int> &arr, int n)
    {
        for (int i = 0; i < n; ++i)
        {
            int r = rand() % (i + 1);
            swap(arr[i], arr[r]);
        }
    }

    int partition(vector<int> &arr, int lo, int hi)
    {
        int i = lo, j = hi + 1;

        while (true)
        {
            while (arr[++i] <= arr[lo])
                if (i == hi)
                    break;

            while (arr[--j] >= arr[lo])
                if (j == lo)
                    break;

            if (i >= j)
                break;

            swap(arr[i], arr[j]);
        }

        swap(arr[lo], arr[j]);
        return j;
    }
    void quickSort(vector<int> &arr, int lo, int hi)
    {
        if (lo >= hi)
            return;

        int j = partition(arr, lo, hi);
        quickSort(arr, lo, j - 1);
        quickSort(arr, j + 1, hi);
    }
    vector<int> sortArray(vector<int> &nums)
    {
        shuffle(nums, nums.size());
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};