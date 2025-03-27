#ifdef __linux__
#include <sys/ioctl.h>
#include <termios.h>
int _kbhit();

#elif _WIN32
#include <conio.h>
#else

#endif

#include <string_view>

#include <stdio.h>
#include <cstdlib>
#include <memory>
#include <ctime>
#include <chrono>
#include <thread>
#include <iostream>

const unsigned bounded_rand(const unsigned&);


class scroller 
{
    private:
        const std::string_view txt { "HELLO WORLD!" };
        const unsigned spacing = 64;
        const int rows = 128;
        std::string line;
        std::unique_ptr<int[]> offset;
        void init() 
        { 
            offset = std::make_unique<int[]>(rows);
            std::srand(std::time({}));
            for(int x = 0; x < rows; ++x) offset[x] = -bounded_rand(spacing); 
        };

    public:
        const std::string_view next_line() 
        {
            for(int x = 0; x < rows; ++x)
            {
                if(offset[x] >= txt.length()) offset[x] = -bounded_rand(spacing);

                if(offset[x] < 0) line.at(x) = ' ';
                else line.at(x) = txt.at(offset[x]);

                offset[x]++;
            }
            return line;        
        }

        void iterate(const int& ms)
        {
            while (true) 
            { 
                std::this_thread::sleep_for(std::chrono::milliseconds(ms));
                std::cout<<next_line()<<"\n";
                if(_kbhit()) break;
            }
        }

        scroller(): line(std::string(rows, ' ')) { init(); };
        scroller(const int& _rows, const int& spaces, const std::string_view& text): rows(_rows), txt(text), spacing(spaces), line(std::string(rows, ' ')) 
        { 
            init(); 
        }; 
       ~scroller() {};
};


int main (int argc, char *argv[]) 
{


    scroller hw(64, 64, "HELLO WORLD!");
    hw.iterate(50);

    return 0;
}


// https://www.flipcode.com/archives/_kbhit_for_Linux.shtml
// Linux (POSIX) implementation of _kbhit().
// Morgan McGuire, morgan@cs.brown.edu
#ifdef __linux__
int _kbhit() 
{
    static const int STDIN = 0;
    static bool initialized = false;

    if (! initialized) {
        // Use termios to turn off line buffering
        termios term;
        tcgetattr(STDIN, &term);
        term.c_lflag &= ~ICANON;
        tcsetattr(STDIN, TCSANOW, &term);
        setbuf(stdin, NULL);
        initialized = true;
    }

    int bytesWaiting;
    ioctl(STDIN, FIONREAD, &bytesWaiting);
    return bytesWaiting;
}
#endif


// https://en.cppreference.com/w/cpp/numeric/random/rand
// https://www.pcg-random.org/posts/bounded-rands.html#debiased-modulo-once-javas-method

const unsigned bounded_rand(const unsigned& range)
{
    for (unsigned x, r;;)
        if (x = rand(), r = x % range, x - r <= -range)
            return r;
}
