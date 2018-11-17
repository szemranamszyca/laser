#ifndef ILASER_
#define ILASER_H

namespace laser
{

class ILaser
{
public:
	virtual void on() const = 0;
	virtual ~ILaser(){};
};

} // namespace laser

#endif /* ILASER_H */

