#ifndef DARK_TRIAD_SERVICES_DEPLOYMENT_STAGE_HPP
#define DARK_TRIAD_SERVICES_DEPLOYMENT_STAGE_HPP

#include <string>

enum class DeploymentStage {
    LOCAL,
    PROD
};

DeploymentStage getDeploymentStage()
{
    const char* stageStr = std::getenv("DEPLOYMENT_STAGE");

    if (stageStr == nullptr)
        return DeploymentStage::PROD;

    const auto stage = std::string(stageStr);

    if (stage == "local")
        return DeploymentStage::LOCAL;
    else
        return DeploymentStage::PROD;
}

#endif //DARK_TRIAD_SERVICES_DEPLOYMENT_STAGE_HPP
