#ifndef CONTEXT_H
#define CONTEXT_H
#include "contextbase.h"

#include <string>

#include <drogon/WebSocketController.h>
using namespace drogon;

struct ContextUser {
    long id{0};
    std::string type{""};
};

class MAdminContext : public ContextBase
{
public:
    MAdminContext(const HttpRequestPtr &req, const WebSocketConnectionPtr &wsConnPtr_);
    long current_session_id = 0;
    long user_id = 0;

    std::tuple<long, long> generateContext(const HttpRequestPtr &req);
    void setUser();

    ContextUser user;

};

#endif // CONTEXT_H
