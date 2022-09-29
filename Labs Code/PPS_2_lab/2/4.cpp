#include <iostream>
using namespace std;

struct amount
{
    int denomination;
    int coins;
};

int main()
{

    int num, paid_amount, my_amount = 0, count = 0, result, diff;

    cin >> num;
    amount arr[num], sol_arr[num];
    for (int i = 0; i < num; i++)
        cin >> arr[i].denomination >> arr[i].coins;

    cin >> paid_amount;

    for (int i = 0; i < num - 1; i++)
    {
        for (int j = i + 1; j < num; j++)
        {
            if (arr[j].denomination > arr[i].denomination)
            {
                amount temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }

    for (int i = 0; i < num; i++)
    {
        diff = paid_amount - my_amount;

        if (diff < arr[i].denomination)
            continue;

        result = diff / arr[i].denomination;

        if (result <= arr[i].coins)
            sol_arr[count].coins = result;

        else
            sol_arr[count].coins = arr[i].coins;

        sol_arr[count].denomination = arr[i].denomination;
        my_amount += (sol_arr[count].denomination * sol_arr[count].coins);
        count++;

        if (my_amount == paid_amount)
            break;
    }

    if (my_amount == paid_amount)
    {
        cout << count << endl;
        for (int i = 0; i < count; i++)
            cout << sol_arr[i].denomination << " " << sol_arr[i].coins << endl;
    }

    else
        cout << "-1";

    return 0;
}