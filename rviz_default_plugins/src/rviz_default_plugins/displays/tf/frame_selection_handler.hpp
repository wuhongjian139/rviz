/*
 * Copyright (c) 2012, Willow Garage, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Willow Garage, Inc. nor the names of its
 *       contributors may be used to endorse or promote products derived from
 *       this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef RVIZ_DEFAULT_PLUGINS__DISPLAYS__TF__FRAME_SELECTION_HANDLER_HPP_
#define RVIZ_DEFAULT_PLUGINS__DISPLAYS__TF__FRAME_SELECTION_HANDLER_HPP_

#include <string>

#include "rviz_common/selection/selection_handler.hpp"
#include "tf_display.hpp"
#include "frame_info.hpp"

namespace rviz_common
{

namespace properties
{
class Property;
class BoolProperty;
class StringProperty;
class VectorProperty;
class QuaternionProperty;
}  // namespace properties
}  // namespace rviz_common

namespace rviz_default_plugins
{

namespace displays
{

class FrameSelectionHandler : public rviz_common::selection::SelectionHandler
{
public:
  FrameSelectionHandler(
    FrameInfo * frame,
    TFDisplay * display,
    rviz_common::DisplayContext * context);

  ~FrameSelectionHandler() override = default;

  void createProperties(
    const rviz_common::selection::Picked & obj,
    rviz_common::properties::Property * parent_property) override;

  void destroyProperties(
    const rviz_common::selection::Picked & obj,
    rviz_common::properties::Property * parent_property) override;

  bool getEnabled();

  void setEnabled(bool enabled);

  void setParentName(std::string parent_name);

  void setPosition(const Ogre::Vector3 & position);

  void setOrientation(const Ogre::Quaternion & orientation);

private:
  FrameInfo * frame_;
  TFDisplay * display_;
  rviz_common::properties::Property * category_property_;
  rviz_common::properties::BoolProperty * enabled_property_;
  rviz_common::properties::StringProperty * parent_property_;
  rviz_common::properties::VectorProperty * position_property_;
  rviz_common::properties::QuaternionProperty * orientation_property_;
};

}  // namespace displays

}  // namespace rviz_default_plugins

#endif  // RVIZ_DEFAULT_PLUGINS__DISPLAYS__TF__FRAME_SELECTION_HANDLER_HPP_