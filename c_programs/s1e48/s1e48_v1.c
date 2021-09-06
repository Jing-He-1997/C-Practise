/*
 * ========通讯录管理程序==========
 * 1. 插入新的联系人 - addPerson()
 * 2. 查找已有联系人 - findPerson()
 * 3. 更改现有联系人 - changePerson()
 * 4. 删除已有联系人 - delPerson()
 * 5. 显示当前通讯录 - displayContacts()
 * 6. 退出通讯录程序
 * */

// 未完成(8.24.2021)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 128
struct Contact
{
	char name[16];
	unsigned long phoneNum;
	char addr[32];
	struct Contact *next;		
};

void getInput(struct Contact *person);
void displayContracts(struct Contact *contact);
void addPerson(struct Contact **contact);
struct Contact *findPerson(struct Contact *contact, char *target);
void changePerson(struct Contact **contact, char *target);
void delPerson(struct Contact **contact, char *target);

//插入新的联系人 - 输入联系人的详细信息
void getInput(struct Contact *person)
{
	printf("联系人名字:");
	scanf("%s", person->name);
	printf("电话号码:");
	scanf("%lu", &person->phoneNum);
	printf("地址:");
	scanf("%s",person->addr);
}
//显示当前的通讯录
void displayContacts(struct Contact *contact)
{
	int count = 1;
	struct Contact *person = NULL;
	person = contact;

	if(contact == NULL)
	{
		printf("通讯录是空的! 请先输入联系人的信息!\n");
		return;
	}

	do
	{
		printf("===第 %d 个联系人的信息===\n", count);
		printf("姓名:%s\n", person->name);
		printf("电话号码:%lu\n", person->phoneNum);
		printf("地址:%s\n", person->addr);
		putchar('\n');
		count++;
	}while((person = person->next) != NULL);
}
// 插入新的联系人(尾插法)
void addPerson(struct Contact **contact)
{
	struct Contact *person;
	static struct Contact *tail;	//一直定位在单链表的尾部

	person = (struct Contact *)malloc(sizeof(struct Contact));

	if(person == NULL)
	{
		printf("动态内存分配失败!\n");
		exit(1);
	}

	getInput(person);

	if(*contact != NULL)
	{
		tail->next = person;
		person->next = NULL;
	}
	else
	{
		*contact = person;
		person->next = NULL;
	}

	tail = person;	
}

//通过名字查找通讯录中的联系人
struct Contact *findPerson(struct Contact *contact, char *target)
{
	if(contact == NULL)
	{
		printf("通讯录是空的，请先输入联系人的信息!\n");
		return contact;
	}
	struct Contact *person = NULL;
	person = contact;
	
	while(person != NULL)
	{
		if(!strcmp(person->name, target))
		{
			break;
		}
		person = person->next;	
	}

	if(person == NULL)
	{
		printf("通讯录中不存在此人!\n");
	}

	return person;
}

// 更改已有联系人的信息 - changePerson()
void changePerson(struct Contact **contact, char *target)
{
	if(*contact == NULL)
	{
		printf("通讯录是空的，请先输入联系人的信息!\n");
		return ;
	}

	struct Contact *person = NULL;
	person = *contact;
	person = findPerson(person, target);
	
	if(person == NULL)
	{
		printf("未能找到需要修改的联系人!\n");
		return ;
	}
	
	printf("开始修改联系人信息....\n");
	getInput(person);
}

void delPerson(struct Contact **contact, char *target)
{
	// ....
}

int main(void)
{
	struct Contact *contact = NULL;
	struct Contact *person = NULL;
	char target[MAX] = {0};
	int num = 0, count_1 = 1;

	printf("\n进入通讯录程序中...\n");

	while(num != 6)
	{
		printf("\n请输入操作数:");
		scanf("%d", &num);

		switch(num)
		{
			case 1:
			{
				printf("请输入通讯录中第 %d 个联系人的信息...\n",count_1);
				addPerson(&contact);
				count_1++;
				break;
			}
			case 2:
			{
				printf("请输入需要查找的联系人的姓名:");
				scanf("%s", target);
				person = findPerson(contact, target);
				
				if(person != NULL)
				{
					printf("\n找到了!\n");
				}
				break;
			}
			case 3:
			{
				printf("请输入需要查找的联系人的姓名:");
				scanf("%s", target);
				changePerson(&contact, target);
				break;	
			}
			case 4:
			{
				//....
				break;
			}
			case 5:
			{
				displayContacts(contact);
				break;
			}
		}
	}

	return 0;
}
