/*
 * Copyright (C) 2020 Smirnov Vladimir / mapron1@gmail.com
 * SPDX-License-Identifier: MIT
 * See LICENSE file for details.
 */
#pragma once

#include "IGameDatabase.hpp"

#include "PropertyTree.hpp"

#include "CoreLogicExport.hpp"

#include <memory>

namespace FreeHeroes::Core {
class IResourceLibrary;
class CORELOGIC_EXPORT GameDatabase : public IGameDatabase {
public:
    struct Resource {
        PropertyTree m_jsonData;
        std::string  m_filename;
    };

public:
    GameDatabase(const std::vector<Resource>& resourceFiles);
    GameDatabase(const std::string& dataBaseId, const IResourceLibrary* resourceLibrary);
    ~GameDatabase();

    LibraryUnitContainerPtr           units() const override;
    LibraryHeroContainerPtr           heroes() const override;
    LibraryArtifactContainerPtr       artifacts() const override;
    LibrarySecondarySkillContainerPtr secSkills() const override;
    LibraryFactionContainerPtr        factions() const override;
    LibrarySpellContainerPtr          spells() const override;
    LibraryResourceContainerPtr       resources() const override;
    LibraryTerrainContainerPtr        terrains() const override;
    LibraryMapObjectContainerPtr      mapObjects() const override;
    LibraryHeroSpecContainerPtr       heroSpecs() const override;

    LibraryGameRulesConstPtr gameRules() const override;

private:
    static std::vector<Resource> loadLibrary(const std::string& dataBaseId, const IResourceLibrary* resourceLibrary);
    bool                         load(const std::vector<Resource>& resourceFiles);

private:
    struct Impl;
    std::unique_ptr<Impl> m_impl;
};

}
