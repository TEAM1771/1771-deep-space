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
	Transmission(Transmission const& t) = delete;
	Transmission& operator=(Transmission const& t) = delete;

	Transmission(std::initializer_list<std::pair<int, Direction>> motor_info) : 
			leader( (motor_info.end()-1)->first ) {
		auto leader_info = *(motor_info.end()-1);
		leader.SetInverted(leader_info.second);

		followers.reserve(motor_info.size()-1);
		for(auto m_inf = motor_info.begin(); m_inf != motor_info.end()-1; m_inf++)
			followers.push_back( (new Motor_Controller( m_inf->first) ) );

		for(int i = 0; i < motor_info.size()-1; i++){
			followers[i]->SetInverted((motor_info.begin()+i)->second);
			followers[i]->Set(ControlMode::Follower, leader_info.first);
		}
	}

	~Transmission(){
		for(Motor_Controller* follower : followers)
			follower->~Motor_Controller();
	}

	void Set(ControlMode control_mode, double value){
		leader.Set(control_mode, value);
	}

private:
	Motor_Controller leader;
	std::vector<Motor_Controller*> followers;
};