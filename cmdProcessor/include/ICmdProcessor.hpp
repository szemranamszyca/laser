#ifndef ICMDPROCESSOR_H
#define ICMDPROCESSOR_H

#include <memory>
#include <functional>
#include <map>
#include <vector>

namespace laser
{
namespace cmdProcessor
{

using Params = std::vector<int>;
using Validator_t = std::function<bool(size_t)>;
using Reaction_t = std::function<bool(Params&)>;
using ActionReactionMap_t = std::map<std::string, Reaction_t>;

class ICmdProcessor
{
public:
	virtual std::string process(const std::string&) = 0;
	virtual void configure(
		std::shared_ptr<ActionReactionMap_t>) = 0;
	virtual ~ICmdProcessor(){};
};

} // namespace laser
} // namespace cmdProcessor

#endif /* ICMDPROCESSOR_H */

