/** @file
    @brief Header

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

#ifndef INCLUDED_PathTreeOwner_h_GUID_3B8C4AD4_90FA_4485_1388_CCFABF5EB66F
#define INCLUDED_PathTreeOwner_h_GUID_3B8C4AD4_90FA_4485_1388_CCFABF5EB66F

// Internal Includes
#include <osvr/Common/PathTreeObserverPtr.h>
#include <osvr/Common/PathTree.h>

// Library/third-party includes
#include <boost/noncopyable.hpp>
#include <json/value.h>

// Standard includes
#include <vector>

namespace osvr {
namespace common {
    class PathTreeOwner : private boost::noncopyable {
      public:
        PathTreeOwner();

        PathTreeObserverPtr makeObserver();

      protected:
      private:
        PathTree m_tree;
        std::vector<PathTreeObserverWeakPtr> m_observers;
    };
} // namespace common
} // namespace osvr
#endif // INCLUDED_PathTreeOwner_h_GUID_3B8C4AD4_90FA_4485_1388_CCFABF5EB66F
