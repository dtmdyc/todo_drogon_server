#include "MusicWebsock.h"

#include <unistd.h>
#include <chrono>

#include "../actor/caf.h"
#include "spdlogfix.h"

#include "../actor/mainactor.h"
#include "../actor/mainactortype.h"

#include "context/madmincontext.h"
namespace websocket {
void MusicWebsock::handleNewMessage(
    const drogon::WebSocketConnectionPtr& wsConnPtr, std::string&& message,
    const drogon::WebSocketMessageType& type) {
  // std::chrono::seconds(10)
  superactor::globalCAF.communicateWithActors()
      ->request(superactor::globalCAF.mainActor(), caf::infinite,
                run_atom::value, MainActorType::MAdmin, wsConnPtr,
                std::move(message), type)
      .receive(
          [&]() {
            // SPDLOG_TRACE("Output: {}", message.c_str());
          },
          [&](caf::error& err) {
            aout(superactor::globalCAF.communicateWithActors())
                << " -> "
                << superactor::globalCAF.communicateWithActors()
                       ->system()
                       .render(err)
                << err.code() << std::endl;
          });
}
void MusicWebsock::handleNewConnection(
    const drogon::HttpRequestPtr& req,
    const drogon::WebSocketConnectionPtr& wsConnPtr) {
  std::shared_ptr<websocket::MAdminContext> context =
      std::make_shared<MAdminContext>(req, wsConnPtr);
  wsConnPtr->setContext(context);
}
void MusicWebsock::handleConnectionClosed(
    const drogon::WebSocketConnectionPtr& wsConnPtr) {
  superactor::globalCAF.communicateWithActors()->request(
      superactor::globalCAF.mainActor(), caf::infinite, exit_atom::value,
      wsConnPtr);
}
}  // namespace websocket
