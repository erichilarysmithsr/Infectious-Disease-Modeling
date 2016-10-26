#ifndef GUARD_MAP_H
#define GUARD_MAP_H
#include "person.h"
#include "disease.h"

class Person;
class Map
{
public:
	void setEveryoneHealthy();
	Map(int width, int height);
	~Map();
	Person** getGrid();
	void print_map();
	void print_test_map();
	void set_person_state(int i, int j, char state);
	void set_person_infection_time(int i, int j, int time);

	Map take_step(Disease& disease);
	void take_step_s(int i, int j, Disease& disease, Map& nextMap);
	void take_step_i(int i, int j, Map& nextMap);
	void take_step_r(int i, int j, Map& nextMap);


	int number_of_adjacent_inffected(int x, int y, int range);

private:
	Person** population;
	int rows;
	int cols;

};
#endif // GUARD_MAP_H
