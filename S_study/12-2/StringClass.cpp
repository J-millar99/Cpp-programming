#include <iostream>
#include <string>
using namespace std;

class String
{
	private:
		char *str;
		int strLen;
	
	public:
		String() : str(NULL), strLen(0){}
		String(const char* src)
		{
			strLen = strlen(src) + 1;
			str = new char[strLen];
			strcpy(str, src);
		}
		~String()
		{
			if (str != NULL)
				delete []str;
		}
		String(const String &ref) : strLen(strlen(ref.str) + 1)
		{
			str = new char[strLen];
			strcpy(str, ref.str);
		}
		String &operator=(const String &ref)
		{
			delete []str;
			strLen = strlen(ref.str) + 1;
			str = new char[strLen];
			strcpy(str, ref.str);
			return *this;
		}
		String operator+(const String &ref)
		{
			char *tempstr = new char[strLen + ref.strLen - 1];
			strcpy(tempstr, str);
			strcat(tempstr, ref.str);
			String temp(tempstr);
			delete []tempstr;
			return temp;
		}
		String &operator+=(const String &ref)
		{
			strLen += (ref.strLen - 1);
			char *tempstr = new char[strLen];
			strcpy(tempstr, str);
			strcat(tempstr, ref.str);
			if (str != NULL)
				delete []str;
			str = tempstr;
			return *this;
		}
		bool operator==(const String &ref)
		{
			if (!strcmp(this->str, ref.str))
				return true;
			else
				return false;
		}
		friend ostream &operator<<(ostream &os, const String &ref);
		friend istream &operator>>(istream &is, String &ref);
};

ostream &operator<<(ostream &os, const String &ref)
{
	os << ref.str;
	return os;
}

istream &operator>>(istream &is, String &ref)
{
	char str[100];
	is >> str;
	ref = String(str);
	return is;
}

int main(void)
{
	String str1 = "I like ";
	String str2 = "string class";
	String str3 = str1 + str2;

	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;

	str1 += str2;
	if (str1 == str3)
		cout << "동일 문자열!" << endl;
	else
		cout << "동일하지 않은 문자열!" << endl;
	
	String str4;
	cout << "문자열 입력: ";
	cin >> str4;
	cout << "입력한 문자열: " << str4 << endl;
	return 0;
}