#pragma once

#include <drogon/WebSocketController.h>
namespace websocket {
class JUserContext {
  struct ContextUser {
    long id{0};
    std::string type{""};
  };

 public:
  JUserContext(const drogon::HttpRequestPtr &req,
               const drogon::WebSocketConnectionPtr &wsConnPtr_);
  std::tuple<long, long> generateContext(const drogon::HttpRequestPtr &req,
                                         const std::string &account_type);
  void setUser();
  long sessionId() { return current_session_id; }
  void setSessionId(long id) { current_session_id = id; }
  void setUserId(long id) { user_id = id; }
  ContextUser &getUser() { return user; }
  long getUserId() { return user_id; }

 private:
  long current_session_id = 0;
  long user_id = 0;
  ContextUser user;
  const drogon::WebSocketConnectionPtr &wsConnPtr;
};
}  // namespace websocket
