
#include "./myactor.h"

#include "../wscontroller/wsfns.h"
#include "./mainactortype.h"

namespace superactor {
namespace myactor {
MyActor::MyActor(caf::actor_config &cfg) : caf::event_based_actor(cfg) {}

caf::behavior MyActor::make_behavior() {
  return {
      [this](const drogon::WebSocketConnectionPtr &wsConnPtr,
             std::string message,
             const drogon::WebSocketMessageType &type) -> caf::result<void> {
        blocking_run(wsConnPtr, std::move(message), type);
        return {};
      },
      [this](superactor::system::exit_atom) -> caf::result<void> {
        quit();
        return {};
      }};
}

nlohmann::json MyActor::handleTextMessage(
    const drogon::WebSocketConnectionPtr &wsConnPtr, const nlohmann::json &in) {
  if (!in.is_array() || !in[0].is_array() || !in[0][0].is_number()) {
    return nlohmann::json::array();
  }

  auto contx = wsConnPtr->getContext<websocket::todo::TodoContext>();
  auto evt = in[0][0].get<int>();
  if (evt == 1) {
    // return handleService<todo::service::UI>(contx, in);
  } else {
    return nlohmann::json::array();
  }
}

nlohmann::json MyActor::handleBinaryMessage(
    const drogon::WebSocketConnectionPtr &wsConnPtr, std::string &message) {
  nlohmann::json event;
  try {
    // auto contx = wsConnPtr->getContext<websocket::music::MAdminContext>();
    // long c = contx->sessionId();
    // auto sqlSession =
    //    "SELECT event FROM music.temp_file_meta where session_id = $1";
    // auto clientPtr = drogon::app().getDbClient("sce");
    // auto r = clientPtr->execSqlSync(sqlSession, c);
    // if (!r.empty()) {
    //  try {
    //    event = nlohmann::json::parse(r[0]["event"].c_str());
    // p.handleBinaryEvent creates new transaction.

    //        if (event[0] == "song") {
    //          music::service::Song p{contx};
    //          auto r = p.handleBinaryEvent(event, 1, message);
    //          if (!r.is_null()) return r;
    //        }
    //  } catch (nlohmann::json::parse_error &e) {
    //    LOG_DEBUG << "message: {}", e.what();
    //    LOG_DEBUG << "exception id: {}", e.id;
    //    LOG_DEBUG << "byte position of error:", e.byte;
    //    nlohmann::json j =
    //        std::string("cant parse json reason: ") + e.what() + event.dump();
    //    websocket::WsFns::sendJson(wsConnPtr, j);
    //  }
    //}
  } catch (const std::exception &e) {
    LOG_DEBUG << e.what();
    nlohmann::json jresult;
    jresult[0] = event;
    jresult[1] = e.what();
    return jresult;
  }
  nlohmann::json ret;
  return ret;
}

}  // namespace myactor
}  // namespace superactor
