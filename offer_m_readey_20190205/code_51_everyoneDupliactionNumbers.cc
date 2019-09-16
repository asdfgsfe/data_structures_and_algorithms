class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        if (!numbers || length < 2 || !duplication)
        {
            return false;
        }
        for (int i = 0; i < length; ++i)
        {
            if (numbers[i] < 0 || numbers[i] >= length)
            {
                return false;
            }
        }
        int l = 0;
        while (l < length)
        {
            if (numbers[l] == l)
            {
                ++l;
            }
            else if (numbers[l] != numbers[numbers[l]])
            {
                std::swap(numbers[l], numbers[numbers[l]]);
            }
            else
            {
                *duplication = numbers[l];
                return true;
            }
        }
        return false;
    }
};
