#include <ctime>
#include <iostream>
#include <filesystem>
using namespace std;
namespace fs = filesystem;

class Watchdog
{
private:

public:
    string parent_path;
    string paths[];
    Watchdog(string parent_path2)
    {
        parent_path = parent_path2;
    };
    void Watch()
    {
        for (auto entry : fs::directory_iterator(parent_path))
        {
            // cout << entry.path().string() << endl;
            paths.append(entry.path().string());
        }
    };
};

void sleep(int time)
{
    std::time_t start_time = std::time(0);
    while (start_time + time > std::time(0))
    {
    }
}

int main()
{
    Watchdog file_1("../");
    file_1.Watch();
    cout << file_1.parent_path << endl;
    for (int i = 0; i < file_1.paths.length(); i++)
    {
        cout << i << file_1.paths[i] << endl;
    }
    return 1;
}