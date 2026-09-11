//Elena María Barrios Jordan
//A01771338

#include <iostream>
using namespace std;
#include <string>

class Log{
    private:
    int day;
    string month;
    int year;
    string time;
    string ip;
    string message;
    string Key;

    public:
    Log();
    Log(int day, string month, int year, string time, string ip, string message);
    string createKey();
    bool operator==(const Log& other);
    bool operator!=(const Log& other);
    bool operator<(const Log& other);
    bool operator>(const Log& other);
    bool operator<=(const Log& other);
    bool operator>=(const Log& other);

};

bool Log::operator>(const Log& other) {
    return Key() > other.Key();
}
