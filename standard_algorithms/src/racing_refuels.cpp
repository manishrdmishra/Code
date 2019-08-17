#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using ulong = unsigned long long;

ulong calculate_min_time(ulong capacity, ulong laps, const vector<ulong>& completion_time,ulong pit_stop_time)
{
    ulong low = 1;
    ulong high = capacity;

    ulong min_time = std::numeric_limits<ulong>::max();
    for(ulong i = 1; i <= capacity; ++i)
    {
        auto time = calculate_time(i, capacity, laps, completion_time, pit_stop_time);
        if( time < min_time)
        {
            min_time = time;
        }

    }
    return min_time;
}

ulong calculate_time(ulong initial_fuel, ulong capacity, ulong laps, const vector<ulong>& completion_time,ulong pit_stop_time)
{
    ulong time = 0;
    ulong fuel = initial_fuel;
    for(ulong lap = 0; lap < laps; ++lap)
    {
        if(fuel == 0)
        {
            fuel = min(laps-lap, capacity);
            time += pit_stop_time;
        }

        time += completion_time[fuel];
        --fuel;

    }
}
int main()
{
    ulong capacity = 0;
    ulong races = 0;
    cin>>capacity;
    cin>>races;

    vector<ulong> completion_time(capacity);
    for(ulong i = 0; i< capacity; ++i)
    {
        ulong time;
        cin>>time;
        completion_time.push_back(time);
    }

    for(ulong race = 0; race < races; ++race)
    {
        ulong laps = 0;
        ulong pit_stop_time = 0;
        cin>>laps;
        cin>>pit_stop_time;
        auto min_time = calculate_min_time(capacity, laps, completion_time, pit_stop_time);
        cout<< min_time;

    }

}
