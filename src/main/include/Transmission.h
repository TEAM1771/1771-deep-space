#pragma once

#include <initializer_list>
#include <string>

enum Direction {
	Forward,
	Reverse
};

template <typename Motor_Controller>
class Transmission {
public:

	Transmission(std::initializer_list<std::pair<int, Direction>> motor_info)
	{
		// Invert followers depending on direction and set to follow mode
		int i = -1;
		followers.reserve(motor_info.size());
		for(auto const& m_info : motor_info){
			followers += new Motor_Controller(m_info.first);
			if(++i != 0) 		// Skip First term
				followers[i]->Set(ControlMode::Follower, motor_info.begin()->first);
			followers[i]->SetInverted(m_info.second);
		}
	}

	Motor_Controller* operator->(){
		return followers[0];
	}

private:
	//Motor_Controller leader;
	std::basic_string<Motor_Controller*> followers;
};