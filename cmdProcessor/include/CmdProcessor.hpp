#ifndef CMDPROCESSOR_H
#define CMDPROCESSOR_H

#include <string>
#include "ICmdProcessor.hpp"

namespace laser
{
namespace cmdProcessor
{


class CmdProcessor : public ICmdProcessor
{
public:
	CmdProcessor();
	virtual ~CmdProcessor();

	std::string process(const std::string&) const override;
};

} // namespace laser
} // namespace cmdProcessor


#endif /* CMDPROCESSOR_H */