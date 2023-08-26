#include "ClassStack.h"

// Создайте приложение "Валидатор HTML-файлов".
// Приложение запрашивает у пользователя путь к файлу, после чего проверяет файл на валидность.
// Критерием валидности для вашего проекта являются правила:
// все открытые теги должны закрываться, если был знак < его должен закрыть знак >.
// 
// По итогам валидации нужно отобразить результат проверки на экран.
// Используйте для работы с файлами потоки, а для работы со строками класс string.

class HTMLValidator
{
private:
    Stack<char> stack;
    string Line;
public:
    HTMLValidator() : stack(), Line() {}

    bool ValidFile(const string& FileName)
    {
        ifstream File(FileName);
        if (!File.is_open())
        {
            cout << "Error: Unable to open file!" << endl;
            return false;
        }

        while (getline(File, Line))
        {
            if (!ValidTag(Line, stack))
            {
                cout << "Error: Invalid HTML detected!" << endl;
                return false;
            }
        }

        if (stack.GetSP() != 0)
        {
            cout << "Error: Unclosed tags detected (<>)!" << endl;
            return false;
        }

        cout << "HTML file is valid." << endl;
        return true;
    }

private:
    bool ValidTag(const string& line, Stack<char>& tagS)
    {
        for (char c : line)
        {
            if (c == '<')
            {
                tagS.push('<');
            }
            else if (c == '>')
            {
                if (tagS.GetSP() == 0 || tagS.top() != '<')
                {
                    return false;
                }
                tagS.pop();
            }
        }
        return true;
    }
};

int main() {
    while (true)
    {
        string file;
        cout << "Enter the path to the HTML file: ";
        cin >> file;
        // index.html - "HTML file is valid."
        // index2.html - "Error: Unclosed tags detected (<>)!"

        if (file == "exit" || file == "Exit")
        {
            cout << "Goodbye..." << endl;
            break;
        }
        
        HTMLValidator validator;
        validator.ValidFile(file);
        cout << "--------------------------------------------------\n";
    }
}