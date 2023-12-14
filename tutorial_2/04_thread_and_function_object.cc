#include <iostream>
#include <thread>

class Vehicle
{
public:
    Vehicle( int id ) : id_(id) {}
    void operator()()
    {
        std::cout << "Vehicle object has been created \n" << std::endl;
    }
private:
    int id_;
};


int main()
{
    // create thread 
    //std::thread t{Vehicle()}; // C++'s most vexing parse
    std::thread t = std::thread(Vehicle(1));

    // do something in main()
    std::cout << "Finished work in main \n";

    // wait for thread to finish
    t.join();

    return 0;
}
