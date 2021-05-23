#include <iostream>
#include <string>
#include "Maple_String.H"

using namespace std;

#ifndef Maple_Define_h
#define Maple_Define_h

class Item{
  public:
     Item();
     int STR = 1, DEX = 1, INT = 1, LUK = 1, att = 0, spell_att = 0, Hp = 5;
     double patt = 0, psatt = 0, p_STR = 0, p_DEX = 0, p_INT = 0, p_LUK = 0, p_all_stat = 0;
     double crit_damage = 0, boss_damage = 0, armor_ignor = 0;
     string name, Item_case;
     bool Item_part;
     int Item_set = 0;
};

class Character{ //기저클래스
  public:
    int Level = 0, Arcan_force = 0, Authentic_force = 0, Arcan_stat = 0, Authentic_stat = 0;
    double att = 0, spell_att = 0, STR = 5, DEX = 5, INT = 5, LUK = 5, all_stat, Hp; //다운캐스팅
    double sub_stat2, p_sub_stat2;
    double patt, psatt, p_all_stat, p_STR, p_DEX, p_INT, p_LUK;
    double damage, crit_damage, boss_damage, final_damage, stat_damage;
    double armor_ignor;
    string name, stat;
    
    Character();
    Character(int level);
    Character(int etc);
   
  private:
    double proficiency = 1, weapon_constants = 1, job_constants = 1;
    virtual double define_stat_damage();
    virtual double define_p_main_stat();
    virtual double define_p_sub_stat();
    virtual void define_p_all_stat();
 
}; //디폴트 직업은 전사, 데벤져는 여기서 재정의, 제논은 미정, 법사는 spell_att 사용

class Warrier : public Character{ //삭제
  private:
     double define_stat_damage();;
};

class Bowmen : public Character{
  private:
     double define_stat_damage();
};

class Magicians : public Character{
  private:
     double define_stat_damage();
};

class Thieves : public Character{
  private:
     double define_stat_damage();
};

class Porates : public Character{
  private:
     double define_stat_damage();
};
    
Character operator + (Character &ch, Item &it);
Character operator - (Character &ch, Item &it);
   
#endif