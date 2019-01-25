#pragma once

#include <vector>
#include <initializer_list>
#include <ctre/Phoenix.h>

enum Direction {
	Forward,
	Reverse
};

template <typename Motor_Controller>
class Transmission {
public:
	// Don't allow copy/move constructors
	Transmission(Transmission const& t) = delete;
	Transmission& operator=(Transmission const& t) = delete;

	// Constructor takes an initializer list of int-direction pairs
	Transmission(std::initializer_list<std::pair<int, Direction>> motor_info) : 
			leader( (motor_info.end()-1)->first ) {
		// Initialize leader motor and create a const variable to store the leader motor's info
		auto const leader_info = *(motor_info.end()-1);
		leader.SetInverted(leader_info.second);

		// Store follower motors in vector
		followers.reserve(motor_info.size()-1);
		for(auto m_inf = motor_info.begin(); m_inf != motor_info.end()-1; m_inf++)
			followers +=  (new Motor_Controller( m_inf->first) );

		// Invert followers depending on direction and set to follow mode
		for(int i = 0; i < motor_info.size()-1; i++){
			followers[i]->SetInverted((motor_info.begin()+i)->second);
			followers[i]->Set(ControlMode::Follower, leader_info.first);
		}
	}

	// Desructor
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