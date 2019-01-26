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

	Transmission(std::initializer_list<std::pair<int, Direction>> motor_info) : 
			leader( (motor_info.begin())->first ) {
		// Initialize leader motor and create a const variable to store the leader motor's info
		auto const leader_num = (motor_info.begin())->first;
		leader.SetInverted((motor_info.begin())->second);

		// Store follower motors in string

		followers.reserve(motor_info.size()-1);
		for(auto m_inf = motor_info.begin(); m_inf != motor_info.end()-1; m_inf++)
			followers +=  (new Motor_Controller( m_inf->first) );

		// Invert followers depending on direction and set to follow mode
		int i = -2;
		for(auto const& m_info : motor_info){
			if(++i==-1) continue;		// Skip the leader, and incriment i
			followers[i]->SetInverted(m_info.second);
			followers[i]->Set(ControlMode::Follower, leader_num);
		}
	}

	// Manual destruction required due to allocation of pointers
	~Transmission(){
		for(Motor_Controller* follower : followers)
			follower->~Motor_Controller();
	}

	Motor_Controller* operator->(){
		return &leader;
	}

private:
	Motor_Controller leader;
	std::basic_string<Motor_Controller*> followers;
};