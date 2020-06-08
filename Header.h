#include<iostream>
using namespace std;
template<class T>
struct treeNodeTP {
	treeNodeTP<T>* leftPtr;
	T data;
	treeNodeTP<T>* rightPtr;

	treeNodeTP(T A) {
		data = A;
		leftPtr = NULL;
		rightPtr = NULL;
	}
};
struct book
{
	char* bookName;  //書名當成 key 來比較大小
	char* authors;
	int price;
};
int compareFun(int  a, int b);
int compareFun(float  a, float b);
template<typename T>
inline void printFun(T a);
template<typename T>
void inOrderTP(treeNodeTP<T>* treePtr);
template<typename T>
void preOrderTP(treeNodeTP<T>* treePtr);
template<typename T>
void postOrderTP(treeNodeTP<T>* treePtr);
template<typename T>
void insertNodeTP(treeNodeTP<T>*& treePtr, T value); //待完成
void testTemplateInt();
void testTemplateFloat();
int compareFun(book a, book b);
inline void printFun(book a);
void setBookData(book& item, const char* bookName, const char* authors, int price =0);
void testTemplateBoot();
template<typename T, typename K>
int deleteNodeTP(treeNodeTP<T>*& treePtr, K keyToDelete);