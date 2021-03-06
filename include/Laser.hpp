#ifndef LASER_H
#define LASER_H

#include <memory>
#include "ILaser.hpp"
#include "../controlPanel/include/IControlPanel.hpp"


namespace emulator
{

class Laser : public ILaser
{
	public:
		Laser(std::unique_ptr<controlPanel::IControlPanel>);
		~Laser();
		void on() const override;

	private:
		std::unique_ptr<controlPanel::IControlPanel> controlPanel_;
};

} // namespace emulator


#endif /* LASER_H */

