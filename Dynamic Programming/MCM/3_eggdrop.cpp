// Egg Dropping Problem
// Minimum Number of Attempts (in *Worst Case) for dropping of Eggs from the Floors
// Problem :- Find the Critical Floor/Threshold Floor (at which the egg breaks) in Minimum No. of Attempts

#include <bits/stdc++.h>
using namespace std;

int eggDrop(int e, int f) // e = egg, f = floor
{
    if (f == 0 || f == 1)
        return f;
    if (e == 1)
        return f;

    int mini = INT_MAX;
    for (int k = 1; k <= f; k++)
    {
        int tempans = 1 + max(eggDrop(e - 1, k - 1), eggDrop(e, f - k));
        //     attempts + worst_case(egg break, egg does't break)
        mini = min(mini, tempans);
    }
    return mini;
}
int egg_Drop(int e, int f) // e = egg, f = floor
{
    int tab[e + 1][f + 1];
    memset(tab, -1, sizeof(tab));

    if (f == 0 || f == 1)
        return f;

    if (e == 1)
        return f;

    if (tab[e][f] != -1)
        return tab[e][f];

    int mini = INT_MAX;
    for (int k = 1; k <= f; k++)
    {
        int tempans = 1 + max(egg_Drop(e - 1, k - 1), egg_Drop(e, f - k));
        //     attempts + worst_case(egg break, egg does't break)
        mini = min(mini, tempans);
    }
    tab[e][f] = mini;
    return tab[e][f];
}
int eggDropBS(int e, int f)
{
    int tab[e + 1][f + 1];
    memset(tab, -1, sizeof(tab));

    if (f == 0 || f == 1)
        return f;

    if (e == 1)
        return f;

    if (tab[e][f] != -1)
        return tab[e][f];

    int low = 1, high = f, mini = INT_MAX;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        int left = egg_Drop(e - 1, mid - 1);
        int right = egg_Drop(e, f - mid);

        mini = min(mini, max(left, right) + 1);

        if (left < right)
            low = mid + 1;

        else
            high = mid - 1;
    }
    return tab[e][f] = mini;
}
int main()
{
    int eggs = 2, floors = 30;
    cout << "Minimum Number of Attempts in Worst Case with " << eggs << " Eggs and " << floors << " Floors are " << eggDropBS(eggs, floors) << endl;
}