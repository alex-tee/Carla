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

/**
    This abstract base class is used by some AudioProcessorParameter helper classes.

    @see AudioParameterFloat, AudioParameterInt, AudioParameterBool, AudioParameterChoice

    @tags{Audio}
*/
class JUCE_API  AudioProcessorParameterWithID  : public AudioProcessorParameter
{
public:
    /** The creation of this object requires providing a name and ID which will be
        constant for its lifetime.
    */
    AudioProcessorParameterWithID (const String& parameterID,
                                   const String& parameterName,
                                   const String& parameterLabel = {},
                                   Category parameterCategory = AudioProcessorParameter::genericParameter);

    /** Destructor. */
    ~AudioProcessorParameterWithID() override;

    /** Provides access to the parameter's ID string. */
    const String paramID;

    /** Provides access to the parameter's name. */
    const String name;

    /** Provides access to the parameter's label. */
    const String label;

    /** Provides access to the parameter's category. */
    const Category category;

    String getName (int) const override;
    String getLabel() const override;
    Category getCategory() const override;

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AudioProcessorParameterWithID)
};

} // namespace juce
