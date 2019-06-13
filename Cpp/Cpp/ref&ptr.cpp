//这个文件用于熟悉 “左值引用” 以及 “指针” 的定义和一些用法
#include <iostream>
using namespace std;

/*
“左值引用基础内容”
	引用不是一个对象，所以不能定义引用的引用
	引用只是某个对象的别名 (可用于函数传值)
	因为引用不可更换引用的目标，所以定义时必须初始化
*/
void refBase()
{
	int obj1 = 10;
	int& ref1 = obj1;

	//修改引用的值就是修改引用指向的值
	cout << ref1++ << endl;
	cout << obj1 << endl;

}
/*
“左值引用在函数参数上的运用”
	紧抓定义：引用是一个别名
	当引用作为形参时，被输入的实参会被形参绑定，所以函数定义时作为形参的引用可以不初始化
*/
void refFuctionInput(int a, int& b)
{
	a++;
	b++;

	cout << a << "," << b << endl;

}

/*
“指针基础内容”
	指针是一个对象，其值为指向的目标的地址
	指针是一个对象，所以可以定义指向指针的指针
	因操作系统不同的定义，指针的长度视操作系统而定
*/
void ptrBase()
{
	int obj1 = 10;
	int obj2 = 20;
	int* ptr1 = &obj1;
	
	//指针的值就是地址，所以可以用取地址符&来将某个同类型的值的地址传给他，从而使指针指向新对象.
	ptr1 = &obj2;

	//解引用符*（也有人叫解地址符）可用以指代指针指向的内容（解出所存地址的对象)，此句将指向的对象的值修改为11.
	*ptr1 = 11;
	
	//输出指针的值，即输出指针指向的对象的内存地址（本机为128位长度）
	cout << ptr1 << endl; 
	//输出指针指向的对象的值，即obj2的值
	cout << *ptr1 << endl;

	cout << obj1 << endl;
	cout << obj2 << endl;

}

/*
“指针和数组的关系”
	在Windows操作系统的实现里，数组其实是用指针来实现的

*/
void ptrWithArray()
{
	//C++11标准新增了内容，使用using A = B 来表示 A是B的一个别名
	using pcharArray = char*;

	pcharArray ptrArray;
	char Array[5] = "ABCD";

	//因数组的变量名在编译时会被编译器替换为首字符的指针，所以此处实际上是将一个指针赋值给另一个指针（地址复制）
	ptrArray = Array;
	cout << *ptrArray << endl;
	cout << &Array << endl;


	cout << Array << endl;
	cout << ptrArray << endl;


}








int main()
{
	cout << "refBase:" << endl;
	refBase();
	cout << endl;
/////////////////////////////////////////////////
	cout << "refFuctionInput:" << endl;
	int c = 10, d = 20;
	refFuctionInput(c,d);
	//输出时，c的值被传入函数时做拷贝处理，所以c的值不变；但D被形参b绑定了，所以形参b就是实参d，在函数内b被改变了值，即d的值被改变。
	cout << c <<","<< d << endl;
	cout << endl;
/////////////////////////////////////////////////
	cout << "ptrBase:" << endl;
	ptrBase();
	cout << endl;
/////////////////////////////////////////////////
	ptrWithArray();
	return 0;
}