/*
  ==============================================================================

   This file is part of the JUCE 6 technical preview.
   Copyright (c) 2017 - ROLI Ltd.

   You may use this code under the terms of the GPL v3
   (see www.gnu.org/licenses).

   For this technical preview, this file is not subject to commercial licensing.

   JUCE IS PROVIDED "AS IS" WITHOUT ANY WARRANTY, AND ALL WARRANTIES, WHETHER
   EXPRESSED OR IMPLIED, INCLUDING MERCHANTABILITY AND FITNESS FOR PURPOSE, ARE
   DISCLAIMED.

  ==============================================================================
*/

namespace juce
{

void MouseListener::mouseEnter (const MouseEvent&) {}
void MouseListener::mouseExit (const MouseEvent&)  {}
void MouseListener::mouseDown (const MouseEvent&)  {}
void MouseListener::mouseUp (const MouseEvent&)    {}
void MouseListener::mouseDrag (const MouseEvent&)  {}
void MouseListener::mouseMove (const MouseEvent&)  {}
void MouseListener::mouseDoubleClick (const MouseEvent&) {}
void MouseListener::mouseWheelMove (const MouseEvent&, const MouseWheelDetails&) {}
void MouseListener::mouseMagnify (const MouseEvent&, float) {}

} // namespace juce
