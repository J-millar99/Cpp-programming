#include <iostream>
#include <cstring>
using namespace std;

class Book
{
    private:
        char *Title;
        char *Isbn;
        int Price;
    public:
        Book(const char *title, const char *isbn, int price) : Price(price)
        {
            Title = new char[strlen(title) + 1];
            strcpy(Title, title);
            Isbn = new char[strlen(isbn) + 1];
            strcpy(Isbn, isbn);
        }
        ~Book()
        {
            delete []Title;
            delete []Isbn;
        }
        void ShowBookInfo()
        {
            cout<<"제목: "<<Title<<endl;
            cout<<"ISBN: "<<Isbn<<endl;
            cout<<"가격: "<<Price<<endl;
        }
};

class EBook : public Book
{
    private:
        char *DRMKey;
    public:
        EBook(const char *title, const char *isbn, int price, const char *drmKey) : Book(title, isbn, price)
        {
            DRMKey = new char[strlen(drmKey) + 1];
            strcpy(DRMKey, drmKey);
        }
        ~EBook()
        {
            delete []DRMKey;
        }
        void ShowEBookInfo()
        {
            ShowBookInfo();
            cout<<"인증키: "<<DRMKey<<endl;
        }
};

int main(void)
{
    Book book("좋은 C++", "555-12345-890-0", 20000);
    book.ShowBookInfo();
    cout<<endl;

    EBook ebook("좋은 c++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
    ebook.ShowEBookInfo();
    return 0;
}