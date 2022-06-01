#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <windows.h> // �޽��� �ڽ� ���
#define _CRT_SECURE_NO_WARNING
#pragma warning(disable:4996)
#pragma warning(disable:6011)
#pragma warning(disable:6001)
#pragma warning(disable:28182)
#pragma warning(disable:6054)
#pragma warning(disble:6289)

void NoFileError(FILE* Check) { // input.txt�� ������ Ȯ��
	if (Check == NULL) {
		MessageBox(NULL, TEXT("�Է� ������ �����ϴ�.\n�ٽ� �ѹ� Ȯ���ϼ���!!"), TEXT("���!!"), MB_ICONWARNING | MB_OK); // ��� ����
		exit; // ���α׷� ����
	}
}

void FileError(char buff1) { // ���� ��Ŀ� �´� �� Ȯ��
	if ((buff1 != 'i') || (buff1 != 'd') || (buff1 != 's')) {
		MessageBox(NULL, TEXT("������ �߸��Ǿ����ϴ�."), TEXT("���� ����!!"), MB_ICONWARNING | MB_OK); // ��� ����
		exit; // ���α׷� ����
	}
}

typedef struct TreeNode { // Ʈ���� ��� ����
	unsigned int data;
	struct TreeNode* left, * right;
}TreeNode;

void init(TreeNode* t) { // Ʈ�� ��� �߰� �� �ʱ�ȭ
	t->left = NULL;
	t->right = NULL;
}

void Print_Out(TreeNode* print) {

}

TreeNode* search_tree(TreeNode* start, unsigned int value) {
	if (start == NULL) return NULL;
	if (value == start->data) return start;
	else if (value < start->data) return search_tree(start->left, value);
	else return search_tree(start->right, value);
}

void insert_tree(TreeNode* start, unsigned int value) {
	
}

void delete_tree(TreeNode* start, unsigned int value) {

}

// main function
void main() {
	// Ʈ�� ����
	TreeNode* ourTree;
	ourTree = (TreeNode*)malloc(sizeof(TreeNode));
	init(&ourTree);
	
	
	// �ؽ�Ʈ �� �� ���� �б�
	// �ӽ� �޸�
	char buffer[20];
	// input.txt�� �� ��(�̸� �������� ���)
	int line = 0;
	
	// input.txt���� �о����
	FILE* input = fopen("input.txt", "r");
	FILE* output = fopen("output.txt", "a");
	NoFileError(input); // input.txt ���� üũ (���ٸ� ��� ���� ��� �� ���α׷� ����)

	while (fgets(buffer, 5, input) != NULL) { // �� �о�� NULL�� ��ȯ�մϴ�.
		FileError(buffer[0]); // ���� ��Ŀ� �´� �� Ȯ��

		// ���� ��������
		int i;
		char Num[sizeof(unsigned int)];
		for (i = 1; buffer[i] == '\n' || buffer[i] == '\0'; i++) {
			if (buffer[i] != '\n') {
				Num[i - 1] = buffer[i];
			}
			else {
				Num[i - 1] = '\0';
			}
		}
		unsigned int i_Number = atoi(Num);

		char Det = buffer[0];
		if (Det == 'i') {
			if (line == 0) {
				ourTree->data = i_Number;
			}
			else insert_tree(ourTree, i_Number);
		}
		else if (Det == 'd') {
			delete_tree(ourTree, i_Number);
		}
		else {
			search_tree(ourTree, i_Number);
		}
		line++;
	}
	fclose(input);

}