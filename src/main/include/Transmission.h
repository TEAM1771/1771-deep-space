#pragma once

#include <vector>
#include <initializer_list>
#include <ctre/Phoenix.h>

enum Direction {
	Forward,
	Reverse
};

template<typename Motor_Controller> 
Motor_Controller& make_transmission(std::initializer_list<std::pair<int,Direction>> motor_info);