#include "plugin.hpp"

using namespace SKSE;


SKSEPluginLoad(const LoadInterface* skse)
{

    auto* plugin = PluginDeclaration::GetSingleton();
    auto version = plugin->GetVersion();

    Init(skse);

    return true;
}
