vector<int> temp;
    temp.push_back(arr[lastIdx]);
    while (hash[lastIdx] != lastIdx)
    {
        lastIdx = hash[lastIdx];
        temp.push_back(arr[lastIdx]);
    }