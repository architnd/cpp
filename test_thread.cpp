#include<iostream>
#include<thread>
#include<ctime>
#include<mutex>
using namespace std;
int main(){
    #if 0
    std::thread th1([](){
        int i = 0;
        cout << "My Id is: " << std::this_thread::get_id() << "\n";

        while (i < 10){
            cout << i << "\n";
            i++;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        cout << "I am in thread\n";

    });
    std::thread th2([](){
        int i = 0;
        cout << "My Id is: " << std::this_thread::get_id() << "\n";
        while (i < 10){
            cout << i << "\n";
            i++;
            std::this_thread::sleep_for(std::chrono::seconds(2));
        }
        cout << "I am in thread\n";

    }); 
    th1.join();
    th2.join();
    cout << "thread joined\n";
    #endif
    #if 0
    auto now = std::chrono::system_clock::now();
    std:: time_t t = std::chrono::system_clock::to_time_t(now);
    cout << ctime(&t) << "\n";
    #endif

    int count = 0;
    std::mutex myMutex;
    std::thread th1([&](){
        while (1){
            {
            std::lock_guard m(myMutex);
            if (count >= 10) break;
            cout << std::this_thread::get_id() << " " << count << "\n";
            count++;
            }
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    });
    std::thread th2([&](){
        //count = 0;
        while (1){
            {
            std::lock_guard m(myMutex);
            if (count >= 10) break;
            cout << std::this_thread::get_id() << " " << count << "\n";
            count++;
            }
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }); 
    th1.join();
    th2.join();
    cout << "thread joined\n";
    return 0;
}