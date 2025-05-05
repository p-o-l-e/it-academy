#pragma once

#include <string>
#include <memory>
#include <ctime>
#include <iostream>
#include <format>


class dice
{
    private:
        const int players { 2 };
        const int win_limit { 50 };
        const int draw_limit { 100 };
        const int range { 5 };
        int mvp { 0 };
        std::unique_ptr<int[]> result;
        const std::string next_turn();

    public:
        void iterate();
        dice();
        dice(const int&, const int&, const int&, const int&);
       ~dice();
};


// https://en.cppreference.com/w/cpp/numeric/random/rand
// https://www.pcg-random.org/posts/bounded-rands.html#debiased-modulo-once-javas-method
const unsigned bounded_rand(const unsigned& range);


