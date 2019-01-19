#include <Transmission.h>

template<typename Motor_Controller> 
Motor_Controller& make_transmission(std::initializer_list<std::pair<int,Direction>> motor_info)
{
	std::vector<Motor_Controller*> motors;							// Memory leak is intentional
	motors.reserve(motor_info.size());

	for(auto const& m_inf : motor_info)
		motors.push_back(new Motor_Controller{m_inf.first});
		
	for(auto motor_itr = motors.begin(); motor_itr != --motors.end(); motor_itr++)
		(*motor_itr)->Set(ControlMode::Follower, (motor_info.end()-1)->first);
	

	auto m_inf = motor_info.begin();
	for(auto* motor : motors)
		motor->SetInverted(m_inf++->second);

	return **motors.end();
}