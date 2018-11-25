#ifndef ILASER_
#define ILASER_H

namespace emulator
{

class ILaser
{
public:
	virtual void on() const = 0;
	virtual ~ILaser(){};
};

} // namespace emulator

#endif /* ILASER_H */

