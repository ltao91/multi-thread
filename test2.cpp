#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <assert.h>
#include <functional>
#include <vector>
#include <thread>
#include <chrono>
#include <map>
#include <random>
#include <string>
#include <queue>
#include <iostream>
#include <atomic>
#include <mutex>
using namespace std;
using ll =long long;

ll a = 0;
ll N;
int main()
{
  auto func = [&](ll t)
  {
    ll n=N/t;
    ll sum=0;
    for (ll i = 0; i < n; i++)
    {
      sum++;
    }
    a+=sum;
  };
  N=1000000000; 
  for (ll t=1;t<15;t++)
  {
    vector<thread> threads;
    auto b = chrono::system_clock::now();
    for (ll i = 0; i < t; i++)
    {
      threads.emplace_back(thread(func, t));
    }
    for(auto &i:threads)i.join();
    auto e = chrono::system_clock::now();
    cout << (chrono::duration_cast<chrono::milliseconds>(e - b).count()) << endl;
    assert(t==threads.size());
  }
}