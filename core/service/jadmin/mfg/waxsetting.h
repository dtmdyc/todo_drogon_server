#ifndef WAXSETTING_H
#define WAXSETTING_H
#include "../../../../wscontroller/context/jadmincontext.h"
#include "core/sql/query.h"

namespace jadmin {
class WaxSetting {
 public:
  WaxSetting(std::shared_ptr<websocket::JAdminContext>);
  nlohmann::json handleEvent(nlohmann::json event, unsigned long next,
                             nlohmann::json args);

 private:
  void setupTable();
  nlohmann::json ins(nlohmann::json event, nlohmann::json args);
  nlohmann::json upd(nlohmann::json event, nlohmann::json args);
  std::shared_ptr<websocket::JAdminContext> context;
  sql::Query query;
};
}  // namespace jadmin
#endif  // WAXSETTING_H
