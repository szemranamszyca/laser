#include <iostream>
#include <utility>

#include "../include/ControlPanel.hpp"

namespace laser
{
namespace controlPanel
{

ControlPanel::ControlPanel(
	std::unique_ptr<laser::HMI::IHMI> hmi,
	std::unique_ptr<laser::cmdProcessor::ICmdProcessor> cmdProcessor) :
	laserPower_(0),
	emissionStatus_(false),
	hmi_(move(hmi)),
	cmdProcessor_(move(cmdProcessor))
{
	actionFuncMap_ = std::make_shared<ActionFunctionMap_t>();
	actionFuncMap_->insert
	(
		std::make_pair
		(
			"GetStatus", 
			[this]() -> bool
			{
				return emissionStatus_;
			}
		)

	);

	std::cout << "ControlPanel created!\n";

}

ControlPanel::~ControlPanel()
{}

void ControlPanel::configure() const
{
	std::cout << "CONFIGURING" << '\n';

	hmi_->plugProcessor([=](std::string cmd) -> std::string {
		return cmdProcessor_->process(cmd);
	});
	cmdProcessor_->configure(actionFuncMap_);
}

void ControlPanel::start() const
{
	std::cout << "LASER START!" << '\n';
	hmi_->interact();
}

} // namespace controlPanel
} // namespace laser

