/**
 *@file test1.cpp
 *@author zju1229
 *@brief ��YRΪ�������佫 
**/
#include<cstdio>
#include<cstdlib>
typedef struct Person{
	int c;		///<	�����༶ 
	bool is_teacher;	///<	�Ƿ�Ϊ��ʦ 
};
typedef struct Position{
	int x,y;	///<	�佫���� 
};
typedef struct Hero{
	int hp,g,math;		///<	��������ֵ����ѧ 
	bool sex;	///<	�Ա� 
	Position* p;	///<	�佫���� 
	Person* a;		///<	�佫��� 
};
/**
 *@name ray_f
 *@param[in] h1		һ���佫ָ��
 *@brief ��h1�佫ָ�븳��Ray��Ϣ 
**/ 
void ray_f(Hero *h1)
{
	h1->a=(Person *)malloc(sizeof(Person));
	h1->p=(Position *)malloc(sizeof(Position));
	h1->p->x=0;
	h1->p->y=0;
	h1->a->c=5;
	h1->a->is_teacher=true;
}
/**
 *@name move
 *@param[in] target		Ŀ��λ��
 *@param[in] h1		�����佫
 *@brief ���佫���в��� 
**/ 
void move(Position *target,Hero* h1)
{
	free(h1->p);
	h1->p=target;
} 
/**
 *@name kill
 *@param[in] h1		һ���佫ָ��
 *@brief ���ٸ��佫 
**/
void kill(Hero *h1)
{
	free(h1->p);
	free(h1->a);
	free(h1);
} 
//һ���ӿ� 
int main()
{
	Hero *ray=(Hero *)malloc(sizeof(Hero));
	ray_f(ray);
	kill(ray); 
	return 0;
} 
