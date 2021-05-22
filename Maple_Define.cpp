#include <iostream>
#include <string>

#include "Maple_operator.H"
#include "Maple_Define.H"
#include "Maple_String.H"

using namespace std;

Character::Character(){
  define_p_all_stat();
  this -> stat_damage = define_stat_damage();
}

Character::Character(int level){
  this -> Level = level;
  this -> STR += (level - 10) * 5;
  define_p_all_stat();
  this -> stat_damage = define_stat_damage();
}

void Character::define_p_all_stat(){
  this -> STR += all_stat;
  this -> DEX += all_stat;
  this -> p_main_stat += p_all_stat;
  this -> p_sub_stat += p_all_stat;
}

double Character::define_p_main_stat(){
  this -> STR = 
}

double Character::define_stat_damage(){
  double s_d;
  s_d = (STR * 4 + DEX) * 0.01 * att * weapon_constants * job_constants * (1 + patt) * (1 + damage + boss_damage) * ((1.2 + crit_damage) + (1.5 + crit_damage)) / 2 * (1 + proficiency) / 2 * (1 + final_damage);
  return s_d;
}