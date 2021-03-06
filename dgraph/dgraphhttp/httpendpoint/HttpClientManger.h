#ifndef _HTTPCLIENTMANGER_H
#define _HTTPCLIENTMANGER_H

#include <map>
#include <memory>
#include <string>
namespace dgraph {
namespace http {
class DGraphHttpClient;
/*host and port not obaying..*/
class HttpClientManager {
 private:
 public:
  static std::map<std::string, std::shared_ptr<DGraphHttpClient>> conns;
  HttpClientManager();
  static std::shared_ptr<DGraphHttpClient> getClient(const std::string &name);
  static void createClient(const std::string &name, const std::string &host,
                           const std::string &port, const std::string &target);
};
}  // namespace dgraph
}
#endif
