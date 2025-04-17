/**
 * @file 58Glory_test2.cpp
 * @author zju1229
 * @brief ��Ϸ���Ľ�ɫ�ඨ�壨��YR�佫ʵ�֣�
 * @version 1.1
 * @date 2025-04-17
 * 
 * @copyright Copyright (c) 2025 58_Glory
 */

#pragma once
#include <memory>
#include <stdexcept>
#include <iostream>

/**
 * @class Position
 * @brief ��ʾ�佫�ڵ�ͼ�ϵ�����λ��
 * @note �������ֱ������ϵ��ԭ��(0,0)λ�ڵ�ͼ���½�
 */
class Position {
public:
    int x; ///< �����꣬��Χ[0, ��ͼ�����)
    int y; ///< �����꣬��Χ[0, ��ͼ���߶�)

    /**
     * @brief ���캯��
     * @param x_ ��ʼ�����꣨Ĭ��0��
     * @param y_ ��ʼ�����꣨Ĭ��0��
     * @throw std::invalid_argument ����ֵΪ����ʱ�׳�
     */
    Position(int x_ = 0, int y_ = 0) : x(x_), y(y_)
	{
        if(x < 0 || y < 0)    throw std::invalid_argument("Position coordinates cannot be negative");
    }
};

/**
 * @class Person
 * @brief ��ɫ�����Ϣ���༶�ͽ�ʦ��ݣ�
 * @note �༶��Ź���5=��࣬6=���࣬0=NPC
 */
class Person {
public:
    int class_id;     ///< �༶��ţ��μ�ע�͹���
    bool is_teacher;  ///< �Ƿ�Ϊ��ʦ���

    /**
     * @brief ���캯��
     * @param cls �༶���
     * @param teacher ��ʦ��ݱ�ʶ
     */
    Person(int cls, bool teacher) : class_id(cls), is_teacher(teacher) {}
};

/**
 * @class Hero
 * @brief ��Ϸ���Ľ�ɫ�࣬��װ�佫���Ժ���Ϊ
 * 
 * @details �������º���Ҫ�أ�
 * - �������ԣ�����ֵ����ֵ����ѧ����
 * - �ռ����ԣ���ͼ����λ��
 * - ������ԣ��༶�����ͽ�ʦ���
 * 
 * @warning ���̰߳�ȫ�࣬���̲߳������ⲿͬ��
 */
class Hero {
private:
    std::unique_ptr<Position> pos;       ///< �佫��ǰλ�ã�����ָ�����
    std::unique_ptr<Person> identity;    ///< �����Ϣ������ָ�����
    int health;                         ///< ����ֵ��HP������Χ[0, 200]
    int extreme_value;                   ///< ��ֵ��������ƫ�ơ������˺�
    int math_ability;                    ///< ��ѧ����������/��/ǿ/��/���嵵
    bool sex;                           ///< �Ա�true=���ԣ�false=Ů��

public:
    /**
     * @brief ���캯��
     * @param hp ��ʼ����ֵ����Χ50-200��
     * @param g ��ʼ��ֵ����Χ0-15��
     * @param math ��ѧ������0=��1=�ޣ�2=ǿ��3=�У�4=����
     * @param sex �Ա��ʶ
     * @param cls �༶��ţ��μ�Person��˵����
     * @param teacher ��ʦ��ݱ�ʶ
     * @throw std::invalid_argument �������������Ч��Χʱ�׳�
     */
    Hero(int hp, int g, int math, bool sex, int cls, bool teacher)
        : health(hp), extreme_value(g), math_ability(math), sex(sex),
          pos(std::make_unique<Position>(0, 0)),
          identity(std::make_unique<Person>(cls, teacher)) 
    {
        if(hp < 50 || hp > 200) {
            throw std::invalid_argument("Invalid health value");
        }
        if(g < 0 || g > 15) {
            throw std::invalid_argument("Extreme value out of range");
        }
    }

    /**
     * @brief �ƶ��佫��ָ��λ��
     * @param new_pos Ŀ��λ�ã��������ô��ݣ�
     * @throw std::invalid_argument Ŀ��λ�÷Ƿ�ʱ�׳�
     * 
     * @code
     * Hero yr(150, 0, 0, false, 5, true);
     * yr.moveTo(Position(3, 4)); // �ƶ�������(3,4)
     * @endcode
     */
    void moveTo(const Position& new_pos) {
        if (new_pos.x < 0 || new_pos.y < 0) {
            throw std::invalid_argument("Position coordinates cannot be negative");
        }
        pos = std::make_unique<Position>(new_pos);
    }

    /**
     * @brief ��ȡ��ǰ���꣨�����÷��ʣ�
     * @return ��ǰ����ĳ�������
     */
    const Position& getPosition() const { return *pos; }

    /**
     * @brief ��ȡ�༶��Ϣ
     * @return �༶��ţ��μ�Person��˵����
     */
    int getClass() const { return identity->class_id; }

    /**
     * @brief �ж��Ƿ�Ϊ��ʦ���
     * @return true��ʾ��ʦ��false��ʾѧ��
     */
    bool isTeacher() const { return identity->is_teacher; }

    /// @name ���Է�����
    /// @{
    int getHealth() const { return health; }          ///< ��ȡ��ǰ����ֵ
    int getExtremeValue() const { return extreme_value; } ///< ��ȡ��ֵ
    int getMathAbility() const { return math_ability; }   ///< ��ȡ��ѧ����
    /// @}
};

/**
 * @brief ʾ����YR��ɫ��ʼ�����ƶ�
 * @return �����˳���
 * 
 * @par ʾ�����̣�
 * 1. ��ʼ��YR��ɫ����ʦ��ݣ�
 * 2. �ƶ�������(1,1)
 * 3. ���������
 */
int main()
{
    try
	{
        // ��ʼ��YR��ɫ��HP=150����ֵ=0����ѧ=����Ů�ԣ�����ʦ��
        Hero yr(150, 0, 0, false, 5, true); 
        yr.moveTo(Position(1, 1));
        std::cout << "New position: (" 
                  << yr.getPosition().x << ", " 
                  << yr.getPosition().y << ")\n";
    }
	catch (const std::exception& e)
	{
        std::cerr << "[ERROR] " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
