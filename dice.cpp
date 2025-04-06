#include "dice.hpp"

int main()
{
    dice d_game(2, 50, 100, 5);

    d_game.iterate();

    return 0;
}



dice::dice()
{
    std::srand(std::time({}));
    result = std::make_unique<int[]>(players);
}

dice::dice(const int& pn, const int& wl, const int& dl, const int& r):
    players(pn), win_limit(wl), draw_limit(dl), range(r)
{
    std::srand(std::time({}));
    result = std::make_unique<int[]>(players);
}

dice::~dice()
{
    
}

const std::string dice::next_turn()
{
    static int sign = 1;
    std::string turn {};
    for(int i = 0; i < players; ++i)
    {
        int value = bounded_rand(range) * sign;
        turn += std::format("[P{:1}: {:4} - Total: {:4} ] ", (i + 1), value, result[i] += value);
        if (result[i] > win_limit) mvp = (i + 1);
    }
    sign *= -1;
    return turn;
}

void dice::iterate()
{
    int t = 0;
    while (!mvp)
    {
        std::cout<<std::format("Turn:{:3} ", t)<<next_turn()<<"\n";
        t++;
        if(t > draw_limit)
        {
            std::cout<<"\nDraw!"; 
            return;
        }
    }
    std::cout<<"\nPlayer "<<std::to_string(mvp)<<" wins!\n"; 
    mvp = 0;
}



// https://en.cppreference.com/w/cpp/numeric/random/rand
// https://www.pcg-random.org/posts/bounded-rands.html#debiased-modulo-once-javas-method

const unsigned bounded_rand(const unsigned& range)
{
    for (unsigned x, r;;)
        if (x = rand(), r = x % range, x - r <= -range)
            return r;
}







