/*
 * Copyright (C) 2022 Smirnov Vladimir / mapron1@gmail.com
 * SPDX-License-Identifier: MIT
 * See LICENSE file for details.
 */
#include "FH2H3M.hpp"
#include "H3M2FH.hpp"
#include "FHTemplateProcessor.hpp"

#include "H3MConversion.hpp"

namespace FreeHeroes {

void convertH3M2FH(const H3Map& src, FHMap& dest, const Core::IGameDatabase* database)
{
    H3M2FHConverter converter(database);
    converter.convertMap(src, dest);
}

void convertFH2H3M(const FHMap& src, H3Map& dest, const Core::IGameDatabase* database)
{
    FH2H3MConverter converter(database);
    converter.convertMap(src, dest);
}

void generateFromTemplate(FHMap&                     map,
                          const Core::IGameDatabase* database,
                          Core::IRandomGenerator*    rng,
                          std::ostream&              logOutput,
                          const std::string&         stopAfterStage)
{
    FHTemplateProcessor converter(map, database, rng, logOutput);
    converter.run(stopAfterStage);
}

}
