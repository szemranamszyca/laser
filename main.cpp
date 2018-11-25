#include <memory>

#include "include/Laser.hpp"
#include "controlPanel/include/ControlPanel.hpp"
#include "cmdProcessor/include/CmdProcessor.hpp"
#include "HMI/include/HMI.hpp"


int main()
{
	auto controlPanel = 
		std::make_unique<
		emulator::controlPanel::ControlPanel>(
			std::make_unique<emulator::HMI::HMI>(),
			std::make_unique<emulator::cmdProcessor::CmdProcessor>());

	emulator::Laser fancyLaser(move(controlPanel));
	fancyLaser.on();
	return 0;
}