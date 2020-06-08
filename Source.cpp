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
		cout << "�п�J�@�� :";
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
		cout << "�п�J�@�� :";
		cin >> a;
		deleteNodeTP(rootPtr, a);
		printf("\n\nThe inOrder traversal is:\n");
		inOrderTP(rootPtr);
		cout << endl << "(1) delet " << "(2) End" << endl;
		cin >> control;
	}
}
/////////////////////////////////////////////////////////////////////////
//�G �Q��template�y�k���g���G����(binary search tree)
//���x�s��Ʈ��y���(20��)
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
	setBookData(item, "��q���ǿ��ѧ޳N�G����ABBYY FineReader 11 OCR", "�����q", 371);
	insertNodeTP(rootPtr, item);
	setBookData(item, "VISUAL FORTRAN�{���]�p�P�}�o", "�i�űj�B���E��", 400);
	insertNodeTP(rootPtr, item);
	setBookData(item, "�{���]�p�Шϥ�C++", "���خx", 420);
	insertNodeTP(rootPtr, item);
	setBookData(item, "��Ʈw�t�Ρ�MTA�{�Ҽv���о�", "���K��", 336);
	insertNodeTP(rootPtr, item);
	setBookData(item, "���P�d�wGoogle���ݧ޳N�GMaps.Android.App Engine.Cloud SQL�P�q�l�Ӱ�API��ҸѪR", "���@��", 560);
	insertNodeTP(rootPtr, item);
	setBookData(item, "�H�u���z�G���z���t�ξɽ�(�ĤT��) ", "���p�� ��ҹ�w �¬F��", 590);
	insertNodeTP(rootPtr, item);
	setBookData(item, "�q����������(�ĤG��)", "�����s", 420);
	insertNodeTP(rootPtr, item);
	setBookData(item, "���ں����P�q�l�Ӱ�(�ĤT��)", "������", 450);
	insertNodeTP(rootPtr, item);
	setBookData(item, "��Ʈw�t�βz�סШϥ�SQL Server 2008", "���K��", 650);
	insertNodeTP(rootPtr, item);
	setBookData(item, "�ʵe�ϸѸ�Ʈw�t�βz�סШϥ�Access 2010��@(�ĤG��)", "���K��", 600);
	insertNodeTP(rootPtr, item);
	//
	setBookData(item, "�ʵe�ϸѸ�Ʈw�t�βz�סШϥ�Access 2010��@(�ĤG��)", "������", 60);
	insertNodeTP(rootPtr, item);
	// test duplicate data
	setBookData(item, "��q���ǿ��ѧ޳N�G����ABBYY FineReader 11 OCR", "�����q", 371);
	insertNodeTP(rootPtr, item);
	setBookData(item, "VISUAL FORTRAN�{���]�p�P�}�o", "�i�űj�B���E��", 400);
	insertNodeTP(rootPtr, item);
	setBookData(item, "�{���]�p�Шϥ�C++", "���خx", 420);
	insertNodeTP(rootPtr, item);
	setBookData(item, "��Ʈw�t�Ρ�MTA�{�Ҽv���о�", "���K��", 336);
	insertNodeTP(rootPtr, item);
	setBookData(item, "���P�d�wGoogle���ݧ޳N�GMaps.Android.App Engine.Cloud SQL�P�q�l�Ӱ�API��ҸѪR", "���@��", 560);
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
		cout << "�п�J�ѦW: ";
		getchar();
		string bookname;
		getline(cin, bookname);
		cout << "�п�J�@��: ";
		string authername;
		getline(cin, authername);	
		int price;
		cout << "�п�J����:";
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
//�T �W�[�G���� �R����ƪ��\��(20��)
/////////////////////////////////////////////////////////////////////////
template<typename T, typename K>
int deleteNodeTP(treeNodeTP<T>*& treePtr, K keyToDelete) {

	if (treePtr == NULL) {
		printf("\n���s�b\n"); //�S�����R���`�I
		return 0;
	}
	int compare_result = compareFun(keyToDelete, treePtr->data);	
	if (treePtr->leftPtr == NULL && treePtr->rightPtr == NULL && compare_result != 0) {
		printf("\n���s�b\n"); //�u�����
		return 0;
	}
	
	if (compare_result < 0)//��ڤp
		return deleteNodeTP(treePtr->leftPtr, keyToDelete);
	else if (compare_result > 0)//��ڤj
		return deleteNodeTP(treePtr->rightPtr, keyToDelete);
	else if (treePtr->leftPtr == NULL && treePtr->rightPtr == NULL && compare_result != 0) {
		printf("\n���s�b\n"); //�S�����R���`�I
		return 0;
	}
	else if (compare_result == 0) {
		if (treePtr->rightPtr == NULL && treePtr->leftPtr == NULL) {
			treePtr = NULL;
			cout << "�w�R��!" << endl;
			return 1;
		}
		else if (treePtr->rightPtr == NULL && treePtr->leftPtr != NULL)
		{
			treePtr = treePtr->leftPtr;
			cout << "�w�R��!" << endl;
			return 1;
		}
		else if (treePtr->rightPtr != NULL && treePtr->leftPtr == NULL)
		{
			treePtr = treePtr->rightPtr;
			cout << "�w�R��!" << endl;
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
			cout << "�w�R��!" << endl;
			return 1;

		}
	}
}
int main()
{
	srand(time(NULL));
	// testInt();
	testTemplateInt();	 //���� int:	 �@ �Q��template���y�k���g�G����(binary search tree)   
	testTemplateFloat();  //���� float:	 �@ �Q��template���y�k���g�G����(binary search tree) 
	testTemplateBoot();  //���� book:	 �G �Q��template���y�k���g�G����(binary search tree) 
	system("Pause");
	return 0;
}