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
		motors.reserve(motor_info.size());
		for(auto const& m_info : motor_info){
			motors += new Motor_Controller(m_info.first);
			if(++i != 0) 		// Skip First term
				motors[i]->Set(ControlMode::Follower, motor_info.begin()->first);
			motors[i]->SetInverted(m_info.second);
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