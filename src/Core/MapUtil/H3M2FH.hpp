/*
 * Copyright (C) 2022 Smirnov Vladimir / mapron1@gmail.com
 * SPDX-License-Identifier: MIT
 * See LICENSE file for details.
 */
#pragma once

#include "FHMap.hpp"
#include "H3MMap.hpp"

#include "IGameDatabase.hpp"

namespace FreeHeroes {

class H3M2FHConverter {
public:
    H3M2FHConverter(const Core::IGameDatabase* database);

    void convertMap(const H3Map& src, FHMap& dest) const;

private:
    Core::ResourceAmount             convertResources(const std::vector<uint32_t>& resourceAmount) const;
    Core::HeroPrimaryParams          convertPrim(const std::vector<uint8_t>& arr) const;
    std::vector<Core::UnitWithCount> convertStacks(const std::vector<StackBasicDescriptor>& stacks) const;

    Core::Reward convertRewardHut(const MapSeerHut& hut) const;
    Core::Reward convertReward(const MapReward& reward) const;
    FHQuest      convertQuest(const MapQuest& quest) const;

    void convertTileMap(const H3Map& src, FHMap& dest) const;

    Core::LibraryObjectDef convertDef(const ObjectTemplate& objTempl) const;

private:
    const Core::IGameDatabase* const m_database;

    Core::IGameDatabase::LibraryFactionContainerPtr m_factionsContainer;

    std::vector<Core::LibraryArtifactConstPtr> m_artifactIds;
    std::vector<Core::LibraryBuildingConstPtr> m_buildingIds;
    //std::vector<Core::LibraryDwellingConstPtr>;
    std::vector<Core::LibraryFactionConstPtr> m_factionIds;
    std::vector<Core::LibraryHeroConstPtr>    m_heroIds;
    //std::vector<Core::LibraryHeroSpecConstPtr>;
    //std::vector<Core::LibraryMapBankConstPtr>;
    //std::vector<Core::LibraryMapObstacleConstPtr>;
    //std::vector<Core::LibraryMapVisitableConstPtr>;
    //std::vector<Core::LibraryObjectDefConstPtr>;
    std::map<int, Core::LibraryPlayerConstPtr>       m_playerIds;
    std::vector<Core::LibraryResourceConstPtr>       m_resourceIds;
    std::vector<Core::LibrarySecondarySkillConstPtr> m_secSkillIds;
    std::vector<Core::LibrarySpellConstPtr>          m_spellIds;
    std::vector<Core::LibraryTerrainConstPtr>        m_terrainIds;
    std::vector<Core::LibraryUnitConstPtr>           m_unitIds;
};

}
