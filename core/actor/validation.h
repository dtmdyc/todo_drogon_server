#ifndef VALIDATION_H
#define VALIDATION_H

#include "caf/all.hpp"
#include "json.hpp"

class Validation : public caf::event_based_actor {
 public:
  Validation(caf::actor_config &cfg, nlohmann::json in);

 protected:
  caf::behavior make_behavior() override;

 private:
  void blocking_run();

  nlohmann::json in;
  caf::behavior running_job;  // initial behavior
};

#endif  // VALIDATION_H
