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

SliderPropertyComponent::SliderPropertyComponent (const String& name,
                                                  const double rangeMin,
                                                  const double rangeMax,
                                                  const double interval,
                                                  const double skewFactor,
                                                  bool symmetricSkew)
    : PropertyComponent (name)
{
    addAndMakeVisible (slider);

    slider.setRange (rangeMin, rangeMax, interval);
    slider.setSkewFactor (skewFactor, symmetricSkew);
    slider.setSliderStyle (Slider::LinearBar);

    slider.onValueChange = [this]
    {
        if (getValue() != slider.getValue())
            setValue (slider.getValue());
    };
}

SliderPropertyComponent::SliderPropertyComponent (const Value& valueToControl,
                                                  const String& name,
                                                  const double rangeMin,
                                                  const double rangeMax,
                                                  const double interval,
                                                  const double skewFactor,
                                                  bool symmetricSkew)
    : PropertyComponent (name)
{
    addAndMakeVisible (slider);

    slider.setRange (rangeMin, rangeMax, interval);
    slider.setSkewFactor (skewFactor, symmetricSkew);
    slider.setSliderStyle (Slider::LinearBar);

    slider.getValueObject().referTo (valueToControl);
}

SliderPropertyComponent::~SliderPropertyComponent()
{
}

void SliderPropertyComponent::setValue (const double /*newValue*/)
{
}

double SliderPropertyComponent::getValue() const
{
    return slider.getValue();
}

void SliderPropertyComponent::refresh()
{
    slider.setValue (getValue(), dontSendNotification);
}

} // namespace juce
