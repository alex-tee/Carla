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

ApplicationCommandInfo::ApplicationCommandInfo (const CommandID cid) noexcept
    : commandID (cid), flags (0)
{
}

void ApplicationCommandInfo::setInfo (const String& shortName_,
                                      const String& description_,
                                      const String& categoryName_,
                                      const int flags_) noexcept
{
    shortName = shortName_;
    description = description_;
    categoryName = categoryName_;
    flags = flags_;
}

void ApplicationCommandInfo::setActive (const bool b) noexcept
{
    if (b)
        flags &= ~isDisabled;
    else
        flags |= isDisabled;
}

void ApplicationCommandInfo::setTicked (const bool b) noexcept
{
    if (b)
        flags |= isTicked;
    else
        flags &= ~isTicked;
}

void ApplicationCommandInfo::addDefaultKeypress (const int keyCode, ModifierKeys modifiers) noexcept
{
    defaultKeypresses.add (KeyPress (keyCode, modifiers, 0));
}

} // namespace juce
