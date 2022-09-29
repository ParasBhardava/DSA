/*
There is one meeting room in a firm. There are N meetings in the form of (startTime[i], finishTime[i])
What is the maximum number of meetings that can be accomodated in the meeting room ?
Also note that start time of one chosen meeting can't be equal to the end time of the other choden meeting. 
*/

#include<bits/stdc++.h>
using namespace std;

struct meeting 
{
    int start;
    int end;
    int pos;
};

bool compare(meeting m1, meeting m2)
{
    if(m1.end < m2.end)
        return true;

    else if(m1.end > m2.end)
        return false;

    else if(m1.pos < m2.pos)
        return true;

    return false;
}

void maxMeetings(int startTime[], int finishTime[], int n)
{
    struct meeting meet[n];
    for(int i = 0; i < n; i++)
    {
       meet[i].start = startTime[i];
       meet[i].end = finishTime[i];
       meet[i].pos = i+1; 
    }

    sort(meet, meet+n, compare);
    vector<int>ans;

    int limit = meet[0].end;
    ans.push_back(meet[0].pos);

    for(int i = 1; i < n; i++)
    {
        if(meet[i].start > limit)
        {
            limit = meet[i].end;
            ans.push_back(meet[i].pos);
        }
    }

    for(int i = 0; i < ans.size(); i++)
        cout<<ans[i]<<" ";
}

int main()
{
    int n = 6;
    int startTime[] = {1, 3, 0, 5, 8, 5};
    int finishTime[] = {2, 4, 6, 7, 9, 9};

    maxMeetings(startTime, finishTime, n);

    return 0;
}