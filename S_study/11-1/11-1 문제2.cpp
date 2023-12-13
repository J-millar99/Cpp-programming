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
		Book(const Book &ref)
		{
			Title = new char[strlen(ref.Title) + 1];
			Isbn = new char[strlen(ref.Isbn) + 1];
			strcpy(Title, ref.Title);
			strcpy(Isbn, ref.Isbn);
			Price = ref.Price;
		}
		Book &operator=(const Book &ref)
		{
			if (Title)
				delete []Title;
			if (Isbn)
				delete []Isbn;
			Title = new char[strlen(ref.Title) + 1];
			Isbn = new char[strlen(ref.Isbn) + 1];
			strcpy(Title, ref.Title);
			strcpy(Isbn, ref.Isbn);
			Price = ref.Price;
			return *this;
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
		EBook(const EBook &ref) : Book(ref)
		{
			DRMKey = new char[strlen(ref.DRMKey) + 1];
			strcpy(DRMKey, ref.DRMKey);
		}
		EBook &operator=(const EBook &ref)
		{
			Book::operator=(ref);
			delete []DRMKey;
			DRMKey = new char[strlen(ref.DRMKey) + 1];
			strcpy(DRMKey, ref.DRMKey);
			return *this;
		}
};

int main(void)
{
    Book book1("좋은 C++", "555-12345-890-0", 20000);
	Book book2 = book1;
    book2.ShowBookInfo();
    cout<<endl;

    EBook ebook1("좋은 c++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	EBook ebook2("좋은 c++ ebook2", "555-12345-890-2", 20000, "fdx9w0i8kiw2");
	ebook2 = ebook1;
    ebook2.ShowEBookInfo();
    return 0;
}