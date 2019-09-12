#include "psu_manager.hpp"

#include <fstream>
#include <phosphor-logging/log.hpp>
//#include <sdbusplus/bus.hpp>
//#include <sdbusplus/server.hpp>
//#include <sdeventplus/event.hpp>
//#include <sdeventplus/utility/timer.hpp>

namespace phosphor
{
namespace power
{
namespace manager
{

using namespace phosphor::logging;

/**
 * @class psuManager
 *
 * This class will create an object used to manage and monitor a list of power
 * supply devices.
 */
//psuManager::psuManager(std::string j, sdbusplus::bus::bus& b,
//                       const sdeventplus::Event& e) :
//    jsonFile(j),
//    bus(b)
psuManager::psuManager(std::string j) :
    jsonFile(j)
{
    try
    {
        std::ifstream file{jsonFile};
        psuJson = nlohmann::json::parse(file, nullptr, true);
        ///std::chrono::milliseconds pollInterval{psuJson.at("pollInterval")};
/*
        timer = std::make_unique<sdeventplus::ClockId::Monotonic>
            (e, std::bind(&psuManager::analyze, this),
            psuJson.at("pollInterval"));
            */
        //timer(e, std::bind(&psuManager::analyze, this), pollInterval);
    }
    catch (const std::exception& e)
    {
        log<level::ERR>("Failed to parse JSON configuration file",
                        entry("FILENAME=%s", jsonFile.c_str()));
    }
}

} // namespace manager
} // namespace power
} // namspace phosphor
