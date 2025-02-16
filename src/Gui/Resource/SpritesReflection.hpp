/*
 * Copyright (C) 2023 Smirnov Vladimir / mapron1@gmail.com
 * SPDX-License-Identifier: MIT
 * See LICENSE file for details.
 */
#pragma once

#include "Sprites.hpp"

#include "MernelReflection/EnumTraitsMacro.hpp"
#include "MernelReflection/MetaInfoMacro.hpp"

namespace Mernel::Reflection {
using namespace ::FreeHeroes::Gui;

// clang-format off
template<>
struct MetaInfo::MetaFields<QPoint> {
static inline constexpr const std::tuple s_fields{
    SetGetLambda<QPoint, int>("x", [](QPoint& obj, int val) { obj.setX(val); }, [](const QPoint& obj) { return obj.x(); }),
    SetGetLambda<QPoint, int>("y", [](QPoint& obj, int val) { obj.setY(val); }, [](const QPoint& obj) { return obj.y(); }),
};
};

template<>
struct MetaInfo::MetaFields<QSize> {
static inline constexpr const std::tuple s_fields{
    SetGetLambda<QSize, int>("w", [](QSize& obj, int val) { obj.setWidth(val);  }, [](const QSize& obj) { return obj.width(); }),
    SetGetLambda<QSize, int>("h", [](QSize& obj, int val) { obj.setHeight(val); }, [](const QSize& obj) { return obj.height(); }),
};
};

// clang-format on

STRUCT_REFLECTION_STRINGIFY_OFFSET_2(
    Sprite,
    m_boundarySize,
    m_mask,
    m_groups)

STRUCT_REFLECTION_STRINGIFY_OFFSET_2(
    Sprite::FrameImpl,
    m_padding,
    m_hasBitmap,
    m_bitmapSize,
    m_bitmapOffset,
    m_boundarySize)

STRUCT_REFLECTION_STRINGIFY_OFFSET_2(
    ISprite::SpriteSequenceParams,
    m_scaleFactorPercent,
    m_animationCycleDuration,
    m_specialFrameIndex,
    m_actionPoint)

STRUCT_REFLECTION_STRINGIFY_OFFSET_2(
    ISprite::SpriteSequenceMask,
    m_width,
    m_height,
    m_draw1,
    m_draw2)

STRUCT_REFLECTION_STRINGIFY_OFFSET_2(
    Sprite::Group,
    m_params,
    m_groupId,
    m_frames)

}
