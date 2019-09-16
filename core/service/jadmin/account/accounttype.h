#ifndef ACCOUNTTYPE_H
#define ACCOUNTTYPE_H
#include "../../../../wscontroller/context/jadmincontext.h"
#include "core/sql/query.h"

namespace jewel {
namespace service {
class AccountType {
 public:
  AccountType(std::shared_ptr<websocket::jewel::JAdminContext>);
  nlohmann::json handleEvent(nlohmann::json event, unsigned long next,
                             nlohmann::json args);

 private:
  void setupTable();
  nlohmann::json ins(nlohmann::json event, nlohmann::json args);
  nlohmann::json upd(nlohmann::json event, nlohmann::json args);
  std::shared_ptr<websocket::jewel::JAdminContext> context;
  sql::Query query;
};
}  // namespace service
}  // namespace jadmin
#endif  // ACCOUNTTYPE_H
