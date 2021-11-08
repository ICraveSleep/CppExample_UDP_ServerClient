#include <chrono>
#include <iostream>
#include <unistd.h>

std::string GetISO8601String() {

    std::chrono::high_resolution_clock::time_point timePoint = std::chrono::high_resolution_clock::now();
    std::chrono::milliseconds ms = std::chrono::duration_cast<std::chrono::milliseconds>(timePoint.time_since_epoch());
    std::size_t fractional_seconds = ms.count() % 1000000;
    std::time_t tTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

    char tmp[30];
    std::strftime(tmp, sizeof(tmp), "%Y-%m-%dT%H:%M:%S", std::gmtime(&tTime));

    std::string sString = std::string(tmp) + "." + std::to_string(fractional_seconds);

    return sString;
}


int main(){
std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
sleep(2);
std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds> (end - begin).count() << "[ns]" << std::endl;

std::string time = GetISO8601String();

std::cout << "time is: " << time << std::endl;
}