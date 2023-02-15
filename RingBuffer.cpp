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
        for(int i = 0; i < buff.lenght(); ++i)
        {
            int a;
            std::cin >> a;
            buff.push(a);
        }
    else
        for (int i = 0; i < buff.lenght(); ++i)
            buff.push(rand() % 50);
    buff.clear();
    std::cout << "Your buffer:\n\n";
    buff.outBuff();

    bool stop = true;
    while (stop)
    {
        int input;

        std::cout << "Operations:\n"
            "1 -> push\n2 -> pop\n3 -> top\n"
            "4 -> operator <<\n5 -> operator >>\n"
            "0 -> stop\n"
            "Your operation:\t";

        std::cin >> input;

        switch (input)
        {
        case 0:
            stop = false;
            break;
        case 1:
            int a;
            std::cin >> a;
            buff.push(a);
            break;
        case 2:
            std::cout << "\n\n||||||   " <<
                buff.top() << "   ||||||\n\n";
            buff.pop();
            break;
        case 3:
            std::cout << "\n\n||||||   " <<
                buff.top() << "   ||||||\n\n";
            break;
        case 4:
            int c, d;
            std::cin >> c >> d;
            buff << c << d;
            break;
        case 5:
            int e, f;
            buff >> e >> f;
            std::cout << "\nA: " << e << "\nB: " << f << '\n';
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

    RingBuffer buff(5);
    int a = 5;
    int b = 9;
    buff << 3 << 2;
    buff.outBuff();
    buff >> a >> b;
    std::cout << a << b;
}