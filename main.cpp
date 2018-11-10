#include <memory>

#include "include/Laser.hpp"
#include "controlPanel/include/ControlPanel.hpp"
#include "cmdProcessor/include/CmdProcessor.hpp"
#include "HMI/include/HMI.hpp"


int main()
{
	auto controlPanel = 
		std::make_unique<
		laser::controlPanel::ControlPanel>(
			std::make_unique<laser::HMI::HMI>(),
			std::make_unique<laser::cmdProcessor::CmdProcessor>());

	laser::Laser fancyLaser(move(controlPanel));
	fancyLaser.on();
	return 0;
}