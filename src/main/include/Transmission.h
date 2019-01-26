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
		int const leader_num = (motor_info.begin())->first;
		leader.SetInverted((motor_info.begin())->second);

		// Store follower motors in string
		followers.reserve(motor_info.size()-1);
		for(auto m_inf = motor_info.begin()+1; m_inf != motor_info.end(); m_inf++)
			followers +=  (new Motor_Controller(m_inf->first) );

		// Invert followers depending on direction and set to follow mode
		for(int i = 0; i < motor_info.size()-1; i++){
			followers[i]->SetInverted((motor_info.begin()+i)->second);
			followers[i]->Set(ControlMode::Follower, leader_num);
		}
	}

	~Transmission()
	{
		for(auto* motor : motors)
			motor->~MotorController();
	}

	Motor_Controller* operator->(){
		return followers[0];
	}

private:
	//Motor_Controller leader;
	std::basic_string<Motor_Controller*> motors;
};