/** @file
    @brief Implementation

    @date 2015

    @author
    Sensics, Inc.
    <http://sensics.com/osvr>
*/

// Copyright 2015 Sensics, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//        http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// Internal Includes
#include <osvr/Client/ClientObjectsAndCallbacks.h>
#include <osvr/Common/PathTreeObserver.h>
#include <osvr/Util/Verbosity.h>

// Library/third-party includes
// - none

// Standard includes
#include <unordered_set>

namespace osvr {
namespace client {
    ClientObjectsAndCallbacks::ClientObjectsAndCallbacks(
        common::PathTreeOwner &tree)
        : m_tree(tree.get()), m_treeObserver(tree.makeObserver()) {
        m_treeObserver->setEventCallback(
            common::PathTreeEvents::AboutToUpdate,
            [&](common::PathTree &) { m_interfaces.clearHandlers(); });
        m_treeObserver->setEventCallback(
            common::PathTreeEvents::AfterUpdate,
            [&](common::PathTree &) { m_connectNeededCallbacks(); });
    }
    bool ClientObjectsAndCallbacks::m_connectCallbacksOnPath(
        std::string const &path) {
        /// @todo
    }

    /// @brief Given a path, remove any existing handler for that path from
    /// both the handler container and the interface tree.
    void ClientObjectsAndCallbacks::m_removeCallbacksOnPath(
        std::string const &path) {
        m_interfaces.eraseHandlerForPath(path);
    }

    void ClientObjectsAndCallbacks::m_connectNeededCallbacks() {
        std::unordered_set<std::string> failedPaths;
        size_t successfulPaths{0};
/// @todo
#if 0
        for (auto const &iface : getInterfaces()) {
            /// @todo slightly overkill, but it works - tree traversal would be
            /// better.
            auto path = iface->getPath();
            /// For every interface, if there's no handler at that path on the
            /// interface tree, try to set one up.
            if (!m_interfaces.getHandlerForPath(path)) {
                auto success = m_connectCallbacksOnPath(path);
                if (success) {
                    successfulPaths++;
                } else {
                    failedPaths.insert(path);
                }
            }
        }
#endif
        OSVR_DEV_VERBOSE("Connected " << successfulPaths << " of "
                                      << successfulPaths + failedPaths.size()
                                      << " unconnected paths successfully");
    }
} // namespace client
} // namespace osvr
