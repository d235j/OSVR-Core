/** @file
    @brief Header containing simple traits definitions.

    While this file contains all of the main traits generated by macros, it is
   suggested that you include the specific header file for the trait you want to
   use, in case the structure changes and to make the include list more
   semantic.

    @date 2014

    @author
    Sensics, Inc.
    <http://sensics.com/osvr>
*/

// Copyright 2014 Sensics, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef INCLUDED_ReportTraits_h_GUID_CEDB196C_04E8_4085_EDCF_C5A1BD81A827
#define INCLUDED_ReportTraits_h_GUID_CEDB196C_04E8_4085_EDCF_C5A1BD81A827

// Internal Includes
#include <osvr/Util/ClientCallbackTypesC.h>

// Library/third-party includes
// - none

// Standard includes
// - none

namespace osvr {
namespace common {
    namespace traits {
        /// @brief Metafunction taking a ReportType and returning the associated
        /// CallbackType
        /// @headerfile CallbackType.h <osvr/Common/CallbackType.h>
        template <typename T> struct CallbackType {};

        /** @brief Metafunction taking a CallbackType and returning the
        associated ReportType
        @headerfile ReportFromCallback.h <osvr/Common/ReportFromCallback.h>
        */
        template <typename T> struct ReportFromCallback {};

        /// @brief Metafunction taking a ReportType and returning the associated
        /// StateType
        /// @headerfile StateType.h <osvr/Common/StateType.h>
        template <typename T> struct StateType {};

#define OSVR_REPORT_TRAITS(TYPE)                                               \
    template <> struct CallbackType<OSVR_##TYPE##Report> {                     \
        typedef OSVR_##TYPE##Callback type;                                    \
    };                                                                         \
    template <> struct ReportFromCallback<OSVR_##TYPE##Callback> {             \
        typedef OSVR_##TYPE##Report type;                                      \
    };                                                                         \
    template <> struct StateType<OSVR_##TYPE##Report> {                        \
        typedef OSVR_##TYPE##State type;                                       \
    };
        OSVR_REPORT_TRAITS(Analog)
        OSVR_REPORT_TRAITS(Button)
        OSVR_REPORT_TRAITS(Pose)
        OSVR_REPORT_TRAITS(Position)
        OSVR_REPORT_TRAITS(Orientation)
        OSVR_REPORT_TRAITS(Imaging)
        OSVR_REPORT_TRAITS(Location2D)
        OSVR_REPORT_TRAITS(Direction)
        OSVR_REPORT_TRAITS(EyeTracker2D)
        OSVR_REPORT_TRAITS(EyeTracker3D)
        OSVR_REPORT_TRAITS(EyeTrackerBlink)
        OSVR_REPORT_TRAITS(NaviVelocity)
        OSVR_REPORT_TRAITS(NaviPosition)
        OSVR_REPORT_TRAITS(Gesture)
#undef OSVR_REPORT_TRAITS
    } // namespace traits

} // namespace common
} // namespace osvr

#endif // INCLUDED_ReportTraits_h_GUID_CEDB196C_04E8_4085_EDCF_C5A1BD81A827
