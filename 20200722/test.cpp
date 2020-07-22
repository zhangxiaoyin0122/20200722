#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class String {
public:
	//���캯��
	String(const char* str = "") {
		_size = strlen(str);
		_str = new char[_size + 1];
		strcpy(_str, str);
		_capacity= _size;
		cout << "String()" << endl;
	}
	//��������
	String(const String& str)
		:_str(new char[str._size])
		,_size(str._size)
		,_capacity(_size)
	{
		//���
		strcpy(_str, str._str);
		cout << "String(const String&)" << endl;
	}
	//�ƶ�����
	String(String&& str)
		:_str(str._str)
	{
		str._str = nullptr;
		_size = _capacity = str._size;
		cout << "String(String&&) " << endl;
	}
	~String() {
		cout << "����" << endl;
		if (_str) {
			delete[] _str;
			cout << "~String()" << endl;
		}
	}
	const char* c_str()const {
		return _str;
	}
private:
	char* _str;
	size_t _size;
	size_t _capacity;
};
String func() {
	String str("123");
	return str;
}
//
ostream& operator<<(ostream& _cout, const String& str) {
	_cout << str.c_str() << endl;
	return _cout;
}
void test() {
	//String str("123");
	String ret = func();
	//cout << str << endl;
}

int main() {
	func();
	return 0;
}