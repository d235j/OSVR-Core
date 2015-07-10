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
// 	http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef INCLUDED_EyeTrackerInterfaceC_h_GUID_F6C50F38_5C4F_41AD_B703_DE8A073F77B3
#define INCLUDED_EyeTrackerInterfaceC_h_GUID_F6C50F38_5C4F_41AD_B703_DE8A073F77B3

/* Internal Includes */
#include <osvr/PluginKit/DeviceInterfaceC.h>
#include <osvr/Util/ChannelCountC.h>
#include <osvr/Util/ClientReportTypesC.h>

/* Library/third-party includes */
/* none */

/* Standard includes */
/* none */

OSVR_EXTERN_C_BEGIN

/** @brief Opaque type used in conjunction with a device token to send data on
    eye tracker interface (which internally is carried over several interfaces).
*/
typedef struct OSVR_EyeTrackerDeviceInterfaceObject *
    OSVR_EyeTrackerDeviceInterface;

/** @brief Specify that your device will implement the Eye Tracker interface.

    @param opts The device init options object.
    @param [out] iface An interface object you should retain with the same
    lifetime as the device token in order to send messages conforming to an
    imaging interface.
    @param numSensors The number of eye tracker sensors you will be reporting:
    You can report 1 - 3 sensors.
*/
OSVR_PLUGINKIT_EXPORT
OSVR_ReturnCode osvrDeviceEyeTrackerConfigure(
    OSVR_INOUT_PTR OSVR_DeviceInitOptions opts,
    OSVR_OUT_PTR OSVR_EyeTrackerDeviceInterface *iface,
    OSVR_IN OSVR_ChannelCount numSensors) OSVR_FUNC_NONNULL((1, 2));

/** @brief Report gaze position 2D for a sensor (eye) - each component
    normalized from 0 to 1, lower-left corner of the screen is (0, 0) with the
    screen extending along the positive axes.

    @todo remove dev parameter

    @param dev Device token
    @param iface Eye Tracker interface
    @param gazePosition The 2D eye gaze position
    @param sensor Sensor number
    @param timestamp Timestamp correlating to eye data.
*/
OSVR_PLUGINKIT_EXPORT
OSVR_ReturnCode osvrDeviceEyeTrackerReport2DGaze(
    OSVR_IN_PTR OSVR_EyeTrackerDeviceInterface iface,
    OSVR_IN OSVR_EyeGazePosition2DState gazePosition,
    OSVR_IN OSVR_ChannelCount sensor,
    OSVR_IN_PTR OSVR_TimeValue const *timestamp) OSVR_FUNC_NONNULL((1, 4));

/** @brief Report 3D gaze ray for an eye
    @param dev Device token
    @param iface Eye Tracker interface
    @param gazeDirection The 3D eye gaze direction - unit vector
    @param gazeBasePoint The 3D eye gaze base - origin of the gaze ray
    @param sensor Sensor number
    @param timestamp Timestamp correlating to eye data.
*/
OSVR_PLUGINKIT_EXPORT
OSVR_ReturnCode osvrDeviceEyeTrackerReport3DGaze(
    OSVR_IN_PTR OSVR_EyeTrackerDeviceInterface iface,
    OSVR_IN OSVR_EyeGazeDirectionState gazeDirection,
    OSVR_IN OSVR_EyeGazeBasePoint3DState gazeBasePoint,
    OSVR_IN OSVR_ChannelCount sensor,
    OSVR_IN_PTR OSVR_TimeValue const *timestamp) OSVR_FUNC_NONNULL((1, 5));

/** @brief 3D gaze direction for an eye
    @param dev Device token
    @param iface Eye Tracker interface
    @param gazeDirection The 3D eye gaze direction - unit vector
    @param sensor Sensor number
    @param timestamp Timestamp correlating to eye data.
*/
OSVR_PLUGINKIT_EXPORT
OSVR_ReturnCode osvrDeviceEyeTrackerReport3DGazeDirection(
    OSVR_IN_PTR OSVR_EyeTrackerDeviceInterface iface,
    OSVR_IN OSVR_EyeGazeDirectionState gazeDirection,
    OSVR_IN OSVR_ChannelCount sensor,
    OSVR_IN_PTR OSVR_TimeValue const *timestamp) OSVR_FUNC_NONNULL((1, 4));

/** @brief Report both 2D and 3D gaze for an eye
    @param dev Device token
    @param iface Eye Tracker interface
    @param gazePosition The 2D eye gaze position
    @param gazeDirection The 3D eye gaze direction - unit vector
    @param gazeBasePoint The 3D eye gaze base - origin of the gaze ray
    @param sensor Sensor number
    @param timestamp Timestamp correlating to eye data.
*/
OSVR_PLUGINKIT_EXPORT
OSVR_ReturnCode osvrDeviceEyeTrackerReportGaze(
    OSVR_IN_PTR OSVR_EyeTrackerDeviceInterface iface,
    OSVR_IN OSVR_EyeGazePosition2DState gazePosition,
    OSVR_IN OSVR_EyeGazeDirectionState gazeDirection,
    OSVR_IN OSVR_EyeGazeBasePoint3DState gazeBasePoint,
    OSVR_IN OSVR_ChannelCount sensor,
    OSVR_IN_PTR OSVR_TimeValue const *timestamp) OSVR_FUNC_NONNULL((1, 6));

/** @brief Report the blink state
    @param dev Device token
    @param iface Eye Tracker interface
    @param blink Whether the eye is blinking ("pressed") or not.
    @param sensor Sensor number
    @param timestamp Timestamp correlating to eye data.
*/
OSVR_PLUGINKIT_EXPORT
OSVR_ReturnCode osvrDeviceEyeTrackerReportBlink(
    OSVR_IN_PTR OSVR_EyeTrackerDeviceInterface iface,
    OSVR_IN OSVR_EyeTrackerBlinkState blink, OSVR_IN OSVR_ChannelCount sensor,
    OSVR_IN_PTR OSVR_TimeValue const *timestamp) OSVR_FUNC_NONNULL((1, 4));

OSVR_EXTERN_C_END

#endif // INCLUDED_EyeTrackerInterfaceC_h_GUID_F6C50F38_5C4F_41AD_B703_DE8A073F77B3