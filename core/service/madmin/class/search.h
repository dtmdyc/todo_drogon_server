#ifndef SEARCH_H
#define SEARCH_H

#include "../../../../wscontroller/context/madmincontext.h"

#include "core/sql/query.h"

namespace madmin {
class Search {
 public:
  Search(std::shared_ptr<websocket::MAdminContext>);
  nlohmann::json handleEvent(nlohmann::json event, unsigned long next,
                             nlohmann::json args);
  void setupTable();

 private:
  std::shared_ptr<websocket::MAdminContext> context;
  sql::Query query;
};
}  // namespace madmin
#endif  // SEARCH_H
