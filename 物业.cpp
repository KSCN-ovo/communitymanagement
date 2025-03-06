#include <stdio.h>
#include <string.h>
#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<time.h>
#define MAX_RESIDENTS 100  // 假设最多100个住户




// 定义住户信息结构体
typedef struct {
    char unit_number[10]; // 单元号
    char room_number[10]; // 房号
    int room_size; // 房屋面积
    char owner_name[50]; // 户主姓名
    
    char occupation[50]; // 职业
    char work_or_school[100]; // 工作单位或所在学校
    char personal_phone[20]; // 个人手机号
    char id[20]; // 身份证号
    char work_phone[20]; // 单位联系电话
    char wechat_or_qq[30]; // 微信或QQ号
    int is_owner; // 是否户主（1为是，0为否）
    char relationship_with_owner[50]; // 与户主的关系
    char parking_spot_number[10]; // 车位编号
    char license_plate[20]; // 车牌号
    float property_fee; // 物业费
    float parking_fee; // 停车费
} ResidentInfo;

// 全局变量，存储所有住户信息
ResidentInfo residents[MAX_RESIDENTS];
int resident_count = 0; // 当前住户数量

// 函数声明
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
        printf("\n菜单：\n");
        printf("1. 新增住户\n");
        printf("2. 根据身份证号查询住户信息\n");
        printf("3. 根据车牌号查询信息\n");
        printf("4. 输出所有用户信息\n");
        printf("5. 删除住户\n");
        printf("6. 修改住户\n");
        printf("7. 输出用户姓名 id 物业费\n");
        printf("8. 输出用户姓名 id 停车费\n");
        printf("9. 统计缴费\n");
        printf("10. 排序缴费\n");
        printf("11. 将用户信息存入文件\n");
        printf("12. 从文件导入用户信息\n");
        printf("0. 退出\n");
        printf("请选择：");
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
                printf("无效选择，请重新输入。\n");
        }
    }

    return 0;
}


void MM_pass()
{
	//首先进行用户名判断，当存在此用户名后 再进行与该用户名 匹配的密码 判断 。当密码输入3次错误时 退出程序
	int count = 0, a, i;
	char MM[10] = { "passkey" }, MI[10]; //密码存放
	char UW[10] = { "hello" }, UU[10]; //用户名存放
									   //-------------------------------------------------------------	
	for (i = 0; i<8; i++)                    //UI欢迎界面
	{
		printf("\n");
	}
	for (i = 0; i<30; i++)
	{
		printf(" ");
	}
	printf("欢迎进入物业管理系统\n");
	//-------------------------------------------------------------------------------	
	while (1)			//进入循环				//判断用户名是否存在
	{
		for (i = 0; i<30; i++)
		{
			printf(" ");
		}
		printf("请输入用户名：");  //提示输入用户名
		gets(UU);       //键盘得到 用户名

		if (strcmp(UW, UU) == 0)    //如果用户名存在 则判断密码是否正确
		{

			for (i = 0; i<30; i++)
			{
				printf(" ");
			}
			printf("请输入密码：");
			for (count = 0; count<3; count++)   //判断密码是否正确
			{

				gets(MI);
				a = strcmp(MM, MI);
				if (a == 0)                    // 如果比对 成功
				{
					system("cls");
					return;                 //返回值，结束此函数
				}
				if (count == 0 || count == 1) //比对不成功
				{
					for (i = 0; i<30; i++)
					{
						printf(" ");
					}
					printf("请输入密码："); //提示重新输入密码
				}
			}
			//由于执行过count++ 则count为3
			if (count >= 3)                    //密码输错3次 程序锁定 错误判定
			{
				for (i = 0; i<25; i++)
				{
					printf(" ");
				}
				printf("密码3输入错误，程序锁定,退出重试。\n");
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
			printf("查无此用户！\n");

		}
	}



}
void LoadResidentsFromFile() {
    FILE *file = fopen("residents_data.txt", "r");
    if (file == NULL) {
        printf("无法打开文件进行读取。\n");
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
    printf("住户信息已成功从文件导入。\n");
}
void SaveResidentsToFile() {
    FILE *file = fopen("residents_data.txt", "w");
    if (file == NULL) {
        printf("无法打开文件进行写入。\n");
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
    printf("住户信息已成功保存到文件。\n");
}


void AddResident() {
    // Check if we can add more residents
    if (resident_count >= MAX_RESIDENTS) {
        printf("无法添加更多住户，已达到最大住户数。\n");
        return;
    }

    // Temporary variable to store new resident's information
    ResidentInfo new_resident;

    // Prompt user for information and fill in the new_resident structure
    printf("请输入单元号：");
    scanf("%9s", new_resident.unit_number);

    printf("请输入房号：");
    scanf("%9s", new_resident.room_number);

    printf("请输入房屋面积：");
    scanf("%d", &new_resident.room_size);

    printf("请输入户主姓名：");
    scanf("%49s", new_resident.owner_name);

   
    printf("请输入职业：");
    scanf("%49s", new_resident.occupation);

    printf("请输入工作单位或所在学校：");
    scanf("%99s", new_resident.work_or_school);

    printf("请输入个人手机号：");
    scanf("%19s", new_resident.personal_phone);

    printf("请输入身份证号：");
    scanf("%19s", new_resident.id);

    printf("请输入单位联系电话：");
    scanf("%19s", new_resident.work_phone);

    printf("请输入微信或QQ号：");
    scanf("%29s", new_resident.wechat_or_qq);

    printf("是否户主（1为是，0为否）：");
    scanf("%d", &new_resident.is_owner);

    if (!new_resident.is_owner) {
        printf("请输入与户主的关系：");
        scanf("%49s", new_resident.relationship_with_owner);
    } else {
        // If the person is the owner, we can set the relationship to "Owner" or similar
        strcpy(new_resident.relationship_with_owner, "户主");
    }

    printf("请输入车位编号：");
    scanf("%9s", new_resident.parking_spot_number);

    printf("请输入车牌号：");
    scanf("%19s", new_resident.license_plate);
  

   
    // Add the new resident to the array and increment the count
    residents[resident_count] = new_resident;
    resident_count++;

    printf("住户添加成功！\n");
}
void FindResidentByID() {
    char id_to_find[20];
    printf("请输入要查找的身份证号: ");
    scanf("%19s", id_to_find);

    int found = 0;
    for (int i = 0; i < resident_count; ++i) {
        if (strcmp(residents[i].id, id_to_find) == 0) {
            found = 1;
            printf("找到住户信息如下：\n");
            printf("单元号：%s\n", residents[i].unit_number);
            printf("房号：%s\n", residents[i].room_number);
            printf("房屋面积：%d\n", residents[i].room_size);
            printf("户主姓名：%s\n", residents[i].owner_name);
            // Assuming `identity` is an enum, you may need to convert it to a string or print its integer value
            
            printf("职业：%s\n", residents[i].occupation);
            printf("工作单位或所在学校：%s\n", residents[i].work_or_school);
            printf("个人手机号：%s\n", residents[i].personal_phone);
            printf("身份证号：%s\n", residents[i].id);
            printf("单位联系电话：%s\n", residents[i].work_phone);
            printf("微信或QQ号：%s\n", residents[i].wechat_or_qq);
            printf("是否户主：%d\n", residents[i].is_owner);
            if (!residents[i].is_owner) {
                printf("与户主的关系：%s\n", residents[i].relationship_with_owner);
            }
            printf("车位编号：%s\n", residents[i].parking_spot_number);
            printf("车牌号：%s\n", residents[i].license_plate);
            
            break;
        }
    }

    if (!found) {
        printf("没有找到对应的住户。\n");
    }
}
void FindResidentByCarPlate() {
    char car_plate_to_find[20];
    printf("请输入要查找的车牌号: ");
    scanf("%19s", car_plate_to_find);

    int found = 0;
    for (int i = 0; i < resident_count; ++i) {
        if (strcmp(residents[i].license_plate, car_plate_to_find) == 0) {
            found = 1;
            printf("找到住户信息如下：\n");
            printf("单元号：%s\n", residents[i].unit_number);
            printf("房号：%s\n", residents[i].room_number);
            printf("房屋面积：%d\n", residents[i].room_size);
            printf("户主姓名：%s\n", residents[i].owner_name);
            // Convert the identity enum to a string if necessary
            
            printf("职业：%s\n", residents[i].occupation);
            printf("工作单位或所在学校：%s\n", residents[i].work_or_school);
            printf("个人手机号：%s\n", residents[i].personal_phone);
            printf("身份证号：%s\n", residents[i].id);
            printf("单位联系电话：%s\n", residents[i].work_phone);
            printf("微信或QQ号：%s\n", residents[i].wechat_or_qq);
            printf("是否户主：%s\n", residents[i].is_owner ? "是" : "否");
            if (!residents[i].is_owner) {
                printf("与户主的关系：%s\n", residents[i].relationship_with_owner);
            }
            printf("车位编号：%s\n", residents[i].parking_spot_number);
            printf("车牌号：%s\n", residents[i].license_plate);
            
            break;
        }
    }

    if (!found) {
        printf("没有找到对应车牌号的住户。\n");
    }
}

void PrintAllResidents() {
    if (resident_count == 0) {
        printf("当前没有住户信息。\n");
        return;
    }

    // 标题行，根据实际情况调整宽度
    printf("%-5s %-10s %-10s\t %-10s\t %-15s\t %-15s\t %-25s\t %-15s\t %-20s\t %-15s\t %-20s\t %-10s\t %-15s\t %-15s\t %-15s\t %-10s\t %-10s\n",
           "编号\t", "单元号\t", "房号\t", "房屋面积\t", "户主姓名\t", "职业\t", "工作单位或所在学校\t", "个人手机号\t", "身份证号\t", "单位联系电话\t", "微信或QQ号\t", "是否户主\t", "与户主的关系\t", "车位编号\t", "车牌号\t");

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
               residents[i].is_owner ? "是" : "否",
               residents[i].relationship_with_owner,
               residents[i].parking_spot_number,
               residents[i].license_plate);
              
    }
}
void DeleteResidentById() {
    char id_to_delete[20];
    int found_index = -1;

    // 获取要删除的住户的身份证号
    printf("请输入要删除的住户的身份证号: ");
    scanf("%19s", id_to_delete); // 防止缓冲区溢出

    // 搜索住户
    for (int i = 0; i < resident_count; ++i) {
        if (strcmp(residents[i].id, id_to_delete) == 0) {
            found_index = i;
            break;
        }
    }

    // 如果找到，删除住户信息
    if (found_index != -1) {
        // 将找到索引之后的所有元素向左移动一位
        for (int i = found_index; i < resident_count - 1; ++i) {
            residents[i] = residents[i + 1];
        }
        // 减少住户数量
        --resident_count;
        printf("住户删除成功。\n");
    } else {
        printf("未找到对应的住户信息，删除失败。\n");
    }
}

void ModifyResident() {
    char id_to_modify[20];
    int room_size;
    char personal_phone[20];
    int found_index = -1;

    // 获取要修改的住户的身份证号
    printf("请输入要修改的住户的身份证号: ");
    scanf("%19s", id_to_modify); // 防止缓冲区溢出

    // 搜索住户
    for (int i = 0; i < resident_count; ++i) {
        if (strcmp(residents[i].id, id_to_modify) == 0) {
            found_index = i;
            break;
        }
    }

    // 如果找到，修改住户信息
    if (found_index != -1) {
        printf("请输入新的房屋面积: ");
        scanf("%d", &room_size);
        printf("请输入新的个人手机号: ");
        scanf("%19s", personal_phone); // 防止缓冲区溢出

        // 更新信息
        residents[found_index].room_size = room_size;
        strncpy(residents[found_index].personal_phone, personal_phone, sizeof(residents[found_index].personal_phone) - 1);
        // 确保字符串是以 null 结尾的
        residents[found_index].personal_phone[sizeof(residents[found_index].personal_phone) - 1] = '\0';

        printf("住户信息更新成功。\n");
    } else {
        printf("未找到对应的住户信息，修改失败。\n");
    }
}
void PrintPropertyFee() {
    printf("物业费信息:\n");
    printf("ID\t房屋面积\t物业费\n");
    for (int i = 0; i < resident_count; ++i) {
        printf("%s\t%d\t%.2f\n", residents[i].id, residents[i].room_size, residents[i].property_fee);
    }
}

void PrintParkingFee() {
    printf("停车费信息:\n");
    printf("ID\t车位编号\t停车费\n");
    for (int i = 0; i < resident_count; ++i) {
        // 车位编号可能为空，因此需要判断是否有车位编号
        if (residents[i].parking_spot_number[0] != '\0') {
            printf("%s\t%s\t%.2f\n", residents[i].id, residents[i].parking_spot_number, residents[i].parking_fee);
        }
    }
}



void CalculateTotalFee() {
    printf("用户费用总计:\n");
    printf("ID\t姓名\t房屋面积\t车位编号\t费用总和\n");
    for (int i = 0; i < resident_count; ++i) {
    	residents[i].property_fee=residents[i].room_size*2;
        residents[i].parking_fee=800;
        float total_fee = residents[i].property_fee + residents[i].parking_fee;
        
        // 如果没有车位编号，我们可以选择打印"无"或者空字符串
        const char* parking_spot = residents[i].parking_spot_number[0] != '\0' ? residents[i].parking_spot_number : "无";
        printf("%s\t%s\t%d\t\t%s\t\t%.2f\n", residents[i].id, residents[i].owner_name, residents[i].room_size, parking_spot, total_fee);
    }
}

// 一个辅助函数来交换两个居民信息
void SwapResidents(ResidentInfo *a, ResidentInfo *b) {
    ResidentInfo temp = *a;
    *a = *b;
    *b = temp;
}

void SortResidentsByTotalFee() {
    // 使用冒泡排序算法对居民进行排序
    for (int i = 0; i < resident_count - 1; ++i) {
        for (int j = 0; j < resident_count - i - 1; ++j) {
            float total_fee_j = residents[j].property_fee + residents[j].parking_fee;
            float total_fee_j1 = residents[j + 1].property_fee + residents[j + 1].parking_fee;
            if (total_fee_j > total_fee_j1) {
                // 交换两个居民的位置
                SwapResidents(&residents[j], &residents[j + 1]);
            }
        }
    }

    // 打印排序后的提示信息
    printf("居民信息已根据物业费和停车费总和进行排序。\n");
}


