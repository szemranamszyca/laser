#include <iostream>
#include <utility>


//TODO: move to another class
#include <thread>

#include "../include/ControlPanel.hpp"

namespace emulator
{
namespace controlPanel
{

ControlPanel::ControlPanel(
	std::unique_ptr<emulator::HMI::IHMI> hmi,
	std::unique_ptr<emulator::cmdProcessor::ICmdProcessor> cmdProcessor) :
	laserPower_(0),
	emissionStatus_(false),
	deathMenSwitch(10),
	hmi_(move(hmi)),
	cmdProcessor_(move(cmdProcessor))
{
	actionReactionMap_ = std::make_shared<emulator::cmdProcessor::ActionReactionMap_t>();

	addActionReaction("GetStatus",  
		[this](emulator::cmdProcessor::Params& params) -> bool
		{
			if (params.size() > 0)
			{
				//redundant validation... TODO something with that
				return false;
			}
			params.push_back(emissionStatus_ ? 1 : 0);
			return true;
		}
	);

	addActionReaction("StartEmission",  
		[this](emulator::cmdProcessor::Params& params) -> bool
		{
			if (params.size() > 0)
			{
				//redundant validation... TODO something with that
				return false;
			}

			emissionStatus_ = true;
			lastKalSignal_ = std::chrono::system_clock::now();
			timer_ = std::async(std::launch::async, [this](){
				while(1)
				{
					std::this_thread::sleep_for(std::chrono::seconds(1));
					if (std::chrono::system_clock::now() > lastKalSignal_ 
						+ std::chrono::seconds(deathMenSwitch))
					{
						emissionStatus_ = false;
						return;
					}
				}
			});
			return true;
		}	
	);

	addActionReaction("StopEmission",  
		[this](emulator::cmdProcessor::Params& params) -> bool
		{
			if (params.size() > 0)
			{
				//redundant validation... TODO something with that
				return false;
			}

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
		[this](emulator::cmdProcessor::Params& params) -> bool
		{
			if (!emissionStatus_)
			{
				return false;
			}
			else
			{
				laserPower_ = static_cast<uint8_t>(params.front());
				return true;
			}	
		}
	);

	addActionReaction("GetPower",  
		[this](emulator::cmdProcessor::Params& params) -> bool
		{
			if (!emissionStatus_)
			{
				params.push_back(0);
				return true;
			}
			else
			{
				params.push_back(laserPower_);
				return true;
			}	
		}
	);

	addActionReaction("KeepAlive",  
		[this](emulator::cmdProcessor::Params& params) -> bool
		{
			if (params.size() > 0)
			{
				//redundant validation... TODO something with that
				return false;
			}

			if (!emissionStatus_)
			{
				return false;
			}
			else
			{
				lastKalSignal_ = std::chrono::system_clock::now();
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
	const emulator::cmdProcessor::Reaction_t& reaction)
{
	actionReactionMap_->insert(std::make_pair(action, reaction));
}

} // namespace controlPanel
} // namespace emulator

