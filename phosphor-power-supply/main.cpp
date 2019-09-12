/**
 * Copyright © 2019 IBM Corporation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <CLI/CLI.hpp>
#include <sdbusplus/bus.hpp>
#include <sdeventplus/event.hpp>

int main(int argc, char* argv[])
{
    auto rc = -1;

    CLI::App app{"OpenBMC Power Supply Unit Monitor"};

    std::string configfile;
    app.add_option("-c,--config", configfile, "JSON configuration file path");

    // Read the arguments.
    CLI11_PARSE(app, argc, argv);

    auto bus = sdbusplus::bus::new_default();
    auto event = sdeventplus::Event::get_default();

    // Attach the event object to the bus object so we can
    // handle both sd_events (for the timers) and dbus signals.
    bus.attach_event(event.get(), SD_EVENT_PRIORITY_NORMAL);

    rc = 0;

    return rc;
}