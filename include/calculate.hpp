#ifndef CALCULATE_HPP
#define CALCULATE_HPP

#include <thread>
#include <iostream>
#include "record.hpp"


Record logistic(const double x0, const double mu0, const double delta_mu, const double iter_mu,
                const int m, const int N)
{
    Record record(m * (iter_mu + 1));
    const int thread_num = std::thread::hardware_concurrency();

    auto work = 
    [thread_num, m, N, x0, mu0, &record, delta_mu, iter_mu](int thread_id)
    {
        for(int k = thread_id; k < iter_mu + 1; k += thread_num)
        {
            double x = x0;
            double mu = mu0 + delta_mu * k;
            for(int i = 0; i < N-1; ++i)
            {
                x = mu * x * (1.0 - x);
            }
            
            for(int i = 0; i < m; ++i)
            {
                x = mu * x * (1.0 - x);
                record.x_list[k * m + i] = x;
                record.mu_list[k * m + i] = mu;
            }
        }
    };


    std::vector<std::thread> threads(thread_num);
    for(int i = 0; i < thread_num; ++i)
    {
        threads[i] = std::thread(work, i);
    }


    for(int i = 0; i < thread_num; ++i)
    {
        threads[i].join();
    }

    return record;
}



#endif