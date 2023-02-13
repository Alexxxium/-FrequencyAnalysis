
#include "RingBuffer.h"
#include <random>

void TestRingBuffer()
{
    std::cout << "Enter a lenght:\t";
    int lenght;
    std::cin >> lenght;

    std::cout << "Press 0 if you want get random buffer or\n"
        "Press another intenger button:\nYour chouse:\t";
    RingBuffer buff(lenght);

    std::cin >> lenght;

    if (lenght)
        while (!buff.eob())
        {
            int a;
            std::cin >> a;
            buff.push(a);
        }
    else
        while (!buff.eob())
            buff.push(rand() % 50);

    std::cout << "Your buffer:\n\n";
    buff.outBuff();

    bool stop = true;
    while (stop)
    {
        int input;

        std::cout << "Operations:\n"
            "1 -> push\n2 -> pop\n0 -> stop"
            "Operation:\t";
        std::cin >> input;

        switch(input)
        {
        case 0:
            stop = false;
            break;
        case 1:
            int vl;
            std::cin >> vl;
            buff.push(vl);
            break;
        case 2:
            std::cout << "\n\n|||||\t" << buff.pop() << "\t|||||\n\n";
            break;
        default:
            stop = false;
            break;
        }

        std::cout << "Your buffer:\n\n";
        buff.outBuff();
    }

}

int main()
{
    TestRingBuffer();
}


