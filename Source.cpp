#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string.h>
#include <string>
#include "Header.h"
using namespace std;
int compareFun(int  a, int b)
{
	if (a < b)
		return -1;
	else if (a > b)
		return 1;
	else
		return 0;
}
int compareFun(float  a, float b)
{
	if (a < b)
		return -1;
	else if (a > b)
		return 1;
	else
		return 0;
}
template<typename T>
inline void printFun(T a)
{
	cout << a << " ";
}
template<typename T>
void inOrderTP(treeNodeTP<T>* treePtr)
{
	if (treePtr != NULL) {
		inOrderTP(treePtr->leftPtr);
		printFun(treePtr->data);
		inOrderTP(treePtr->rightPtr);
	}

}
template<typename T>
void preOrderTP(treeNodeTP<T>* treePtr)
{
	if (treePtr != NULL) {
		printFun(treePtr->data);
		preOrderTP(treePtr->leftPtr);
		preOrderTP(treePtr->rightPtr);
	}
}
template<typename T>
void postOrderTP(treeNodeTP<T>* treePtr)
{
	if (treePtr != NULL) {
		postOrderTP(treePtr->leftPtr);
		postOrderTP(treePtr->rightPtr);
		printFun(treePtr->data);
	}
}
template<typename T>
void insertNodeTP(treeNodeTP<T>*& treePtr, T value)
{
	if (treePtr == NULL) {
		treePtr = new struct treeNodeTP<T>(value);
		if (treePtr != NULL) 
			printFun(value);
		else
			printf("%f  not inserted. No memory available.\n", value);
	}
	else if (compareFun(value, (treePtr->data)) == -1)
		insertNodeTP((treePtr->leftPtr), value);
	else if (compareFun(value, (treePtr->data)) == 1)
		insertNodeTP((treePtr->rightPtr), value);
	else
		printf("X ");
}
void testTemplateInt()
{
	treeNodeTP<int>* rootPtr = NULL;
	int i, item;
	/* insert random values between 1 and 15 in the tree */
	printf("The numbers being placed in the tree are:\n");
	/*
	for (int i = 0; i < 15; i++) {
		cin >> item;
		insertNodeTP(rootPtr, item);
	}
	*/
	for (i = 1; i <= 15; i++) {
		item = rand() % 15;
		insertNodeTP(rootPtr, item);
	}
	
	
	/* traverse the tree preOrder */
	printf("\n\nThe preOrder traversal is:\n");
	preOrderTP(rootPtr);
	/* traverse the tree inOrder */
	printf("\n\nThe inOrder traversal is:\n");
	inOrderTP(rootPtr);
	/* traverse the tree postOrder */
	printf("\n\nThe postOrder traversal is:\n");
	postOrderTP(rootPtr);
	std::cout << endl << endl;
	int control = 0;
	cout << "(1) delet " << "(2) End" << endl;
	cin >> control;
	while (control == 1) {
		int a;
		cout << "請輸入一數 :";
		cin >> a;
		deleteNodeTP(rootPtr, a);
		printf("\n\nThe inOrder traversal is:\n");
		inOrderTP(rootPtr);
		cout << endl << "(1) delet " << "(2) End" << endl;
		cin >> control;
	}
}
void testTemplateFloat()
{
	treeNodeTP<float>* rootPtr = NULL;
	int i;
	float item;
	/* insert random values between 1 and 15 in the tree */
	printf("The numbers being placed in the tree are:\n");	
	for (i = 1; i <= 15; i++) {
		item = 1.0 + (float)(rand() % 8) * 0.01f;
		//std::cout << item << "  ";
		insertNodeTP(rootPtr, item);
	}
	/* traverse the tree preOrder */
	printf("\n\nThe preOrder traversal is:\n");
	preOrderTP(rootPtr);
	/* traverse the tree inOrder */
	printf("\n\nThe inOrder traversal is:\n");
	inOrderTP(rootPtr);
	/* traverse the tree postOrder */
	printf("\n\nThe postOrder traversal is:\n");
	postOrderTP(rootPtr);
	std::cout << endl << endl;
	int control = 0;
	cout << "(1) delet " << "(2) End" << endl;
	cin >> control;
	while (control == 1) {
		float a;
		cout << "請輸入一數 :";
		cin >> a;
		deleteNodeTP(rootPtr, a);
		printf("\n\nThe inOrder traversal is:\n");
		inOrderTP(rootPtr);
		cout << endl << "(1) delet " << "(2) End" << endl;
		cin >> control;
	}
}
/////////////////////////////////////////////////////////////////////////
//二 利用template語法撰寫的二元樹(binary search tree)
//來儲存資料書籍資料(20分)
/////////////////////////////////////////////////////////////////////////
int compareFun(book a, book b)
{
	 if (!strcmp(a.bookName, b.bookName)) {		 
		 if (strcmp(a.authors, b.authors) == 0 ) 
			 return compareFun(a.price, b.price);
		 return strcmp(a.authors, b.authors);
	 }
	 
	 return strcmp(a.bookName, b.bookName);

}
inline void printFun(book a)
{
	cout << a.bookName << " " << a.authors << " " << a.price << endl;
}
void setBookData(book& item, const char* bookName, const char* authors, int price)
{
	item.bookName = (char*)bookName;
	item.authors = (char*)authors;
	item.price = price;
};
void testTemplateBoot()
{
	treeNodeTP<book>* rootPtr = NULL;
	book item;
	printf("The books being placed in the tree are:\n");
	setBookData(item, "精通光學辨識技術：應用ABBYY FineReader 11 OCR", "黃敦義", 371);
	insertNodeTP(rootPtr, item);
	setBookData(item, "VISUAL FORTRAN程式設計與開發", "張嘉強、陳鴻智", 400);
	insertNodeTP(rootPtr, item);
	setBookData(item, "程式設計－使用C++", "黃建庭", 420);
	insertNodeTP(rootPtr, item);
	setBookData(item, "資料庫系統－MTA認證影音教學", "李春雄", 336);
	insertNodeTP(rootPtr, item);
	setBookData(item, "輕鬆搞定Google雲端技術：Maps.Android.App Engine.Cloud SQL與電子商務API實例解析", "陳世興", 560);
	insertNodeTP(rootPtr, item);
	setBookData(item, "人工智慧：智慧型系統導論(第三版) ", "李聯旺 廖珗洲 謝政勳", 590);
	insertNodeTP(rootPtr, item);
	setBookData(item, "電腦網路概論(第二版)", "陳雲龍", 420);
	insertNodeTP(rootPtr, item);
	setBookData(item, "網際網路與電子商務(第三版)", "朱正忠", 450);
	insertNodeTP(rootPtr, item);
	setBookData(item, "資料庫系統理論－使用SQL Server 2008", "李春雄", 650);
	insertNodeTP(rootPtr, item);
	setBookData(item, "動畫圖解資料庫系統理論－使用Access 2010實作(第二版)", "李春雄", 600);
	insertNodeTP(rootPtr, item);
	//
	setBookData(item, "動畫圖解資料庫系統理論－使用Access 2010實作(第二版)", "朱正忠", 60);
	insertNodeTP(rootPtr, item);
	// test duplicate data
	setBookData(item, "精通光學辨識技術：應用ABBYY FineReader 11 OCR", "黃敦義", 371);
	insertNodeTP(rootPtr, item);
	setBookData(item, "VISUAL FORTRAN程式設計與開發", "張嘉強、陳鴻智", 400);
	insertNodeTP(rootPtr, item);
	setBookData(item, "程式設計－使用C++", "黃建庭", 420);
	insertNodeTP(rootPtr, item);
	setBookData(item, "資料庫系統－MTA認證影音教學", "李春雄", 336);
	insertNodeTP(rootPtr, item);
	setBookData(item, "輕鬆搞定Google雲端技術：Maps.Android.App Engine.Cloud SQL與電子商務API實例解析", "陳世興", 560);
	insertNodeTP(rootPtr, item);
	/* traverse the tree preOrder */
	printf("\n\nThe preOrder traversal is:\n");
	preOrderTP(rootPtr);
	/* traverse the tree inOrder */
	printf("\n\nThe inOrder traversal is:\n");
	inOrderTP(rootPtr);
	/* traverse the tree postOrder */
	printf("\n\nThe postOrder traversal is:\n");
	postOrderTP(rootPtr);
	std::cout << endl << endl;

	cout << "(1) delet " << "(2) End" << endl;
	int control;
	cin >> control;
	while (control == 1) {
		book delet;
		cout << "請輸入書名: ";
		getchar();
		string bookname;
		getline(cin, bookname);
		cout << "請輸入作者: ";
		string authername;
		getline(cin, authername);	
		int price;
		cout << "請輸入價格:";
		cin >> price;
		setBookData(delet, bookname.c_str(), authername.c_str(),price);
		printFun(delet);
		deleteNodeTP(rootPtr, delet);
		printf("\n\nThe inOrder traversal is:\n");
		inOrderTP(rootPtr);
		cout << endl << "(1) delet " << "(2) End" << endl;
		cin >> control;
	}
}
/////////////////////////////////////////////////////////////////////////
//三 增加二元樹 刪除資料的功能(20分)
/////////////////////////////////////////////////////////////////////////
template<typename T, typename K>
int deleteNodeTP(treeNodeTP<T>*& treePtr, K keyToDelete) {

	if (treePtr == NULL) {
		printf("\n不存在\n"); //沒有找到刪除節點
		return 0;
	}
	int compare_result = compareFun(keyToDelete, treePtr->data);	
	if (treePtr->leftPtr == NULL && treePtr->rightPtr == NULL && compare_result != 0) {
		printf("\n不存在\n"); //只有樹根
		return 0;
	}
	
	if (compare_result < 0)//比根小
		return deleteNodeTP(treePtr->leftPtr, keyToDelete);
	else if (compare_result > 0)//比根大
		return deleteNodeTP(treePtr->rightPtr, keyToDelete);
	else if (treePtr->leftPtr == NULL && treePtr->rightPtr == NULL && compare_result != 0) {
		printf("\n不存在\n"); //沒有找到刪除節點
		return 0;
	}
	else if (compare_result == 0) {
		if (treePtr->rightPtr == NULL && treePtr->leftPtr == NULL) {
			treePtr = NULL;
			cout << "已刪除!" << endl;
			return 1;
		}
		else if (treePtr->rightPtr == NULL && treePtr->leftPtr != NULL)
		{
			treePtr = treePtr->leftPtr;
			cout << "已刪除!" << endl;
			return 1;
		}
		else if (treePtr->rightPtr != NULL && treePtr->leftPtr == NULL)
		{
			treePtr = treePtr->rightPtr;
			cout << "已刪除!" << endl;
			return 1;
		}
		else if (treePtr->rightPtr != NULL && treePtr->leftPtr != NULL)
		{
			treeNodeTP<T>* savePtr, * saveleft;
			savePtr = treePtr;
			saveleft = treePtr->rightPtr;
			treePtr = treePtr->rightPtr;
			while (saveleft->leftPtr != NULL)
			{
				saveleft = saveleft->leftPtr;
			}
			saveleft->leftPtr = savePtr->leftPtr;
			cout << "已刪除!" << endl;
			return 1;

		}
	}
}
int main()
{
	srand(time(NULL));
	// testInt();
	testTemplateInt();	 //測試 int:	 一 利用template的語法撰寫二元樹(binary search tree)   
	testTemplateFloat();  //測試 float:	 一 利用template的語法撰寫二元樹(binary search tree) 
	testTemplateBoot();  //測試 book:	 二 利用template的語法撰寫二元樹(binary search tree) 
	system("Pause");
	return 0;
}