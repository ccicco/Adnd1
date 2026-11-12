    // ---- R966 content structure charter audit ----
    // the charter audit - the frame (nine domains, three worlds, two nesting
    // precedents, the retiring viewport pair), the tile resolutions, and the
    // eleven adjudicated doctrines, every decision fail-on-wrong
    {
        using namespace rules;
        int bad = 0;
    if (cshContentDomains() != 9
            || cshWorldCount() != 3
            || cshNestingPrecedents() != 2
            || cshDungeonTilePx() != 64
            || cshOverlandTilePx() != 32
            || cshDungeonTileValues() != 6
            || cshViewportTilesX() != 25
            || cshViewportTilesY() != 19
            || !cshContentRootAdjudicated()
            || !cshNoCppInContent()
            || !cshRulesMigrateToLua()
            || !cshNpcsSeparateFromMonsters()
            || !cshItemsMundaneMagicTogether()
            || !cshArtifactsOwnSubdomain()
            || !cshModulesNestUnderWorld()
            || !cshExpansionsNestUnderParent()
            || !cshTileSizeManifestField()
            || !cshTileVocabShared()
            || !cshAssetManifestPairing()
        )
            ++bad;
        // the frame - nine domains, three worlds, two nesting precedents
    if (cshContentDomains() != 9
            || cshWorldCount() != 3
            || cshNestingPrecedents() != 2
        )
            ++bad;
        // the resolutions - dungeon 64, overland 32, the six-value dungeon
        // vocabulary
    if (cshDungeonTilePx() != 64
            || cshOverlandTilePx() != 32
            || cshDungeonTileValues() != 6
        )
            ++bad;
        // the retiring viewport pair - 25x19, derived from window over tile
        // size once the manifests own it
    if (cshViewportTilesX() != 25
            || cshViewportTilesY() != 19
        )
            ++bad;
        // the tree - content/ the data root, no C++ inside, assets as payload
        // plus manifest
    if (cshContentRootAdjudicated() != 1
            || cshNoCppInContent() != 1
            || cshAssetManifestPairing() != 1
        )
            ++bad;
        // the record families - npcs separate, mundane and magic together,
        // artifacts own sub-domain
    if (cshNpcsSeparateFromMonsters() != 1
            || cshItemsMundaneMagicTogether() != 1
            || cshArtifactsOwnSubdomain() != 1
        )
            ++bad;
        // the migrations - rules to Lua records, tile size to the manifests,
        // one shared vocabulary
    if (cshRulesMigrateToLua() != 1
            || cshTileSizeManifestField() != 1
            || cshTileVocabShared() != 1
        )
            ++bad;
        // the nesting - modules under their world, expansions under their
        // parent
    if (cshModulesNestUnderWorld() != 1
            || cshExpansionsNestUnderParent() != 1
        )
            ++bad;
        printf("R966 content structure charter audit: bad %d\n", bad);
        if (bad) return 1;
    }
