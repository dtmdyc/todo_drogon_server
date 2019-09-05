#ifndef SETTING_H
#define SETTING_H

#include "../../baseserviceabs.h"
#include "../../../../wscontroller/context/jadmincontext.h"
using JAdminContextPtr = std::shared_ptr<JAdminContext>;
namespace jadmin {
class Setting : public BaseServiceAbs
{
public:
    Setting(JAdminContextPtr );

   json handleEvent(json event, int next, const json& args);

private:
    void setupTable() override;
    json save(const json& event, json args);
    json del( json event, json args) override;
    JAdminContextPtr context;
};
}
#endif // SETTING_H
