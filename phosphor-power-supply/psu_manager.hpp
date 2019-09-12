#pragma once

#include <nlohmann/json.hpp>
//#include <sdbusplus/bus.hpp>
#include <sdeventplus/event.hpp>
#include <sdeventplus/utility/timer.hpp>

namespace phosphor
{
namespace power
{
namespace manager
{

/**
 * @class psuManager
 *
 * This class will create an object used to manage and monitor a list of power
 * supply devices.
 */
class psuManager
{
    public:
        psuManager() = delete;
        ~psuManager() = default;
        psuManager(const psuManager&) = delete;
        psuManager& operator=(const psuManager&) = delete;
        psuManager(psuManager&&) = default;
        psuManager& operator=(psuManager&&) = default;

        /**
        * Constructor
        *
        * @param[in] j - JSON configuration file
        * @param[in] b - D-Bus bus object
        * @param[in] e - event object
        */
        psuManager(std::string j);
        //psuManager(std::string j, sdbusplus::bus::bus& b,
                   //const sdeventplus::Event& e);

        /**
         * Initializes the manager.
         *
         * Get current BMC state, ...
         */
        void init()
        {
        }

        /**
         * Starts the timer to start monitoring the list of devices.
         */
         int run()
         {
             //return timer.get_event().loop();
             return 0;
         }

    protected:
        /**
        * The timer that runs to periodically check the power supplies.
        */
        //sdeventplus::utility::Timer<sdeventplus::ClockId::Monotonic> timer;

        /**
         * Analyze the status of each of the power supplies.
         */
        void analyze()
        {
        }

    private:
        /**
         * @brief The path to the JSON power supply configuration file.
         */
        std::string jsonFile;

        /**
         * @brief The JSON object to parse the configuration file.
         */
        nlohmann::json psuJson;

        /**
         * The D-Bus object
         */
        //sdbusplus::bus::bus& bus;
};

} // namespace manager
} // namespace power
} // namspace phosphor
