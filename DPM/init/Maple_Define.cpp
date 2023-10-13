#include <iostream>
#include <string>

#include "Maple_Define.H"
#include "Maple_String.H"

using namespace std;

Character::Character(){ //두번째 사용(세번쨰 생성자 추가 작성)
  define_p_all_stat();
  this -> stat_damage = define_stat_damage();
}

Character::Character(int level){ //첫번쨰 사용
  this -> Level = level;
  this -> STR += (level - 10) * 5;
  define_p_all_stat();
  this -> stat_damage = define_stat_damage();
}

Character::Character(int etc){

}

void Character::define_p_all_stat(){
  this -> STR += all_stat;
  this -> DEX += all_stat;
  this -> p_STR += p_all_stat;
  this -> p_DEX += p_all_stat;
}

double Character::define_p_main_stat(){
  double stat;
  stat = this -> STR;
  stat *= (1 + p_STR);
  return stat;
}

double Character::define_p_sub_stat(){
  double stat;
  stat = this -> DEX;
  stat *= (1 + p_DEX);
  return stat;
}

double Character::define_stat_damage(){
  double stat1, stat2, s_d;
  stat1 = define_p_main_stat();
  stat2 = define_p_sub_stat();
  s_d = (stat1 * 4 + stat2) * 0.01 * att * weapon_constants * job_constants * (1 + patt) * (1 + damage + boss_damage) * ((1.2 + crit_damage) + (1.5 + crit_damage)) / 2 * (1 + proficiency) / 2 * (1 + final_damage);
  return s_d;
}

Character operator +(Character &ch, Item & it){
  ch.STR += it.STR;
  ch.DEX += it.DEX;
  ch.INT += it.INT;
  ch.LUK += it.LUK;
  ch.att += it.att;
  ch.spell_att += it.spell_att;
  ch.Hp += it.Hp;
  ch.crit_damage += it.crit_damage;
  ch.boss_damage += it.boss_damage;
  ch.patt += it.patt;
  ch.psatt += it.psatt;
  ch.p_STR += it.p_STR;
  ch.p_DEX += it.p_DEX;
  ch.p_INT += it.p_INT;
  ch.p_LUK += it.p_LUK;
  ch.p_all_stat += it.p_all_stat;
}

Character operator -(Character &ch, Item & it){
  ch.STR -= it.STR;
  ch.DEX -= it.DEX;
  ch.INT -= it.INT;
  ch.LUK -= it.LUK;
  ch.att -= it.att;
  ch.spell_att -= it.spell_att;
  ch.Hp -= it.Hp;
  ch.crit_damage -= it.crit_damage;
  ch.boss_damage -= it.boss_damage;
  ch.patt -= it.patt;
  ch.psatt -= it.psatt;
  ch.p_STR -= it.p_STR;
  ch.p_DEX -= it.p_DEX;
  ch.p_INT -= it.p_INT;
  ch.p_LUK -= it.p_LUK;
  ch.p_all_stat -= it.p_all_stat;
}