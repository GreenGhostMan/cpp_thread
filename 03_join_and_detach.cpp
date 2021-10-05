#include <iostream>
#include <chrono>
#include <thread>

void run(int c) {
    while ( c-->0) {
        std::cout << "ROM robotics "<< std::endl;
    }
    //std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout<< "thread finished " <<std::endl;
}
int main()
{
    std::thread t(run, 10);
    std::cout << "main()" << std::endl;

    //t.join(); 
    t.detach();

    std::cout << "main() after "<< std::endl;

    std::this_thread::sleep_for(std::chrono::seconds(5));
    return 0;
}

// main() thread ပြီးသွားတော့ run() thread ကို မမြင်ရတော့ဘူး။ ဒါမှမဟုတ် os ကြောင့် run() thread နောက်ကျတာလဲဖြစ်နိုင်တယ်။
