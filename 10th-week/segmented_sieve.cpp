//http://primesieve.org/segmented_sieve.html
/// @file   segmented_sieve.cpp
/// @author Kim Walisch, <kim.walisch@gmail.com> 
/// @brief  This is a simple implementation of the segmented sieve of
///         Eratosthenes with a few optimizations. It generates the
///         primes below 10^9 in 0.9 seconds (single-threaded) on an
///         Intel Core i7-4770 CPU (3.4 GHz) from 2013.
///         This is free software released into the public domain.

#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <stdint.h>

const int L1D_CACHE_SIZE = 32768;
const int debug = 0;
void segmented_sieve(std::vector<int64_t>& prime_list,int64_t limit )
{
    int segment_size = L1D_CACHE_SIZE;
    int sqrt = (int) std::sqrt((double) limit);
    int64_t count = (limit < 2) ? 0 : 1;
    int64_t s = 2;
    int64_t n = 3;

    // vector used for sieving
    std::vector<char> sieve(segment_size);

    // generate small primes <= sqrt
    std::vector<char> is_prime(sqrt + 1, 1);
    for (int i = 2; i * i <= sqrt; i++)
        if (is_prime[i])
            for (int j = i * i; j <= sqrt; j += i)
                is_prime[j] = 0;

    std::vector<int64_t> primes;
    std::vector<int64_t> next;

    for (int64_t low = 0; low <= limit; low += segment_size)
    {
        std::fill(sieve.begin(), sieve.end(), 1);

        // current segment = interval [low, high]
        int64_t high = std::min(low + segment_size - 1, limit);

        // store small primes needed to cross off multiples
        for (; s * s <= high; s++)
        {
            if (is_prime[s])
            {
                primes.push_back((int) s);
                next.push_back((int)(s * s - low));
            }
        }
        // sieve the current segment
        for (std::size_t i = 1; i < primes.size(); i++)
        {
            int j = next[i];
            for (int k = primes[i] * 2; j < segment_size; j += k)
                sieve[j] = 0;
            next[i] = j - segment_size;
        }
        if(debug)
        {
            std::cout<<"primes are"<<std::endl;
        }
        prime_list.push_back(2);
        for (; n <= high; n += 2)
        {
            if (sieve[n - low]) // n is a prime
            {
                prime_list.push_back(n);
                if(debug)
                {
                    std::cout<<n<<std::endl;
                }
                count++;
            }
        }
    }
    if(debug)
    {
        std::cout << count << " primes found." << std::endl;
    }
}

std::pair<int64_t, int64_t> prime_pair_even(std::vector<int64_t> primes, int64_t n,int64_t end)
{

    int64_t start ;
    std::pair<int64_t , int64_t> prime_pair;
    start = 0;
    //  end = primes.size() - 1; 

    while( true)
    {
        if(primes[start] > primes[end])
        {

            break;
        }
        else if(primes[start] + primes[end] > n)
        {
            end --; 

        }
        else if(primes[start ] + primes[end] < n)
        {

            start++;

        }
        else
        {

            prime_pair.first = primes[start];
            prime_pair.second = primes[end];
            break;
        }

    }
    return prime_pair;

}
std::vector<int64_t> prime_pair_odd(std::vector<int64_t > primes,int64_t n, int end)
{

    std::vector<int64_t> prime_triple;
    int64_t i1 = 0;
    int64_t i2 = i1;
    int64_t i3 = end;
    while(true)
    {
        if(primes[i2] > primes[i3])
        {
            i1++;
            i2 = i1;
            i3 =end; 

        }
        if( primes[i1] + primes[i2] +  primes[i3] < n)
        {

            i2++;

        }
        else if(primes[i1] + primes[i2] +  primes[i3] > n)
        {
            i3--;

        }
        else
        {

            prime_triple.push_back(primes[i1]);
            prime_triple.push_back(primes[i2]);
            prime_triple.push_back(primes[i3]);
            break;

        }
    }
    return prime_triple;
}
long int search_nearest_prime(std::vector<int64_t> prime , int64_t num)
{
    int64_t low , high, mid;
    low = 0;
    high = prime.size() - 1 ;
    while(low <=  high )
    {
        mid =  (low + high)/ 2;

        if( prime[mid] ==  num)
        {

            return mid;

        }
        else if( prime[mid ] < num)
        {


            low = mid + 1;

        }
        else if( prime[mid] > num )
        {
            high = mid - 1;

        }

    }
return mid;

}
int main(int argc, char** argv)
{
    // generate the primes below this number
    std::vector<int64_t> primes;
    int t; 
    std::cin>>t;
    int64_t limit = 100000000;
    segmented_sieve(primes, limit);
    for(int i = 1; i<=t ; i++)
    {
        std::cin>>limit;
        int64_t  index = search_nearest_prime( primes , limit);
if(debug)
{
    std::cout<<"index = "<< index<<std::endl;

}
        std::pair<int64_t , int64_t> prime_pair;

        if(limit % 2 == 0)
        {
            prime_pair =  prime_pair_even(primes, limit,index);
            std::cout<<"Case #"<<i<<": "<<prime_pair.first<<" "<<prime_pair.second;

        }
        else
        {
            std::vector<int64_t> prime_triple =  prime_pair_odd(primes,limit,index);
            std::cout<<"Case #"<<i<<": "<<prime_triple[0]<<" "<<prime_triple[1]<<" "<<prime_triple[2];

        }
        std::cout<<std::endl;

    }
    return 0;
}
