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
	actionReactionMap_ = std::make_shared<laser::cmdProcessor::ActionReactionMap_t>();

	addActionReaction("GetStatus",  
		[this](laser::cmdProcessor::Params& params) -> bool
		{
			params.outParam = emissionStatus_ ? 1 : 0;
			return true;
		}
	);

	addActionReaction("StartEmission",  
		[this](laser::cmdProcessor::Params& params) -> bool
		{
			emissionStatus_ = true;
			return true;
		}	
	);

	addActionReaction("StopEmission",  
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

	addActionReaction("SetPower",  
		[this](laser::cmdProcessor::Params& params) -> bool
		{
			if (!emissionStatus_)
			{
				return false;
			}
			else
			{
				laserPower_ = static_cast<uint8_t>(*params.inParam);
				return true;
			}	
		}
	);

	addActionReaction("GetPower",  
		[this](laser::cmdProcessor::Params& params) -> bool
		{
			if (!emissionStatus_)
			{
				params.outParam = 0;
				return true;
			}
			else
			{
				params.outParam = laserPower_;
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
	cmdProcessor_->configure(actionReactionMap_);
}

void ControlPanel::start() const
{
	std::cout << "LASER START!" << '\n';
	hmi_->interact();
}

void ControlPanel::addActionReaction(const std::string& action, 
	const laser::cmdProcessor::Reaction_t& reaction)
{
	actionReactionMap_->insert(std::make_pair(action, reaction));
}

} // namespace controlPanel
} // namespace laser

