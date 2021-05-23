#include <iostream>
#include <string>

#include "Maple_String.H"
#include "Maple_Define.H"

using namespace std;

int main(){
  int job_count, get_job_list;
  if(job_count == 45){
    for(int a = 0; a <= 45; a++){
      #include "&job[a].h"
      #include "&job[a]_deal_cycle.h"
    }
  }
  else if(job_count < 45){
    for(int a = 0; a <= job_count; a++){
      #include "&job[a].h"
      #include "&job[a]_deal_cycle.h"
    }
  }
}