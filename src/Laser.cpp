#include <iostream>

#include "../include/Laser.hpp"

namespace emulator
{

Laser::Laser(std::unique_ptr<controlPanel::IControlPanel> controlPanel) :
	controlPanel_(move(controlPanel))
{}

Laser::~Laser()
{}

void Laser::on() const
{
	std::cout << "LASER on" << '\n';
	controlPanel_->configure();
	controlPanel_->start();
}


} // namespace emulator

