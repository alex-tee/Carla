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

ToggleButton::ToggleButton()
    : Button (String())
{
    setClickingTogglesState (true);
}

ToggleButton::ToggleButton (const String& buttonText)
    : Button (buttonText)
{
    setClickingTogglesState (true);
}

ToggleButton::~ToggleButton()
{
}

void ToggleButton::paintButton (Graphics& g, bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown)
{
    getLookAndFeel().drawToggleButton (g, *this, shouldDrawButtonAsHighlighted, shouldDrawButtonAsDown);
}

void ToggleButton::changeWidthToFitText()
{
    getLookAndFeel().changeToggleButtonWidthToFitText (*this);
}

void ToggleButton::colourChanged()
{
    repaint();
}

} // namespace juce
