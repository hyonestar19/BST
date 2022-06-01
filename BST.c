#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <windows.h> // 메시지 박스 출력
#define _CRT_SECURE_NO_WARNING
#pragma warning(disable:4996)
#pragma warning(disable:6011)
#pragma warning(disable:6001)
#pragma warning(disable:28182)
#pragma warning(disable:6054)
#pragma warning(disble:6289)

void NoFileError(FILE* Check) { // input.txt가 없는지 확인
	if (Check == NULL) {
		MessageBox(NULL, TEXT("입력 파일이 없습니다.\n다시 한번 확인하세요!!"), TEXT("경고!!"), MB_ICONWARNING | MB_OK); // 경고 문구
		exit; // 프로그램 종료
	}
}

void FileError(char buff1) { // 파일 양식에 맞는 지 확인
	if ((buff1 != 'i') || (buff1 != 'd') || (buff1 != 's')) {
		MessageBox(NULL, TEXT("파일이 잘못되었습니다."), TEXT("파일 에러!!"), MB_ICONWARNING | MB_OK); // 경고 문구
		exit; // 프로그램 종료
	}
}

typedef struct TreeNode { // 트리의 노드 생성
	unsigned int data;
	struct TreeNode* left, * right;
}TreeNode;

void init(TreeNode* t) { // 트리 노드 추가 시 초기화
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
	// 트리 생성
	TreeNode* ourTree;
	ourTree = (TreeNode*)malloc(sizeof(TreeNode));
	init(&ourTree);
	
	
	// 텍스트 줄 안 내용 읽기
	// 임시 메모리
	char buffer[20];
	// input.txt의 줄 수(이름 설정에도 사용)
	int line = 0;
	
	// input.txt에서 읽어오기
	FILE* input = fopen("input.txt", "r");
	FILE* output = fopen("output.txt", "a");
	NoFileError(input); // input.txt 유무 체크 (없다면 경고 문구 출력 후 프로그램 종료)

	while (fgets(buffer, 5, input) != NULL) { // 다 읽어내면 NULL을 반환합니다.
		FileError(buffer[0]); // 파일 양식에 맞는 지 확인

		// 숫자 가져오기
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