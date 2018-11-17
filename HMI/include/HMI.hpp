#ifndef HMI_H
#define HMI_H

#include <memory>
#include "IHMI.hpp"

namespace laser
{
namespace HMI
{



class HMI : public IHMI
{
public:
	HMI();
	virtual ~HMI();

	void plugProcessor(processorFunction) override;
	void interact() const override;

private:
	processorFunction cmd_;
};

} // namespace laser
} // namespace cmdProcessor


#endif /* HMI_H */

