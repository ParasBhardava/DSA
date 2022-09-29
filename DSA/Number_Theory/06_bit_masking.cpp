// Consider this problem: There are N≤5000 workers. Each worker is available during some days of this month (which has 30 days). For each worker, you are given a set of numbers, each from interval [1,30], representing his/her availability. You need to assign an important project to two workers but they will be able to work on the project only when they are both available. Find two workers that are best for the job — maximize the number of days when both these workers are available.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n; // no of workers

    vector<int> masks(n);
    for (int i = 0; i < n; i++)
    {
        int days; // no of working days of a worker
        cin >> days;
        int mask = 0;
        for (int j = 0; j < days; j++)
        {
            int day;
            cin >> day;
            mask = (mask | (1 << day));
        }
        masks[i] = mask;
    }

    int maxDays = 0, person1 = -1, person2 = -1;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int intersection = (masks[i] & masks[j]);
            int commomDays = __builtin_popcount(intersection);

            // scout << i << " " << j << " " << commomDays << "\n";

            if (commomDays > maxDays)
            {
                maxDays = commomDays;
                person1 = i;
                person2 = j;
            }
        }
    }

    cout << "Person1 " << person1 << " Pearson2 " << person2 << " Max intersection " << maxDays << "\n";

    return 0;
}