#include<stdio.h>
#include<string.h>

const int MAX_SV = 100;
const int MAX_NAME = 30;

int main() {
	char SV[MAX_SV][MAX_NAME];
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
					printf("Danh sach da day\n");
				}
				else {
					printf("Nhap ho va ten sinh vien: ");
					fgets(SV[soSV], MAX_NAME, stdin);
					SV[soSV][strcspn(SV[soSV], "\n")] = 0;
					soSV++;
					printf("Them sinh vien thanh cong\n");
				}
				break;
			case 2:
				for(int i = 0; i < soSV - 1; i++){
					for(int j = 0; j < soSV - 1; j++){
						if(strcmp(SV[j], SV[j + 1]) > 0){
							char temp[MAX_SV];
							strcpy(temp, SV[j]);
							strcpy(SV[j], SV[j + 1]);
							strcpy(SV[j + 1], temp);
						}
					}
				}
				printf("Sap xep thanh cong!\n");
				break;
			case 3:
				for(int i = 0; i < soSV; i++) {
					printf("%d %s\n",i + 1, SV[i]);
				}
				break;
		}
	} while(choice == 1 || choice == 2 || choice == 3);
	printf("Ket thuc!");
}