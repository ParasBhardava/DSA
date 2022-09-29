#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_BOOK 1000
#define MAX_STUDENTS 100

class Book
{
public:
    int BookId;
    string BookTitle;
    int copy;
    Book(string BookTitle = "a", int BookId = 0, int copy = 0)
    {
        this->BookTitle = BookTitle;
        this->BookId = BookId;
        this->copy = copy;
    }
    void print()
    {
        cout << BookTitle << " " << copy << endl;
    }
};

class Student
{

    string name;
    int issuedBooks_count = 0;
    string BookName;

public:
    Student(string name = "a", string BookName = "b")
    {
        this->name = name;
        this->BookName = BookName;
        issuedBooks_count++;
    }
    void print()
    {
        cout << name << " " << BookName << endl;
    }
};

class Library
{
    int book_count, student_count;
    int copy_book;
    Book book[MAX_BOOK];
    Student student[MAX_STUDENTS];

public:
    Library()
    {
        book_count = 0;
        student_count = 0;
    }
    void add_book(string name, int copy_book, int Bookid)
    {
        book[book_count] = Book(name, Bookid, copy_book);
        book_count++;
    }
    void issue_book(string student_name, string Book_name, int n)
    {
        for (int z = 0; z < book_count; z++)
        {
            if (Book_name == book[z].BookTitle)
            {
                student[student_count] = Student(student_name, Book_name);
                student_count++;
            }
        }
        for (int y = 0; y < student_count; y++)
        {
            student[y].print();
        }
    }
    void print()
    {
        int same[book_count];
        for (int i = 0; i < book_count; i++)
        {
            same[i] = 1;
        }
        for (int i = 0; i < book_count; i++)
        {
            for (int j = i + 1; j < book_count; j++)
            {
                if (book[i].BookTitle == book[j].BookTitle)
                {
                    same[j] = 0;
                    book[i].copy += book[j].copy;
                }
            }
        }
        for (int k = 0; k < book_count; k++)
        {
            if (same[k] != 0)
                book[k].print();
        }
    }
};

int main()
{
    int different_title_book_count;
    cin >> different_title_book_count;
    Library L;
    for (int i = 0; i < different_title_book_count; i++)
    {
        int Bookid;
        string name;
        int copy;
        cin >> Bookid >> name >> copy;
        L.add_book(name, copy, Bookid);
    }
    cout << "__________________" << endl;
    cout << "**Total book in Library With Number Of Copies.**" << endl;
    cout << "__________________" << endl;
    L.print();
    cout << "________________" << endl;
    cout << "  ***Book issued by student.***  " << endl;
    cout << "________________" << endl;

    int student_num;
    cin >> student_num;
    for (int i = 0; i < student_num; i++)
    {
        string student_name, Book_name;
        cin >> student_name >> Book_name;
        L.issue_book(student_name, Book_name, student_num);
    }
    return 0;
}