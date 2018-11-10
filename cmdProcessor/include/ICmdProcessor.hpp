#ifndef ICMDPROCESSOR_H
#define ICMDPROCESSOR_H

namespace laser
{
namespace cmdProcessor
{

class ICmdProcessor
{
public:
	virtual std::string process(const std::string&) const = 0;
	virtual ~ICmdProcessor(){};
};

} // namespace laser
} // namespace cmdProcessor

#endif /* ICMDPROCESSOR_H */