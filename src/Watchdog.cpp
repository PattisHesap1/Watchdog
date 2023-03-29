#include <ctime>
#include <iostream>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

class Watchdog
{
private:
public:
    void Watch(std::string file_path);
    string paths[0];
};
void sleep(int time)
{
    std::time_t start_time = std::time(0);
    while (start_time + time > std::time(0))
    {
    }
}
void Watchdog::Watch(std::string parent_path)
{
    string* paths = this->paths;
    for (const auto & entry : fs::directory_iterator(parent_path))
    {
        paths->append(entry.path().string());
    }
}

int main()
{
    Watchdog file_1;
    file_1.Watch("../");
    cout << file_1.paths->length() << endl;
    for (int i = 0; file_1.paths->length(); i++)
    {
        cout << file_1.paths[i] << endl;
    }
}