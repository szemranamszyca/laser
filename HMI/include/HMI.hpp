#ifndef HMI_H
#define HMI_H

#include <memory>
#include "IHMI.hpp"

namespace emulator
{
namespace HMI
{
    
class HMI : public IHMI
{
public:
	HMI();
	virtual ~HMI();

	void plugProcessor(const processorFunction&) override;
	void interact() const override;

private:
	processorFunction cmd_;
};

} // namespace emulator
} // namespace cmdProcessor


#endif /* HMI_H */

