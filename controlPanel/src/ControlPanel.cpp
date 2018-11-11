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
	addActionFunc("GetStatus",  
		[this](laser::cmdProcessor::Params& params) -> bool
		{
			params.outParam = emissionStatus_ ? 1 : 0;
			return true;
		}
	);

	addActionFunc("StartEmission",  
		[this](laser::cmdProcessor::Params& params) -> bool
		{
			emissionStatus_ = true;
			return true;
		}	
	);

	addActionFunc("StopEmission",  
		[this](laser::cmdProcessor::Params& params) -> bool
		{
			if (!emissionStatus_)
			{
				return false;
			}
			else
			{
				emissionStatus_ = false;
				return true;
			}	
		}
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


void ControlPanel::addActionFunc(const std::string& action, const Func_t& func)
{
	actionFuncMap_->insert(std::make_pair(action, func));
}

} // namespace controlPanel
} // namespace laser

