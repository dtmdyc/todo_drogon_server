#ifndef _MADMINACTOR_H
#define _MADMINACTOR_H


#include "caf/all.hpp"

#include "useractorbase.h"

class MAdminActor : public caf::event_based_actor, public UserActorBase {
  public:
    MAdminActor(caf::actor_config & cfg);

  protected:
    caf::behavior make_behavior() override;


  private:
    nlohmann::json handleTextMessage(const drogon::WebSocketConnectionPtr & wsConnPtr, const nlohmann::json & in) override;

    nlohmann::json handleBinaryMessage(const drogon::WebSocketConnectionPtr & wsConnPtr, std::string & message) override;

};
#endif
