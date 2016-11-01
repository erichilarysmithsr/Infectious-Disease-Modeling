#pragma once
#include "person.h"
#include "disease.h"
#include "analytics.h"
#include "map.h"

class SIRS {
public:
	SIRS();
	~SIRS();
	Map take_step(Disease& disease, analytics& a, Map& current_map);

private:
	int take_step_s(int i, int j, Disease& disease, Map& nextMap, Map& current_map);
	int take_step_i(int i, int j, Map& nextMap, Map& current_map);
	int take_step_r(int i, int j, Disease& disease, Map& nextMap);

};