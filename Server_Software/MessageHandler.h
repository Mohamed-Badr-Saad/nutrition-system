#ifndef MESSAGEHANDLER_H
#define MESSAGEHANDLER_H

#include <pistache/http.h>
#include <nlohmann/json.hpp>
#include <unordered_map>
#include <string>
#include "Patient.h"
#include "Disease.h"
#include "DietPlan.h"

class MessageHandler : public Pistache::Http::Handler {
public:
    HTTP_PROTOTYPE(MessageHandler)

    void onRequest(const Pistache::Http::Request& request, Pistache::Http::ResponseWriter response) override;

private:
    void handlePost(const Pistache::Http::Request& request, Pistache::Http::ResponseWriter response);
    void handleOptions(const Pistache::Http::Request& request, Pistache::Http::ResponseWriter response);

    std::unordered_map<std::string, Patient> patients;
};

#endif // MESSAGEHANDLER_H
