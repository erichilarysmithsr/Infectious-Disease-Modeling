/*

This file is a test run file for our disease libraries

*/

//include c++ libraries
#include <iostream>
#include <string>

//include all of the other files in the program
//#include "neighborhood.h"
#include "person.h"
#include "map.h"
#include "disease.h"
#include "text_parse.h" //parse through simulation parameter text file

using namespace std;

int main(){
  int time = 50;
  Map map(100, 30);
  //test disease
  Disease disease("test", 5, 50);
  map.random_seed(disease);
  //map.random_seed(disease);

  
  
  for (int loops = 0; loops < time; loops++) {
	  cout << "Time: " << loops << endl;
	  map.print_map();
	  map = map.take_step(disease);
  }
  return 0;
}
