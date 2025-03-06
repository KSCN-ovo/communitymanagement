#include <stdio.h>
#include <string.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#define MAX_RESIDENTS 100  // �������100��ס��




// ����ס����Ϣ�ṹ��
typedef struct {
    char unit_number[10]; // ��Ԫ��
    char room_number[10]; // ����
    int room_size; // �������
    char owner_name[50]; // ��������
    
    char occupation[50]; // ְҵ
    char work_or_school[100]; // ������λ������ѧУ
    char personal_phone[20]; // �����ֻ���
    char id[20]; // ���֤��
    char work_phone[20]; // ��λ��ϵ�绰
    char wechat_or_qq[30]; // ΢�Ż�QQ��
    int is_owner; // �Ƿ�����1Ϊ�ǣ�0Ϊ��
    char relationship_with_owner[50]; // �뻧���Ĺ�ϵ
    char parking_spot_number[10]; // ��λ���
    char license_plate[20]; // ���ƺ�
    float property_fee; // ��ҵ��
    float parking_fee; // ͣ����
} ResidentInfo;

// ȫ�ֱ������洢����ס����Ϣ
ResidentInfo residents[MAX_RESIDENTS];
int resident_count = 0; // ��ǰס������

// ��������
void AddResident();
void FindResidentByID();
void FindResidentByCarPlate();
void PrintAllResidents();
void DeleteResidentById(); 
void ModifyResident();
void PrintPropertyFee();
void PrintParkingFee();
void CalculateTotalFee();
void SortResidentsByTotalFee();
void SaveResidentsToFile();
void LoadResidentsFromFile();
void MM_pass();
int main() {
    int choice;
    MM_pass();
    while (1) {
        printf("\n�˵���\n");
        printf("1. ����ס��\n");
        printf("2. �������֤�Ų�ѯס����Ϣ\n");
        printf("3. ���ݳ��ƺŲ�ѯ��Ϣ\n");
        printf("4. ��������û���Ϣ\n");
        printf("5. ɾ��ס��\n");
        printf("6. �޸�ס��\n");
        printf("7. ����û����� id ��ҵ��\n");
        printf("8. ����û����� id ͣ����\n");
        printf("9. ͳ�ƽɷ�\n");
        printf("10. ����ɷ�\n");
        printf("11. ���û���Ϣ�����ļ�\n");
        printf("12. ���ļ������û���Ϣ\n");
        printf("0. �˳�\n");
        printf("��ѡ��");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                AddResident();
                break;
            case 2:
                FindResidentByID();
                break;
            case 3:
                FindResidentByCarPlate();
                break;
            case 4:
                PrintAllResidents();
                break;
            case 5:
     			DeleteResidentById();
                break;
            case 6:
                ModifyResident();
                break;
            case 7:
                PrintPropertyFee();
                break;
            case 8:
                PrintParkingFee();
                break;
            case 9:
                CalculateTotalFee();
                break;
            case 10:
                SortResidentsByTotalFee();
                break;
            case 11:
                SaveResidentsToFile();
                break;
            case 12:
                LoadResidentsFromFile();
                break;

            case 0:
                return 0;
            default:
                printf("��Чѡ�����������롣\n");
        }
    }

    return 0;
}


void MM_pass()
{
	//���Ƚ����û����жϣ������ڴ��û����� �ٽ�������û��� ƥ������� �ж� ������������3�δ���ʱ �˳�����
	int count = 0, a, i;
	char MM[10] = { "passkey" }, MI[10]; //������
	char UW[10] = { "hello" }, UU[10]; //�û������
									   //-------------------------------------------------------------	
	for (i = 0; i<8; i++)                    //UI��ӭ����
	{
		printf("\n");
	}
	for (i = 0; i<30; i++)
	{
		printf(" ");
	}
	printf("��ӭ������ҵ����ϵͳ\n");
	//-------------------------------------------------------------------------------	
	while (1)			//����ѭ��				//�ж��û����Ƿ����
	{
		for (i = 0; i<30; i++)
		{
			printf(" ");
		}
		printf("�������û�����");  //��ʾ�����û���
		gets(UU);       //���̵õ� �û���

		if (strcmp(UW, UU) == 0)    //����û������� ���ж������Ƿ���ȷ
		{

			for (i = 0; i<30; i++)
			{
				printf(" ");
			}
			printf("���������룺");
			for (count = 0; count<3; count++)   //�ж������Ƿ���ȷ
			{

				gets(MI);
				a = strcmp(MM, MI);
				if (a == 0)                    // ����ȶ� �ɹ�
				{
					system("cls");
					return;                 //����ֵ�������˺���
				}
				if (count == 0 || count == 1) //�ȶԲ��ɹ�
				{
					for (i = 0; i<30; i++)
					{
						printf(" ");
					}
					printf("���������룺"); //��ʾ������������
				}
			}
			//����ִ�й�count++ ��countΪ3
			if (count >= 3)                    //�������3�� �������� �����ж�
			{
				for (i = 0; i<25; i++)
				{
					printf(" ");
				}
				printf("����3������󣬳�������,�˳����ԡ�\n");
				getchar();
				exit(0);
			}

		}
		else
		{
			for (i = 0; i<30; i++)
			{
				printf(" ");
			}
			printf("���޴��û���\n");

		}
	}



}
void LoadResidentsFromFile() {
    FILE *file = fopen("residents_data.txt", "r");
    if (file == NULL) {
        printf("�޷����ļ����ж�ȡ��\n");
        return;
    }

    ResidentInfo resident;
    while (fscanf(file, "%s %s %d %s %s %s %s %s %s %s %d %s %s %s %f %f",
                  resident.unit_number, resident.room_number, &resident.room_size,
                  resident.owner_name, resident.occupation,
                  resident.work_or_school, resident.personal_phone, resident.id,
                  resident.work_phone, resident.wechat_or_qq, &resident.is_owner,
                  resident.relationship_with_owner, resident.parking_spot_number,
                  resident.license_plate, &resident.property_fee, &resident.parking_fee) == 17) {
        residents[resident_count++] = resident;
    }

    fclose(file);
    printf("ס����Ϣ�ѳɹ����ļ����롣\n");
}
void SaveResidentsToFile() {
    FILE *file = fopen("residents_data.txt", "w");
    if (file == NULL) {
        printf("�޷����ļ�����д�롣\n");
        return;
    }

    for (int i = 0; i < resident_count; i++) {
        ResidentInfo resident = residents[i];
        fprintf(file, "%s\t %s\t %d\t %s\t  %s\t %s\t %s\t %s\t %s\t %s\t %d\t %s\t %s\t %s\t %f\t %f\n",
                resident.unit_number, resident.room_number, resident.room_size,
                resident.owner_name, resident.occupation,
                resident.work_or_school, resident.personal_phone, resident.id,
                resident.work_phone, resident.wechat_or_qq, resident.is_owner,
                resident.relationship_with_owner, resident.parking_spot_number,
                resident.license_plate, resident.property_fee, resident.parking_fee);
    }

    fclose(file);
    printf("ס����Ϣ�ѳɹ����浽�ļ���\n");
}


void AddResident() {
    // Check if we can add more residents
    if (resident_count >= MAX_RESIDENTS) {
        printf("�޷���Ӹ���ס�����Ѵﵽ���ס������\n");
        return;
    }

    // Temporary variable to store new resident's information
    ResidentInfo new_resident;

    // Prompt user for information and fill in the new_resident structure
    printf("�����뵥Ԫ�ţ�");
    scanf("%9s", new_resident.unit_number);

    printf("�����뷿�ţ�");
    scanf("%9s", new_resident.room_number);

    printf("�����뷿�������");
    scanf("%d", &new_resident.room_size);

    printf("�����뻧��������");
    scanf("%49s", new_resident.owner_name);

   
    printf("������ְҵ��");
    scanf("%49s", new_resident.occupation);

    printf("�����빤����λ������ѧУ��");
    scanf("%99s", new_resident.work_or_school);

    printf("����������ֻ��ţ�");
    scanf("%19s", new_resident.personal_phone);

    printf("���������֤�ţ�");
    scanf("%19s", new_resident.id);

    printf("�����뵥λ��ϵ�绰��");
    scanf("%19s", new_resident.work_phone);

    printf("������΢�Ż�QQ�ţ�");
    scanf("%29s", new_resident.wechat_or_qq);

    printf("�Ƿ�����1Ϊ�ǣ�0Ϊ�񣩣�");
    scanf("%d", &new_resident.is_owner);

    if (!new_resident.is_owner) {
        printf("�������뻧���Ĺ�ϵ��");
        scanf("%49s", new_resident.relationship_with_owner);
    } else {
        // If the person is the owner, we can set the relationship to "Owner" or similar
        strcpy(new_resident.relationship_with_owner, "����");
    }

    printf("�����복λ��ţ�");
    scanf("%9s", new_resident.parking_spot_number);

    printf("�����복�ƺţ�");
    scanf("%19s", new_resident.license_plate);
  

   
    // Add the new resident to the array and increment the count
    residents[resident_count] = new_resident;
    resident_count++;

    printf("ס����ӳɹ���\n");
}
void FindResidentByID() {
    char id_to_find[20];
    printf("������Ҫ���ҵ����֤��: ");
    scanf("%19s", id_to_find);

    int found = 0;
    for (int i = 0; i < resident_count; ++i) {
        if (strcmp(residents[i].id, id_to_find) == 0) {
            found = 1;
            printf("�ҵ�ס����Ϣ���£�\n");
            printf("��Ԫ�ţ�%s\n", residents[i].unit_number);
            printf("���ţ�%s\n", residents[i].room_number);
            printf("���������%d\n", residents[i].room_size);
            printf("����������%s\n", residents[i].owner_name);
            // Assuming `identity` is an enum, you may need to convert it to a string or print its integer value
            
            printf("ְҵ��%s\n", residents[i].occupation);
            printf("������λ������ѧУ��%s\n", residents[i].work_or_school);
            printf("�����ֻ��ţ�%s\n", residents[i].personal_phone);
            printf("���֤�ţ�%s\n", residents[i].id);
            printf("��λ��ϵ�绰��%s\n", residents[i].work_phone);
            printf("΢�Ż�QQ�ţ�%s\n", residents[i].wechat_or_qq);
            printf("�Ƿ�����%d\n", residents[i].is_owner);
            if (!residents[i].is_owner) {
                printf("�뻧���Ĺ�ϵ��%s\n", residents[i].relationship_with_owner);
            }
            printf("��λ��ţ�%s\n", residents[i].parking_spot_number);
            printf("���ƺţ�%s\n", residents[i].license_plate);
            
            break;
        }
    }

    if (!found) {
        printf("û���ҵ���Ӧ��ס����\n");
    }
}
void FindResidentByCarPlate() {
    char car_plate_to_find[20];
    printf("������Ҫ���ҵĳ��ƺ�: ");
    scanf("%19s", car_plate_to_find);

    int found = 0;
    for (int i = 0; i < resident_count; ++i) {
        if (strcmp(residents[i].license_plate, car_plate_to_find) == 0) {
            found = 1;
            printf("�ҵ�ס����Ϣ���£�\n");
            printf("��Ԫ�ţ�%s\n", residents[i].unit_number);
            printf("���ţ�%s\n", residents[i].room_number);
            printf("���������%d\n", residents[i].room_size);
            printf("����������%s\n", residents[i].owner_name);
            // Convert the identity enum to a string if necessary
            
            printf("ְҵ��%s\n", residents[i].occupation);
            printf("������λ������ѧУ��%s\n", residents[i].work_or_school);
            printf("�����ֻ��ţ�%s\n", residents[i].personal_phone);
            printf("���֤�ţ�%s\n", residents[i].id);
            printf("��λ��ϵ�绰��%s\n", residents[i].work_phone);
            printf("΢�Ż�QQ�ţ�%s\n", residents[i].wechat_or_qq);
            printf("�Ƿ�����%s\n", residents[i].is_owner ? "��" : "��");
            if (!residents[i].is_owner) {
                printf("�뻧���Ĺ�ϵ��%s\n", residents[i].relationship_with_owner);
            }
            printf("��λ��ţ�%s\n", residents[i].parking_spot_number);
            printf("���ƺţ�%s\n", residents[i].license_plate);
            
            break;
        }
    }

    if (!found) {
        printf("û���ҵ���Ӧ���ƺŵ�ס����\n");
    }
}

void PrintAllResidents() {
    if (resident_count == 0) {
        printf("��ǰû��ס����Ϣ��\n");
        return;
    }

    // �����У�����ʵ������������
    printf("%-5s %-10s %-10s\t %-10s\t %-15s\t %-15s\t %-25s\t %-15s\t %-20s\t %-15s\t %-20s\t %-10s\t %-15s\t %-15s\t %-15s\t %-10s\t %-10s\n",
           "���\t", "��Ԫ��\t", "����\t", "�������\t", "��������\t", "ְҵ\t", "������λ������ѧУ\t", "�����ֻ���\t", "���֤��\t", "��λ��ϵ�绰\t", "΢�Ż�QQ��\t", "�Ƿ���\t", "�뻧���Ĺ�ϵ\t", "��λ���\t", "���ƺ�\t");

    for (int i = 0; i < resident_count; i++) {
        printf("%-5d\t %-10s\t %-10s\t %-10d\t  %-10s\t %-15s\t %-25s\t %-15s\t %-20s\t %-15s\t %-20s\t %-10s\t %-15s\t %-15s\t %-15s\n",
               i + 1,
               residents[i].unit_number,
               residents[i].room_number,
               residents[i].room_size,
               residents[i].owner_name,
               
               residents[i].occupation,
               residents[i].work_or_school,
               residents[i].personal_phone,
               residents[i].id,
               residents[i].work_phone,
               residents[i].wechat_or_qq,
               residents[i].is_owner ? "��" : "��",
               residents[i].relationship_with_owner,
               residents[i].parking_spot_number,
               residents[i].license_plate);
              
    }
}
void DeleteResidentById() {
    char id_to_delete[20];
    int found_index = -1;

    // ��ȡҪɾ����ס�������֤��
    printf("������Ҫɾ����ס�������֤��: ");
    scanf("%19s", id_to_delete); // ��ֹ���������

    // ����ס��
    for (int i = 0; i < resident_count; ++i) {
        if (strcmp(residents[i].id, id_to_delete) == 0) {
            found_index = i;
            break;
        }
    }

    // ����ҵ���ɾ��ס����Ϣ
    if (found_index != -1) {
        // ���ҵ�����֮�������Ԫ�������ƶ�һλ
        for (int i = found_index; i < resident_count - 1; ++i) {
            residents[i] = residents[i + 1];
        }
        // ����ס������
        --resident_count;
        printf("ס��ɾ���ɹ���\n");
    } else {
        printf("δ�ҵ���Ӧ��ס����Ϣ��ɾ��ʧ�ܡ�\n");
    }
}

void ModifyResident() {
    char id_to_modify[20];
    int room_size;
    char personal_phone[20];
    int found_index = -1;

    // ��ȡҪ�޸ĵ�ס�������֤��
    printf("������Ҫ�޸ĵ�ס�������֤��: ");
    scanf("%19s", id_to_modify); // ��ֹ���������

    // ����ס��
    for (int i = 0; i < resident_count; ++i) {
        if (strcmp(residents[i].id, id_to_modify) == 0) {
            found_index = i;
            break;
        }
    }

    // ����ҵ����޸�ס����Ϣ
    if (found_index != -1) {
        printf("�������µķ������: ");
        scanf("%d", &room_size);
        printf("�������µĸ����ֻ���: ");
        scanf("%19s", personal_phone); // ��ֹ���������

        // ������Ϣ
        residents[found_index].room_size = room_size;
        strncpy(residents[found_index].personal_phone, personal_phone, sizeof(residents[found_index].personal_phone) - 1);
        // ȷ���ַ������� null ��β��
        residents[found_index].personal_phone[sizeof(residents[found_index].personal_phone) - 1] = '\0';

        printf("ס����Ϣ���³ɹ���\n");
    } else {
        printf("δ�ҵ���Ӧ��ס����Ϣ���޸�ʧ�ܡ�\n");
    }
}
void PrintPropertyFee() {
    printf("��ҵ����Ϣ:\n");
    printf("ID\t�������\t��ҵ��\n");
    for (int i = 0; i < resident_count; ++i) {
        printf("%s\t%d\t%.2f\n", residents[i].id, residents[i].room_size, residents[i].property_fee);
    }
}

void PrintParkingFee() {
    printf("ͣ������Ϣ:\n");
    printf("ID\t��λ���\tͣ����\n");
    for (int i = 0; i < resident_count; ++i) {
        // ��λ��ſ���Ϊ�գ������Ҫ�ж��Ƿ��г�λ���
        if (residents[i].parking_spot_number[0] != '\0') {
            printf("%s\t%s\t%.2f\n", residents[i].id, residents[i].parking_spot_number, residents[i].parking_fee);
        }
    }
}



void CalculateTotalFee() {
    printf("�û������ܼ�:\n");
    printf("ID\t����\t�������\t��λ���\t�����ܺ�\n");
    for (int i = 0; i < resident_count; ++i) {
    	residents[i].property_fee=residents[i].room_size*2;
        residents[i].parking_fee=800;
        float total_fee = residents[i].property_fee + residents[i].parking_fee;
        
        // ���û�г�λ��ţ����ǿ���ѡ���ӡ"��"���߿��ַ���
        const char* parking_spot = residents[i].parking_spot_number[0] != '\0' ? residents[i].parking_spot_number : "��";
        printf("%s\t%s\t%d\t\t%s\t\t%.2f\n", residents[i].id, residents[i].owner_name, residents[i].room_size, parking_spot, total_fee);
    }
}

// һ��������������������������Ϣ
void SwapResidents(ResidentInfo *a, ResidentInfo *b) {
    ResidentInfo temp = *a;
    *a = *b;
    *b = temp;
}

void SortResidentsByTotalFee() {
    // ʹ��ð�������㷨�Ծ����������
    for (int i = 0; i < resident_count - 1; ++i) {
        for (int j = 0; j < resident_count - i - 1; ++j) {
            float total_fee_j = residents[j].property_fee + residents[j].parking_fee;
            float total_fee_j1 = residents[j + 1].property_fee + residents[j + 1].parking_fee;
            if (total_fee_j > total_fee_j1) {
                // �������������λ��
                SwapResidents(&residents[j], &residents[j + 1]);
            }
        }
    }

    // ��ӡ��������ʾ��Ϣ
    printf("������Ϣ�Ѹ�����ҵ�Ѻ�ͣ�����ܺͽ�������\n");
}


