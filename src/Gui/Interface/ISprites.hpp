/*
 * Copyright (C) 2020 Smirnov Vladimir / mapron1@gmail.com
 * SPDX-License-Identifier: MIT
 * See LICENSE file for details.
 */
#pragma once

#include <QList>
#include <QPixmap>

#include <memory>

namespace FreeHeroes::Gui {

class ISprite {
public:
    struct SpriteFrame {
        QPixmap m_frame;
        QPoint  m_paddingLeftTop;
    };

    struct SpriteSequenceParams {
        int    m_scaleFactorPercent     = 100;
        int    m_animationCycleDuration = 1000;
        int    m_specialFrameIndex      = -1;
        QPoint m_actionPoint;
    };

    struct SpriteSequenceMask {
        uint8_t              m_width  = 0;
        uint8_t              m_height = 0;
        std::vector<uint8_t> m_draw1;
        std::vector<uint8_t> m_draw2;
    };

    struct SpriteSequence {
        QList<SpriteFrame>   m_frames;
        QSize                m_boundarySize;
        SpriteSequenceParams m_params;
        SpriteSequenceMask   m_mask;
    };

    using SpriteSequencePtr = std::shared_ptr<const SpriteSequence>;

public:
    virtual ~ISprite()                 = default;
    virtual int getGroupsCount() const = 0;

    virtual QList<int> getGroupsIds() const = 0;

    virtual SpriteSequencePtr getFramesForGroup(int group) const = 0;
};

using SpritePtr = std::shared_ptr<const ISprite>;

}
