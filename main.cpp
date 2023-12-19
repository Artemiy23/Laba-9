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
*   ��������� ��������� �� ���� ������ � ������, � ����� �����, �
*   ����� ������ ����, ����� ������� ��������� ��������.
*/
int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    size_t n;
    
    cout << "���������� ����: ";
    cin >> n;
    cin.ignore();

    if (n == 0)
    {
        cerr << "���������� ���� �� ����� ���� ������ ��� ����� 0.";
        return 1;
    } 

    Book *books = new Book[n+1];
    books[0] = {"�������� ���������", "���� �����", 4000,
     "������ �������", "�������", 634234};
    cout << "������ �����\n";
    structOut(books[0]);

    for (size_t i = 1; i < n+1; i++) 
    {
        cout << "��������: ";
        getline(cin, books[i].title, '\n');
        cout << "�����: "; 
        getline(cin, books[i].autor, '\n');
        cout << "�����: "; 
        cin >> books[i].circulation;
        cin.ignore();
        cout << "�������: "; 
        getline(cin, books[i].coverType, '\n');
        cout << "��� ������: "; 
        getline(cin, books[i].paperType, '\n');
        cout << "����� ������: "; 
        cin >> books[i].orderNum;
        cin.ignore();
    }

    size_t circulation;
    cout << "������� �����: ";
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