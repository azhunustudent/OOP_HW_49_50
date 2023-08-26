#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <time.h>
using namespace std;
struct LC { LC() { system("chcp 1251 > nul"); srand(time(0)); } ~LC() { cin.get(); cin.get(); } } _;
#define RAND(Min,Max)  (rand()%((Max)-(Min)+1)+(Min))

// ������� �������. ������ ����
// ������� 1.
// �������� ������ � ������ "2-������ � ������-Stack.txt".
// ����������� ������ :
// Stack(int depth);
// Stack(const Stack& obj);
// Stack& operator=(const Stack& obj);
// ~Stack();

template <class T>
class Stack
{
private:
    T* Data; // ������ �����
    int Depth, SP; // ������� ������� �����, ��������� �� ������� �����
public:
    Stack() : Data(), Depth(), SP() {} // ������ ����
    Stack(int depth) : Data(), SP(), Depth()
    {
        SetDepth(depth);
    }

    Stack(const Stack<T>& obj) : Data(), SP(), Depth()
    {
        *this = obj;
    }

    Stack<T>& operator=(const Stack<T>& obj)
    {
        SetDepth(obj.GetDepth());
        for (int i = 0; i < obj.GetSP(); i++)
        {
            push(obj.Data[i]);
        }
        return *this;
    }

    ~Stack() { delete[] Data; }

    int GetSP()    const { return SP; }
    int GetDepth() const { return Depth; }

    void SetDepth(int newDepth) {
        T* temp = new T[newDepth];
        int MinCount = (SP < newDepth) ? SP : newDepth;
        for (int i = 0; i < MinCount; i++) {
            temp[i] = Data[i];
        }
        delete[]Data; // ������� ������ ������
        Data = temp;  // ���������� ����� ����� ������� �����
        Depth = newDepth; // ����� ������� �����
        SP = MinCount;
    }
    // �������� ������ val � ����
    void push(T val) {
        if (SP < Depth) {
            Data[SP] = val;
            SP++;
        }
        else {
            SetDepth(Depth * 1.5 + 1);
            Data[SP++] = val;
        }
    }
    //
    T pop() {
        if (SP > 0) {
            SP--;
            return Data[SP];
        }
        cout << "������: ����� �� ������� ����� �����!\n";
        //return ?
        throw "����� �� ������� ����� �����!"; // ����������
    }
    // cout << A.top();
    T top() const {
        if (SP > 0) {
            return Data[SP - 1]; // ���������� �� ��������
            //  - ����� Data[SP-1]
        }
        cout << "������: ����� �� ������� ����� �����!\n";
        throw "����� �� ������� ����� �����!"; // ����������
    }
    // A.top() = 123;
    T& top() {
        if (SP > 0) {
            return Data[SP - 1]; // ���������� �� ������
        }
        cout << "������: ����� �� ������� ����� �����!\n";
        throw "����� �� ������� ����� �����!"; // ����������
    }

    bool is_empty() const {
        return SP == 0;
    }

    friend ostream& operator << (ostream& os,
        const Stack<T>& obj)
    {
        os << "Depth = " << obj.GetDepth() << endl;
        os << "Stack pointer = " << obj.GetSP() << endl;
        os << "Count = " << obj.GetSP() << endl;
        for (int i = 0; i < obj.GetSP(); i++) {
            os << obj.Data[i] << " ";
        }
        return os << endl; // return os;
    }

}; // class Stack<>;