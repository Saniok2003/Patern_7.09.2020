#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Loger
{
private:
    const string Path_to_file = "C:\\Users\\Hp\\source\\repos\\DZ DP 2\\DZ DP 2\\LogFile.txt";

        static Loger* p_instance;
        
        Loger() {}
        Loger(const Loger&) = delete;
        Loger& operator=(Loger&) = delete;
public:
    static Loger* GetInstance() 
    {
        if (!p_instance)
            p_instance = new Loger();
        return p_instance;
    }

    void LogM(string msg)
    {
        ofstream out;
        out.open(this->Path_to_file, ios::app);
        if (out.is_open())
        {
            out << msg << endl;
        }
        out.close();
    }

    void ViewLog()
    {
        string line;
        ifstream fin(this->Path_to_file);
        if (fin.is_open())
        {
            while (!fin.eof())
            {
                getline(fin, line);
                cout << line << endl;
            }
            fin.close();
        }
    }

};

Loger* Loger::p_instance = nullptr;

int main()
{
    Loger::GetInstance()->LogM("Hello");
    Loger::GetInstance()->LogM("World!");
    Loger::GetInstance()->ViewLog();
    delete Loger::GetInstance();

}