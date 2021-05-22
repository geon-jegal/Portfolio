#include <iostrem>
#include <string>
#include "Maple_String.h"

using namespace std;

#ifndef Maple_Define_h
#define Maple_Define_h

class Character{ //기저클래스
  public:
     int Level, Arcan_force, Authentic;
     double att = 0, spell_att = 0, STR = 5, DEX = 5, INT = 5, LUK = 5, all_stat; //다운캐스팅
     virtual double sub_stat2, p_sub_stat2;
     double patt, psatt, p_main_stat, p_sub_stat, p_all_stat;
     double damage, crit_damage, boss_damage, final_damage, stat_damage;
     double armor_ignor;
     string name, stat;
     
     Character();
     Character(int level);
     
  private:
    double proficiency = 1, weapon_constants = 1, job_constants = 1;
    virtual double define_stat_damage();
    virtual double define_p_main_stat();
    virtual double define_p_sub_stat();
    virtual void define_p_all_stat();
    
    friend virtual Character operator + (Item &it);
    friend virtual Character operator - (Item &it);
    
}; //디폴트 직업은 전사, 데벤져는 전사에서 재정의, 제논은 미정, 법사는 spell_att 사용

class Warrier : public Character{
  private:
     double stat_damage();
};

class Bowmen : public Character{
  private:
     double stat_damage();
};

class Magicians : public Character{
  private:
     double stat_damage();
};

class Thieves : public Character{
  private:
     double stat_damage();
};

class Porates : public Character{
  private:
     double stat_damage();
};

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

#endif