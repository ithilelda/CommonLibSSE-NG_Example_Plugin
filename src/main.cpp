#include "plugin.hpp"

using namespace SKSE;


SKSEPluginLoad(const LoadInterface* skse)
{

    Init(skse);

    return true;
}
