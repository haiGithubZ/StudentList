#include<stdio.h>
#include<string.h>
#include<stdlib.h>

const int MAX_SV = 100;
const int MAX_NAME = 30;

struct sv {
	char fullName[MAX_NAME];
	int id;
	char homeTown[100];
	sv* next;
};

sv* createInf(char fullName[], int id, char homeTown[]) {
	sv* newSV = (sv*)malloc(sizeof(sv));
	strcpy(newSV->fullName, fullName);
	strcpy(newSV->homeTown, homeTown);
	newSV->id = id;
	newSV->next = NULL;
	return newSV;
}

void insertFirst(sv** temp, char fullName[], int id, char homeTown[]) {
	sv* newSV = createInf(fullName, id, homeTown);
	if(*temp == NULL) {
		*temp = newSV;
	} else {
		newSV->next = *temp;
		*temp = newSV;
	}
	printf("Them thanh cong!\n");
}

void insertLast(sv* temp, char fullName[], int id, char homeTown[]) {
	sv* temp1 = createInf(fullName, id, homeTown);
	while(temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = temp1;
	printf("Them thanh cong!\n");
}

void printList(sv*head) {
	while(head != NULL) {
		printf("%d. %s %s\n",head->id, head->fullName, head->homeTown);
		head = head->next;
	}
}

void sortList(sv* head, int soSV){
	for(int i = 0; i < soSV; i++){
		sv* temp1 = head;
		while(temp1->next != NULL){
			if(strcmp(temp1->fullName, (temp1->next)->fullName) > 0){
				char *temp2 = (char*)malloc(sizeof(char) * MAX_NAME);
				strcpy(temp2, temp1->fullName);
				strcpy(temp1->fullName, (temp1->next)->fullName);
				strcpy((temp1->next)->fullName, temp2);
			}
			temp1 = temp1->next;
		}			
	}
	printf("Sap xep thanh cong!\n");
}

int main() {
	sv* head = NULL;
	char fullName[MAX_NAME];
	char homeTown[100];
	int soSV = 0;
	int choice;
	do {
		printf("-------------------------------------------------\n");
		printf("1. Bo sung danh sach\n");
		printf("2. Sap xep danh sach theo thu tu ABC\n");
		printf("3. In danh sach\n");
		printf("4. Bam  phim 1-3 chon, bam phim bat ki de thoat\n");
		printf("-------------------------------------------------\n");
		scanf("%d", &choice);
		getchar();
		switch(choice) {
			case 1:
				if(soSV >= MAX_SV) {
					printf("Danh sach da day!");
				} else {
					printf("Nhap ten: ");
					fgets(fullName, MAX_NAME,stdin);
					fullName[strlen(fullName) - 1] = 0;
					fflush(stdin);
					printf("Nhap que quan: ");
					fgets(homeTown, 100,stdin);
					homeTown[strlen(homeTown) - 1] = 0;
					fflush(stdin);
				}
				if(soSV == 0) {
					insertFirst(&head, fullName, soSV, homeTown);
				}
				else{
					insertLast(head, fullName, soSV, homeTown);
				}
				soSV++;
				break;
			case 2:
				sortList(head, soSV);
				break;
			case 3:
				printList(head);
				break;
		}
	} while(choice == 1 || choice  == 2 || choice == 3);
	printf("Ket thuc!");
}
