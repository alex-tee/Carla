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

CaretComponent::CaretComponent (Component* const keyFocusOwner)
    : owner (keyFocusOwner)
{
    setPaintingIsUnclipped (true);
    setInterceptsMouseClicks (false, false);
}

CaretComponent::~CaretComponent()
{
}

void CaretComponent::paint (Graphics& g)
{
    g.setColour (findColour (caretColourId, true));
    g.fillRect (getLocalBounds());
}

void CaretComponent::timerCallback()
{
    setVisible (shouldBeShown() && ! isVisible());
}

void CaretComponent::setCaretPosition (const Rectangle<int>& characterArea)
{
    startTimer (380);
    setVisible (shouldBeShown());
    setBounds (characterArea.withWidth (2));
}

bool CaretComponent::shouldBeShown() const
{
    return owner == nullptr || (owner->hasKeyboardFocus (false)
                                 && ! owner->isCurrentlyBlockedByAnotherModalComponent());
}

} // namespace juce
