#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int green_prob = 25;
const int red_prob = 50;
const int yellow_prob = 25;
const int car_at_inter_prob = 90; 

int handle_light();
int handle_stop_sign();
int ride_to_school();


int handle_light(){
  //return number of seconds spent at a stop light
  int rand_num = rand() % 100;
  
  if(rand_num < green_prob){ //green light
    return 0; //I don't have to wait at a green light
  }
  else if(rand_num >= green_prob && 
    rand_num < green_prob + yellow_prob){//yellow light
    return 60;
  }
  else{ //red light
    return 55;
  } 
}

int handle_stop_sign(){
  //returns the number of seconds spent at waiting at a stop sign
  
  int rand_num = rand() % 100;
  
  //there is a car at the intersection
  if(rand_num < car_at_inter_prob)
  {
    return 5;
  } 
  else{ //no car 
    return 0;
  }
}

int ride_to_school(){
  //return the number of seconds it takes for me to
  //get to school
  
  //const int num_stop_signs = 4;
  //const int num_stop_lights = 5;
  
  int time_to_school = 15 * 60;
  
  time_to_school += handle_stop_sign();
  //time_to_school = time_to_school + handle_stop_sign();
  time_to_school += handle_stop_sign();
  time_to_school += handle_stop_sign();
  time_to_school += handle_stop_sign();
  
  time_to_school += handle_light();
  time_to_school += handle_light();
  time_to_school += handle_light();
  time_to_school += handle_light();
  time_to_school += handle_light();
  
   
  return time_to_school;
  
}



int main(){

  int time_to_school;
  
  srand(time(NULL));
  time_to_school = ride_to_school();
  
  printf("It took me %d seconds to get to school\n", time_to_school);

  return 0;
}
