#include <iostream>
#include <clocale>
#include <string>
#include <windows.h>

using namespace std;

struct Book
{
    string title, autor;
    int circulation;
    string coverType, paperType;
    int orderNum;
};

void structOut(Book book)
{
    cout.width(30);
    cout << left << book.title << " | ";
    cout.width(30);
    cout << left << book.autor << " | ";
    cout.width(20);
    cout << left << book.circulation << " | ";
    cout.width(20);
    cout << left << book.coverType << " | ";
    cout.width(20);
    cout << left << book.paperType << " | ";
    cout.width(20);
    cout << left << book.orderNum << " | ";
    cout << '\n';
}
/*
*   Программа принимает на вход данные о книгах, а также тираж, и
*   выдаёт список книг, тираж которых превышает заданный.
*/
int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    size_t n;
    
    cout << "Количество книг: ";
    cin >> n;
    cin.ignore();

    if (n == 0)
    {
        cerr << "Количество книг не может быть меньше или равно 0.";
        return 1;
    } 

    Book *books = new Book[n+1];
    books[0] = {"Четвёртое поколение", "Джон Браун", 4000,
     "Твёрдый переплёт", "Обычный", 634234};
    cout << "Первая книга\n";
    structOut(books[0]);

    for (size_t i = 1; i < n+1; i++) 
    {
        cout << "Название: ";
        getline(cin, books[i].title, '\n');
        cout << "Автор: "; 
        getline(cin, books[i].autor, '\n');
        cout << "Тираж: "; 
        cin >> books[i].circulation;
        cin.ignore();
        cout << "Обложка: "; 
        getline(cin, books[i].coverType, '\n');
        cout << "Тип бумаги: "; 
        getline(cin, books[i].paperType, '\n');
        cout << "Номер заказа: "; 
        cin >> books[i].orderNum;
        cin.ignore();
    }

    size_t circulation;
    cout << "Введите тираж: ";
    cin >> circulation;
    for (size_t i = 0; i < n+1; i++) 
    {
        if(books[i].circulation > circulation)
        {
            structOut(books[i]);
        } 
    }

    delete[] books;
    return 0;
}